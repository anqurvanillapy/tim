#include "tim.h"

int
main(int argc, const char *argv)
{
    char usr[20];

    printf(" _   _\n"
           "| |_(_)_ __ ___\n"
           "| __| | '_ ` _ \\\n"
           "| |_| | | | | | |\n"
           " \\__|_|_| |_| |_|\n"
           "tim: TTY-based instant messaging app.\n");
    printf("yourname> ");
    fgets(usr, sizeof(usr), stdin);
    printf("\r\33[2K\r");
    printf("successfully signed in!\n");
    printf("%s> ", usr);
    printf("\n");

    return 0;
}
                 
