#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(){

    printf("client6 started\n");

//host for client 5
//host server_socket_2 port on 9995
    int server_socket_2;
    server_socket_2 = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address_2;
    server_address_2.sin_family = AF_INET;
    server_address_2.sin_port = htons(9995);
    server_address_2.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket_2, (struct sockaddr*) &server_address_2, sizeof(server_address_2));
    listen(server_socket_2, 5);

    int client_socket;
    client_socket = accept(server_socket_2, NULL, NULL); 

    char server1_message[256] = "Hello message from cleint 6";
    send(client_socket, server1_message, sizeof(server1_message),0);

//connect to client 1
//connect to server_socket_2 on port 9994
    int client_socket_00;
    client_socket_00 = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address_3;
    server_address_3.sin_family = AF_INET; //connection type
    server_address_3.sin_port = htons(9994); //port
    server_address_3.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY is same as 0.0.0.0

    int connect_status = connect(client_socket_00, (struct sockaddr *) &server_address_3, sizeof(server_address_3));
    if(connect_status == -1){
        printf("connection error code on client 6: %d \n", connect_status);
    }

    char server_response2[256];
    recv(client_socket_00, &server_response2, sizeof(server_response2), 0);
    printf("Received on client 6 Server response: %s \n", server_response2);

    close(client_socket_00);
    return 0;
}
