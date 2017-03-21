#include "tim.h"

int
main(int argc, const char *argv[])
{
    int ipcfd, connfd, listenfd;
    int msgi, lastoverflow;
    char ipc_name[20];
    struct tim_shm *buf;

    if (argc != 2) err_quit("usage: tim-server ip_addr port");

    // Shared-memory object name by PID for current unique name.
    snprintf(ipc_name, sizeof(ipc_name), "/tmp/tim.%d", getpid());

    // SHM object initialization.
    shm_unlink(ipc_name);   // OK if it fails
    ipcfd = Shm_open(ipc_name, O_RDWR | O_CREAT | O_EXCL, FILE_MODE);
    buf = Mmap(NULL, sizeof(struct buf), PROT_READ | PROT_WRITE,
               MAP_SHARED, ipcfd, 0 /* offset */);
    Ftruncate(ipcfd, sizof(struct buf));
    Close(fd);

    // Initialize the array of offsets.
    for (msgi = 0; msgi < NMSG; ++msgi) buf->msgoff[msgi] = msgi * MSGSIZ;

    // Initialize semaphores.
    Sem_init(&buf->mutex, 1, 1);
    Sem_init(&buf->nempty, 1, NMSG);
    Sem_init(&buf->nstored, 1, 0);
    Sem_init(&buf->mutex_overflow, 1, 1);

    // Server message polling.
    msgi = lastoverflow = 0;
    for (;;) {

    }

    return 0;
}
