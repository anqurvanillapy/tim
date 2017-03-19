#ifndef __tim__tim_h
#define __tim__tim_h

#include <stdio.h>
#include <semaphore.h>

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

#endif // !__tim__tim_h
