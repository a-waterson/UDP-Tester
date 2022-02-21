

#include "tcp_connection.h"

int init_tcp_conn(struct addrinfo *hints, struct addrinfo *peer_addr,
                  struct connection_info *data)
{
    memset(hints, 0, sizeof(&hints));
    hints->ai_socktype = SOCK_STREAM;

    if (getaddrinfo(data->hostname, data->port, hints, &peer_addr))
    {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    data->socket = socket(peer_addr->ai_family, peer_addr->ai_socktype,
                          peer_addr->ai_protocol);
    if (!ISVALIDSOCKET(data->socket))
    {
        return INVALID_SOCKET;
    }
    return 0;
}
int connect_to_server(struct addrinfo *peer_addr, struct connection_info *data)
{
    if (connect(data->socket, peer_addr->ai_addr, peer_addr->ai_addrlen))
    {
        fprintf(stderr, "connect() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(peer_addr);
    return 0;
}
int read_from_socket(struct connection_info *data, char *read)
{
    int bytes_received;
    int bytes_total;
    while ((bytes_received = recv(data->socket, &read[bytes_total],
                                  sizeof read - bytes_total, 0)) > 0)
    {
        bytes_total += bytes_received;
    }
    return bytes_received;
}
