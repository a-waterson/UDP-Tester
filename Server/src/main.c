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
#include <ctype.h>
#include "tcp_connection.h"
#include "udp_socket.h"
#define SOCKET int
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define GETSOCKETERRNO() (errno)
int main(void)
{

    struct connection_info *data;
    data = malloc(sizeof(data));
    int bind_socket;
    bind_socket = init_tcp_conn("8080");
    connect_to_clients(bind_socket, 1);
    // start the test
    int udp_socket = init_udp_socket("9090");
    read_from_socket(udp_socket);
    return 0;
}
