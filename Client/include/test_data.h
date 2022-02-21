#pragma once
/**
 *
 * @brief
 * reads the test parameters from the tcp socket.
 */
void read_test_values();

/**
 * @brief
 * writes a final message to the TCP socket signalling that the test is
 * complete.
 */
void send_test_complete();
