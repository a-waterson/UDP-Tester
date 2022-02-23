#include "test_data.h"
void read_test_values(test_values *data, char *message)
{
    char *values[3];

    values[0] = strtok(message, " ");

    for (int i = 1; i < 3; i++)
    {
        values[i] = strtok(NULL, " ");
    }
    data->delay = atoi(values[0]);
    data->num_packets = atoi(values[1]);
    data->start_time = atoi(values[2]);
}