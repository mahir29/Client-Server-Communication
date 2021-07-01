#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        cerr << "Missing hostname and port number\n";
        exit(0);
    }
    char *serverName = argv[1];
    int port = atoi(argv[2]);
    char message[1500]; // buffer to store sent and recieved messages

    struct hostent *host = gethostbyname(serverName);
    sockaddr_in clientSocket;
    clientSocket.sin_family = AF_INET;
    clientSocket.sin_port = htons(port);
    clientSocket.sin_addr = **(struct in_addr **)host->h_addr_list;

    int clientSocketID = socket(AF_INET, SOCK_DGRAM, 0);  // socket() call to get file descriptor

    if (clientSocketID < 0)
    {
        cout << "Not Successful socket()\n";
        exit(0);
    }

    // connect() to the remote address (the server)
    int status = connect(clientSocketID, (struct sockaddr *)&clientSocket, sizeof(clientSocket)); 

    if (status < 0)
    {
        cout << "Error connecting\n";
        exit(0);
    }

    socklen_t len;

    cout << "Connection Successful\n";

    // start communication (sending and receiving messages)
    while (true)
    {
        string data;
        cout << "Client: ";
        // cin>>data;
        getline(cin, data);
        strcpy(message, data.c_str());

        sendto(clientSocketID, (char *)&message, sizeof(message), 0, (struct sockaddr*)&clientSocket, sizeof(clientSocket));

        if (data=="exit")
        {
            cout<<"Connection Ended"<<"\n";
            break;
        }

        cout << "Server: ";

        recvfrom(clientSocketID, (char *)&message, sizeof(message), 0, (struct sockaddr*)&clientSocket, &len);

        if (!strcmp(message, "exit"))
        {
            cout<<"Conection ended"<<"\n";
            break;
        }
        cout<<message<<"\n";
    }

    close(clientSocketID);

    return 0;
}