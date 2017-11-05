#include <linux/kernel.h>
#include <linux/sched.h>

asmlinkage int sys_virtualAddrSpace(void) {
    printk(KERN_EMERG "Hello World from virtualAddrSpace!\n");
    return 0;
}
