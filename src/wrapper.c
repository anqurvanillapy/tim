#include "tim.h"

void
Open(const char *pathname, int flags)
{
    if (open(pathname, flags) < 0) err_sys("open error");
}

void Close(int fd)
{
    if (close(fd) < 0) err_sys("close error");
}

void
Sem_init(sem_t *sem, int pshared, unsigned int value)
{
    if (sem_init(sem, pshared, value) < 0) err_sys("sem_init error");
}

void
Sem_wait(sem_t *sem)
{
    if (sem_wait(sem) < 0) err_sys("sem_wait error");
}

void
Sem_post(sem_t *sem)
{
    if (sem_post(sem) < 0) err_sys("sem_post error");
}

int
Shm_open(const char *name, int oflag, mode_t mode)
{
    int fd;

    if ( (fd = shm_open(name, oflag, mode)) < 0) err_sys("shm_open error");

    return fd;
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
