#include "network.h"

Network::Network()
{
    sock = 0;
}

Network::~Network()
{
}

std::string Network::Send(std::string message)
{

    char        echoBuffer[RCVBUFSIZE]; /* Buffer for received string */
    int         recvMsgSize;            /* Size of received message */

    send(sock, message.c_str(), strlen(message.c_str()), 0);
    sleep(1);

    recvMsgSize = recv (sock, echoBuffer, RCVBUFSIZE-1, 0);
    if (recvMsgSize < 0)
    {
        //DieWithError ("recv() failed");
    }
    echoBuffer[recvMsgSize] = '\0';
    std::stringstream ss;
    ss.str (echoBuffer);
    std::string s = ss.str();
    return (s);   
}

int Network::Close()
{
    close (sock);
    return 1;
}

int Network::Connect (unsigned short port)
{
    struct sockaddr_in  echoServAddr; /* Echo server address */

    /* Create a reliable, stream socket using TCP */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        //DieWithError("socket() failed");
    }
    sleep(1);

    /* Construct the server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));     /* Zero out structure */
    echoServAddr.sin_family      = AF_INET;             /* Internet address family */
    echoServAddr.sin_addr.s_addr = inet_addr(SERVERIP);   /* Server IP address */
    echoServAddr.sin_port        = htons(port);         /* Server port */

    /* Establish the connection to the echo server */
    if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
    {
        //DieWithError("connect() failed");
    }
    
    return (sock);
}