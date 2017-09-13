#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>
asmlinkage int sys_print_self(void) {
    printk(KERN_EMERG "Running sys_print_self 1");
    struct task_struct *task;
    for (task=current; task != &init_task; task=task->parent) {
        printk(KERN_EMERG "state state: %d task name: %s [%d]\n", task->state, task->comm, task->pid);
    }
    return 0;
}
