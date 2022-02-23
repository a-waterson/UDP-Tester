#include <time.h>

#include "tcp_connection.h"
#include "test_data.h"
#include "udp_socket.h"

int main(int argc, char *argv[])
{
    struct addrinfo peer_address_udp;
    struct addrinfo *peer_address;
    test_values vals;
    struct connection_info *data;
    time_t seconds;
    time_t end_wait;

    SOCKET udp_socket;
    if (argc != 3)
    {
        printf("usage: hostname port\n");
        return 1;
    }
    char read[4096] = {0};
    data = malloc(sizeof(data));

    init_tcp_conn(&peer_address, data, argv[1], argv[2]);
    read_from_socket(data, read);

    read_test_values(&vals, read);

    seconds = vals.start_time;
    end_wait = time(NULL) + seconds;
    while (time(NULL) < end_wait)
        ;

    udp_socket = create_udp_socket(&peer_address_udp, vals.num_packets,
                                   (long)vals.delay);

    return 0;
}
