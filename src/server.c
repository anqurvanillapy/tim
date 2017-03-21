#include "tim.h"

int
main(int argc, const char *argv[])
{
    int ipcfd, connfd, listenfd;
    char ipc_name[20];
    struct tim_shm *shmbuf;

    if (argc != 2) err_quit("usage: tim-server ip_addr port");

    // PID for current unique name.
    snprintf(ipc_name, sizeof(ipc_name), "/tmp/tim.%d", getpid());

    shm_unlink(ipc_name);   // OK if it fails
    ipcfd = Shm_open(ipc_name, O_RDWR | O_CREAT | O_EXCL, FILE_MODE);

    return 0;
}
