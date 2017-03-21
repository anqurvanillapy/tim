#include "tim.h"

void
Shm_open(const char *name, int oflag, mode_t mode);
{
    if (shm_open(name, oflag, mode) < 0) err_sys("shm_open error");
}
