#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#define __NR_helloworld 337
#define __NR_print_self 338
#define __NR_print_other 339
int main(int argc, char *argv[]) {
//    syscall(__NR_helloworld);
    //syscall(__NR_print_self);
    syscall(__NR_print_other);
    //syscall(400);
    return 0;
}
