#include "udp_socket.h"

#include <time.h>
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
    socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype,
                           bind_address->ai_protocol);
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

int read_from_socket(int socket_listen, int packets)
{
    time_t seconds;
    time_t end_wait;

    seconds = 15;
    end_wait = time(NULL) + seconds;
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    char read[4096] = {0};
    int bytes_received;
    FILE *log;
    log = fopen("../../../log.csv", "w+");

    char headers[40];
    sprintf(headers, "Host,Port,id,%d\n", packets);
    fwrite(headers, sizeof(char), strlen(headers), log);
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    setsockopt(socket_listen, SOL_SOCKET, SO_RCVTIMEO, (struct timeval *)&tv,
               sizeof(struct timeval));
    while (bytes_received =
               recvfrom(socket_listen, read, 4096, 0,
                        (struct sockaddr *)&client_address, &client_len) > 0)
    {
        if (bytes_received < 0)
        {
            break;
        }
        fwrite(read, sizeof(char), strlen(read), log);
        printf("%s", read);
        memset(read, 0, sizeof(read));
    };
    fclose(log);
}