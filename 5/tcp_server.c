#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(int argc, char **argv)
{
	if(argc!=5){
		printf("Usage Format: ./client -a <IPAddress> -p <PortNumber>\n");
		printf("Sample Run: ./client -a 127.0.0.1 -p 2000\n");
		exit(1);
	}

	// char server_message[256] = "You have reached the server!";

	// create the server socket
   int server_socket;
   server_socket = socket(AF_INET, SOCK_STREAM, 0); // TCP
	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(atoi(argv[4]);); // byte ordering
	server_address.sin_addr.s_addr = (char *)argv[2];

	// bind the socket to specified IP and port
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	
	listen(server_socket, 5);
	
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	while(1)
	{
		char server_response[256];
		recv(client_socket, &server_response, sizeof(server_response), 0);
		send(client_socket, server_response, sizeof(server_response), 0);
	}
	
	
	// close the socket
	close(server_socket);
	
	return 0;
}
