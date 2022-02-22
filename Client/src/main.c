#include "tcp_connection.h"
#include "udp_socket.h"
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
    struct addrinfo peer_address;
    struct addrinfo peer_address_udp;
    struct connection_info *data;
    char read[4096];
    data = malloc(sizeof(data));
    // strcpy(data->hostname, argv[1]);
    // strcpy(data->port, argv[2]);
    printf("hostname: %s port: %s\n", data->hostname, data->port);
    init_tcp_conn(&hints, &peer_address, data, "127.0.0.1", "8080");
    read_from_socket(data, read);
    // while (time!=start_time)
    create_udp_socket(peer_address_udp);
}
