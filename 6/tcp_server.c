#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(int argc, char **argv)
{
	struct sockaddr_in echoClntAddr;
	unsigned int cliAddrLen;
	
	// char server_message[256] = "You have reached the server!";

	// create the server socket
   int server_socket;
   server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // TCP
	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002); // byte ordering
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to specified IP and port
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	
	// listen(server_socket, 5);
	
	// int client_socket;
	// client_socket = accept(server_socket, NULL, NULL);
	
	while(1)
	{
		char server_response[256];
		recvfrom(server_socket, &server_response, sizeof(server_response), 0, (struct sockaddr *) &echoClntAddr, &cliAddrLen);
		sendto(server_socket, server_response, sizeof(server_response), 0, (struct sockaddr *) &echoClntAddr, cliAddrLen);
	}
	
	
	// close the socket
	close(server_socket);
	
	return 0;
}
