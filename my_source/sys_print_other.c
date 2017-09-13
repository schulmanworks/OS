#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>
asmlinkage int sys_print_other(void) {
    printk(KERN_EMERG "Running sys_print_other 1");
    long int id_to_find;
    struct task_struct *temp;
    temp = current;
    id_to_find = temp->pid;
    struct task_struct *task;
    //task = init_task;
    //for (task=current; task != &init_task; task=task->parent) {
    printk(KERN_EMERG "Looking for pid %ld", id_to_find);
    for_each_process(task) {
        printk(KERN_EMERG "STATE %ld task name %s [%d]\n", task->state, task->comm, task->pid);
        if (task->pid == id_to_find) {
            printk(KERN_EMERG "found your pid");
            break;
        }
        else {
            printk(KERN_EMERG "still looking for %ld\n", id_to_find);
        }
    }
    return 0;
}
