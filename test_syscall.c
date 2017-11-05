#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#define __NR_helloworld 337
#define __NR_print_self 338
#define __NR_print_other 339
#define __NR_virtualAddrSpace 340
int main(int argc, char *argv[]) {
	int tmp;
    //syscall(__NR_helloworld);
  //  syscall(__NR_print_self);
//    syscall(__NR_print_other);
    printf("%s\n", argv[1]);
    tmp = atoi(argv[1]);
    syscall(340, tmp);
    //syscall(400);
    return 0;
}
