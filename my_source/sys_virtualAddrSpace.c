#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/mm_types.h>
asmlinkage int sys_virtualAddrSpace(int pid) {
    long int id_to_find = pid;
    struct task_struct *task;
    struct mm_struct *mm;
    struct vm_area_struct *initial_vma;
    struct vm_area_struct *current_vma;
    long int spaceSize = 0;
    for_each_process(task) {
        if (task->pid == id_to_find) {
            printk(KERN_EMERG "Process found");
            break;
        }
    }
    mm = task->mm;
    initial_vma = mm->mmap;
    for(current_vma = initial_vma; current_vma != NULL; current_vma = current_vma->vm_next) {
        spaceSize += current_vma->vm_end - current_vma->vm_start;
    }
    printk(KERN_EMERG "pid: %d",pid);
    printk(KERN_EMERG "space size: %ld B, %ld KB", spaceSize, spaceSize/1024);
    printk(KERN_EMERG "Hello World from virtualAddrSpace!\n");
    return 0;
}
