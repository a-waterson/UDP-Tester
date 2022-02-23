

#include "tcp_connection.h"

int init_tcp_conn(struct addrinfo *peer_addr, struct connection_info *data,
                  const char *hostname, const char *port)
{
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &peer_addr))
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
    if (connect(data->socket, peer_addr->ai_addr, peer_addr->ai_addrlen))
    {
        fprintf(stderr, "connect() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    freeaddrinfo(peer_addr);
    return 0;
}
int connect_to_server(struct addrinfo *peer_addr, struct connection_info *data)
{
    return 0;
}
int read_from_socket(struct connection_info *data, char *read)
{
    char bread[50];
    recv(data->socket, read, 50, 0);
}
