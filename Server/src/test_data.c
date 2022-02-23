
#include "test_data.h"
void build_message(char* message, char** args)
{
    char buf[64];
    sprintf(buf, "%s %s %s", args[1], args[2], args[3]);
    message = strdup(buf);
}
