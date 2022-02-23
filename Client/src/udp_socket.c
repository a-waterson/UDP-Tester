#include "udp_socket.h"
int create_udp_socket(struct addrinfo *peer_address, size_t packets, long delay)
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_DGRAM;

    if (getaddrinfo("127.0.0.1", "9090", &hints, &peer_address))
    {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    char address_buffer[16];
    char service_buffer[16];
    getnameinfo(peer_address->ai_addr, peer_address->ai_addrlen, address_buffer,
                sizeof(address_buffer), service_buffer, sizeof(service_buffer),
                NI_NUMERICHOST | NI_NUMERICSERV);
    printf("%s %s\n", address_buffer, service_buffer);
    printf("Creating socket...\n");
    SOCKET socket_peer;
    socket_peer = socket(peer_address->ai_family, peer_address->ai_socktype,
                         peer_address->ai_protocol);
    if (!ISVALIDSOCKET(socket_peer))
    {
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    for (size_t i = 0; i < packets; i++)
    {
        char output[64] = {0};
        sprintf(output, "%s,%s,%zu\n", address_buffer, service_buffer, i);

        printf("Sending: %s\n", output);
        int bytes_sent =
            sendto(socket_peer, output, strlen(output), 0,
                   peer_address->ai_addr, peer_address->ai_addrlen);
        memset(output, 0, sizeof(output));
        mssleep(delay);
    }
}

int mssleep(long miliseconds)
{
    struct timespec rem;
    struct timespec req = {(int)(miliseconds / 1000),
                           (miliseconds % 1000) * 1000000};

    return nanosleep(&req, &rem);
}