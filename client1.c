#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {

	printf("client1 started\n");

//connect to client 2
//connect to server socket 2 on port 9999
    int client_socket_1;
    client_socket_1 = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET; //connection type
    server_address.sin_port = htons(9999); //port
    server_address.sin_addr.s_addr = INADDR_ANY; //0.0.0.0


    int connect_status = connect(client_socket_1, (struct sockaddr *) &server_address, sizeof(server_address));
    if(connect_status == -1){
        printf("connection error on client1 code: %d \n", connect_status);
    }

    char server_response[256];
    recv(client_socket_1, &server_response, sizeof(server_response), 0);
    printf("Received on client 1 Server response: %s \n", server_response);

    close(client_socket_1);
//host for client 6
//host server_socket_2 port on 9994
    int server_socket_2;
    server_socket_2 = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address_2;
    server_address_2.sin_family = AF_INET;
    server_address_2.sin_port = htons(9994);
    server_address_2.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket_2, (struct sockaddr*) &server_address_2, sizeof(server_address_2));
    listen(server_socket_2, 5);

    int client_socket;
    client_socket = accept(server_socket_2, NULL, NULL); 

    char server1_message[256] = "Hello message from cleint 1";
    send(client_socket, server1_message, sizeof(server1_message),0);
    return 0;
}