#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <stdio.h>
#include <string.h>     // for strlen()
#include <stdlib.h>     // for exit()
#include <sys/socket.h> // for send() and recv()
#include <unistd.h>     // for sleep(), close()
#include <sstream>      // std::stringstream, std::stringbuf
#include <memory.h>     // for memset()
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */

#define RCVBUFSIZE 32   /* Size of receive buffer */
#define SERVERIP "127.0.0.1"

class Network
{
public:
	Network();
	~Network();
	int Connect(unsigned short port);
	std::string Send(std::string message);
	int Close();

private:
	int sock;
};



#endif 