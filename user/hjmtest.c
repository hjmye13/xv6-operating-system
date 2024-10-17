// xv6-book中的小练习
#include "kernel/types.h"
#include "user/user.h"

int main() {
    // char buf[512];
    // int n;
    // for (;;) {
    //     n = read(0, buf, sizeof buf);
    //     if (n == 0)
    //         break;
    //     if (n < 0) {
    //         fprintf(2, "read error\n");
    //         exit(1);
    //     }
    //     if (write(1, buf, n) != n) {
    //         fprintf(2, "write error\n");
    //         exit(1);
    //     }
    // }

    // if (fork() == 0) {
    //     write(1, "hello ", 6);
    //     exit(0);
    // } else {
    //     wait(0);
    //     write(1, "world\n", 6);
    // }
    // exit(0);

    int p[2];
    char *argv[2];
    argv[0] = "wc";
    argv[1] = 0;
    pipe(p);
    if (fork() == 0) {
        close(0);
        dup(p[0]);
        // close(p[0]);
        printf("test fd = %d\n",p[0]);
        close(p[1]);
        exec("wc", argv);
        exit(0);
    } else {
        close(p[0]);
        write(p[1], "hello world\n", 12);
        close(p[1]);
        wait(0);
        exit(0);
    }

}
