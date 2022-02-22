#include "udp_socket.h"
int create_udp_socket(struct addrinfo *peer_address)
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_DGRAM;

    if (getaddrinfo("127.0.0.1", "8080", &hints, &peer_address))
    {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    char address_buffer[100];
    char service_buffer[100];
    getnameinfo(peer_address->ai_addr, peer_address->ai_addrlen,
                address_buffer, sizeof(address_buffer),
                service_buffer, sizeof(service_buffer),
                NI_NUMERICHOST | NI_NUMERICSERV);
    printf("%s %s\n", address_buffer, service_buffer);
    printf("Creating socket...\n");
    SOCKET socket_peer;
    socket_peer = socket(peer_address->ai_family,
                         peer_address->ai_socktype, peer_address->ai_protocol);
    if (!ISVALIDSOCKET(socket_peer))
    {
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
}
int send_test_packets(SOCKET socket, struct addrinfo *peer_address, size_t packets)
{

    for (size_t i = 0; i < packets; i++)
    {
        char *message = sprintf("%d", i);
        printf("Sending: %s\n", message);
        int bytes_sent = sendto(socket,
                                message, strlen(message),
                                0,
                                peer_address->ai_addr, peer_address->ai_addrlen);
        printf("Sent %d bytes.\n", bytes_sent);
    }
}