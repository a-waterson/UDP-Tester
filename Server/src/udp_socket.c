#include "udp_socket.h"

int init_udp_socket(char *port)
{
    printf("Configuring local address...\n");
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;
    struct addrinfo *bind_address;
    getaddrinfo(0, port, &hints, &bind_address);
    SOCKET socket_listen;
    socket_listen = socket(bind_address->ai_family,
                           bind_address->ai_socktype, bind_address->ai_protocol);
    if (!ISVALIDSOCKET(socket_listen))
    {
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    if (bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen))
    {
        fprintf(stderr, "bind() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(bind_address);
    return socket_listen;
}

int read_from_socket(int socket_listen)
{
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    char read[4096];
    int bytes_received = recvfrom(socket_listen,
                                  read, 1024,
                                  0,
                                  (struct sockaddr *)&client_address, &client_len);
}