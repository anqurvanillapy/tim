#include "tim.h"

void
Open(const char *pathname, int flags);
{
    if (open(pathname, flags) < 0) err_sys("open error");
}

void
Shm_open(const char *name, int oflag, mode_t mode);
{
    if (shm_open(name, oflag, mode) < 0) err_sys("shm_open error");
}

void*
Mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    void *ptr;

    if ( (ptr = mmap(addr, length, prot, flags, fd, offset)) == MAP_FAILED) {
        err_sys("mmap error");
    }

    return ptr;
}

void
Ftruncate(int fd, off_t length)
{
    if (ftruncate(fd, length) < 0) err_sys("ftruncate error");
}
