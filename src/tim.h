#ifndef __tim__tim_h
#define __tim__tim_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <semaphore.h>

/// Default permissions for new files (users read/write, group read, others
/// read).
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

#define MSGSIZ  256 // max #bytse per message, including null at end
#define NMSG    16  // max #messages

/// Error handling.
#define err_quit(errmsg) do {   \
    fputs(errmsg, stdout);      \
    exit(EXIT_FAILURE);         \
} while(0)

#define err_sys(errmsg) do {    \
    perror(errmsg);             \
    exit(EXIT_FAILURE);         \
} while(0)

/// This is stored in shared memory.
struct tim_shm {
    sem_t   mutex;                  // Three memory-based semaphores for
    sem_t   nempty;                 // producer-consumer buffer.
    sem_t   nstored;
    int     nput;                   // index of next message
    long    noverflow;              // #overflows by the senders
    sem_t   mutex_overflow;         // mutex for noverflow counter
    long    msgoff[NMSG];           // offset of each message
    char    msgdata[NMSG * MSGSIZ]; // actual messages
};

void    Open(const char *pathname, int flags);
void    Close(int fd);
void    Sem_init(sem_t *sem, int pshared, unsigned int value);
void    Sem_wait(sem_t *sem);
void    Sem_post(sem_t *sem);
int     Shm_open(const char *name, int oflag, mode_t mode);
void*   Mmap(void *addr, size_t length, int prot, int flags, int fd,
             off_t offset);
void    Ftruncate(int fd, off_t length);

#endif // !__tim__tim_h
