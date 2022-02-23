#include "tcp_connection.h"
#include "udp_socket.h"
int main(int argc, char *argv[])
{
    struct connection_info *data;
    data = malloc(sizeof(data));
    int bind_socket;
    bind_socket = init_tcp_conn("8080");
    connect_to_clients(bind_socket, 1, argv);

    printf("setting up UDP\n");
    int udp_socket = init_udp_socket("9090");
    int num_packs = atoi(argv[2]);
    read_from_socket(udp_socket, num_packs);
    return 0;
}
