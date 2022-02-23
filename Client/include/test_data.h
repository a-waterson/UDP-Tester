#ifndef TEST_DATA_H
#define TEST_DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int num_packets;
    int delay;
    int start_time;
} test_values;

/**
 *
 * @brief
 * reads the test parameters from the tcp socket.
 */
void read_test_values(test_values* data, char* message);

/**
 * @brief
 * writes a final message to the TCP socket signalling that the test is
 * complete.
 */
void send_test_complete();
#endif  // !TEST_DATA_H