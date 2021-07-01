# Socket-Programming
Client Server Communication System using Socket Programming in C++

Socket programming is a way of connecting two nodes on a network to communicate with each other. 
One socket(node) listens on a particular port at an IP, while other socket reaches out to the other to form a connection.
Server forms the listener socket while client reaches out to the server.
We believe that our product VIDVAN can meet the market’s requirements in the best possible way without taking a single penny from the consumers.<br/>

1.Transmission Control Protocol (TCP): Establishes a two-way connection between a server and a single client.
It provides reliable byte stream transmission of data with error checking and correction, and message acknowledgement.<br/>
2.User Datagram Protocol (UDP): Provides two-way message transfer between a server and a large number of clients.


### Guide to run the code

```
git clone https://github.com/saurabhhere/VidVan.git<br/>
cd Socket-Programming
```

**FOR TCP**
```
cd TCP
```

**FOR UDP**
```
cd UDP
```

**Compile and run server.cpp and client.cpp using**

```
g++ -o server server.cpp<br/>
./server 2000
```

```
g++ -o client client.cpp<br/>
./client localhost 2000
```
Now you can send messgae from client to server
