#pragma once
/**
 * @brief Create a udp socket object
 * initializes the UDP socket with the values from the TCP connection
 *
 */
void create_udp_socket();
/**
 * @brief
 *
 * @param packets packets specified by params
 * send a packets number of packets to the server
 * timestamp packet no
 */
void send_test_packets(int packets);
/**
 * @brief
 * closes the UDP connection with the server
 */
void close_udp();