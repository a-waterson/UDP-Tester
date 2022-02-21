#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "tcp_connection.h"
#define SOCKET int
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define GETSOCKETERRNO() (errno)
// struct addrinfo
// {
//     int ai_flags;
//     int ai_family;                   AF_INET (ipv4) AF_INET6(ipv6)
//     int ai_socktype;                 SOCK_STREAM (tcp) SOCK_DGRAM (udp)
//     int ai_protocol;                 0: any protocol, IPPROTO_TCP,
//     IPPROTO_UDP socklen_t ai_addrlen;            rest of these fields should
//     be 0 or null on usage. struct sockaddr *ai_addr; char *ai_canonname;
//     struct addrinfo *ai_next;
// };

int main(int argc, char *argv[])
{
    struct addrinfo hints;
    struct addrinfo *peer_address;
    char address_buffer[100];
    char service_buffer[100];
    // struct timeout
    // {
    //     long tv_sec;
    //     long tv_usec;
    // };
    memset(&hints, 0, sizeof(hints));
    // SOCK_STREAM = TCP
    // SOCK_DGRAM = UDP
    hints.ai_socktype = SOCK_STREAM;
    if (argc < 3)
    {
        fprintf(stderr, "usage: tcp_client hostname port\n");
        return 1;
    }
    /* HOSTNAME
     * PORT
     * hints specifies criteria for selecting sock addr structure (protocol,
     *etc) peer_address is the struct we are setting.
     */
    if (getaddrinfo(argv[1], argv[2], &hints, &peer_address))
    {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    printf("Remote address is: ");
    /**
     * inverse of getaddrinfo()
     * protocol independent
     */
    getnameinfo(peer_address->ai_addr, peer_address->ai_addrlen, address_buffer,
                sizeof(address_buffer), service_buffer, sizeof(service_buffer),
                NI_NUMERICHOST);
    printf("%s %s\n", address_buffer, service_buffer);
    printf("Creating socket...\n");
    SOCKET socket_peer;
    /**
     * ip addr type
     * socket type
     * protocol
     */
    socket_peer = socket(peer_address->ai_family, peer_address->ai_socktype,
                         peer_address->ai_protocol);
    if (!ISVALIDSOCKET(socket_peer))
    {
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    /**
     * the socket we are connecting to
     * the relevant peer address
     * the length of the sockaddr struct
     *
     */
    printf("Connecting...\n");
    if (connect(socket_peer, peer_address->ai_addr, peer_address->ai_addrlen))
    {
        fprintf(stderr, "connect() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(peer_address);
    printf("Connected.\n");
    printf("To send data, enter text followed by enter.\n");
    while (1)
    {
        fd_set reads;
        struct timeval timeout;
        // zeroes out the reads socket set
        FD_ZERO(&reads);
        // add our only socket
        FD_SET(socket_peer, &reads);
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;
        // we use select because we can get input from the keyboard to the
        // terminal aswell
        if (select(socket_peer + 1, &reads, 0, 0, &timeout) < 0)
        {
            fprintf(stderr, "select() failed. (%d)\n", GETSOCKETERRNO());
            return 1;
        }
        if (FD_ISSET(socket_peer, &reads))
        {
            char read[4096];
            int bytes_received = recv(socket_peer, read, 4096, 0);
            if (bytes_received < 1)
            {
                printf("Connection closed by peer.\n");
                break;
            }
            printf("Received (%d bytes): %.*s", bytes_received, bytes_received,
                   read);
        }
        char read[4096];
        if (!fgets(read, 4096, stdin)) break;
        printf("Sending: %s", read);
        int bytes_sent = send(socket_peer, read, strlen(read), 0);
        printf("Sent %d bytes.\n", bytes_sent);
    }
    return 0;
}
