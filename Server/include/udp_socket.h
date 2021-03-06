#ifndef UDP_TESTER_UDP
#define UDP_TESTER_UDP
#include <arpa/inet.h>
#include <ctype.h>
#include <dc_posix/dc_fcntl.h>
#include <errno.h>
#include <fcntl.h>
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
int init_udp_socket(char *port);
int read_from_socket(int socket, int packets);
#endif  // !UDP_TESTER_UDP