#ifndef UDP_TESTER_CONNECTION_UDP
#define UDP_TESTER_CONNECTION_UDP
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#define ISVALIDSOCKET(s) ((s) >= 0)
#define SOCKET int
#define INVALID_SOCKET 2
#define GETSOCKETERRNO() (errno)
/**
 * @brief Create a udp socket object
 * initializes the UDP socket with the values from the TCP connection
 *
 */
int create_udp_socket(struct addrinfo *peer_address, size_t packets,
                      long delay);
/**
 * @brief
 *
 * @param packets packets specified by params
 * send a packets number of packets to the server
 * timestamp packet no
 */
int send_test_packets(SOCKET socket, struct addrinfo *peer_address,
                      size_t packets, long delay);
/**
 * @brief
 * closes the UDP connection with the server
 */
void close_udp();
int mssleep(long miliseconds);
#endif