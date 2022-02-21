#ifndef UDP_TESTER_CONNECTION
#define UDP_TESTER_CONNECTION
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
/**
 * @brief
 * initlializes a TCP socket
 *
 */
#define ISVALIDSOCKET(s) ((s) >= 0)
#define SOCKET int
#define INVALID_SOCKET 2
#define GETSOCKETERRNO() (errno)
struct connection_info
{
    SOCKET socket;
    char *port;
    char *hostname;
};
int init_tcp_conn(struct addrinfo *hints, struct addrinfo *peer_addr,
                  struct connection_info *data);
/**
 * @brief
 * connects to the TCP server
 */
int connect_to_server(struct addrinfo *peer_addr, struct connection_info *data);
/**
 * @brief
 * reads the data from our socket
 * @param data
 * @return int
 */
int read_from_socket(struct connection_info *data, char *read);
#endif