#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(int argc, char **argv)
{

	// char server_message[256] = "You have reached the server!";

	// create the server socket
   int server_socket;
   server_socket = socket(AF_INET, SOCK_STREAM, 0); // TCP
	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002); // byte ordering
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to specified IP and port
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	
	listen(server_socket, 5);
	
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	while(1)
	{
		char server_response[256];
		recv(client_socket, &server_response, sizeof(server_response), 0);
		
		char op;
		int a, b, ans;
		char result[256];
		
		for(int i = 0; i < strlen(server_response) + 1; i++)
		{
			if(server_response[i] == '+')
			{
				op = '+';
				a = atoi(strtok(server_response, "+"));
				b = atoi(strtok(NULL, "+"));
				ans = a+b;
				snprintf(result, sizeof(result), "%d", ans);
				break;
			}
			if(server_response[i] == '*')
			{
				op = '*';
				a = atoi(strtok(server_response, "*"));
				b = atoi(strtok(NULL, "*"));
				ans = a*b;
				snprintf(result, sizeof(result), "%d", ans);
				break;
			}
		}
		
		
		
		send(client_socket, result, sizeof(result), 0);
	}
	
	
	// close the socket
	close(server_socket);
	
	return 0;
}
