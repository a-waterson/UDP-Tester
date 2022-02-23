#ifndef UDP_TESTER_CONNECTION
#define UDP_TESTER_CONNECTION
#include <arpa/inet.h>
#include <ctype.h>
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

#define ISVALIDSOCKET(s) ((s) >= 0)
#define SOCKET int
#define INVALID_SOCKET 2
#define GETSOCKETERRNO() (errno)
#define CLOSESOCKET(s) close(s)
/**
 * @brief creates the tcp connection used to send our initial parameters
 *
 * @return int
 */
struct connection_info
{
    SOCKET bind_socket;
};
int init_tcp_conn(char *port);
int connect_to_clients(SOCKET socket_listen, int max_sockets, char *argv[]);
#endif
