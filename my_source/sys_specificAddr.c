#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/mm_types.h>
#include <asm/pgtable.h>
asmlinkage int sys_specificAddr(unsigned long int specAddr)
    long int id_to_find = pid;
    struct task_struct *task;
    struct mm_struct *mm;
    struct vm_area_struct *initial_vma;
    struct vm_area_struct *current_vma;
    long int spaceSize = 0;
    pgd_t *pgd;
    pmd_t *pmd;
    pte_t *pte;
    spinlock_t * lock;
    int present;
    for_each_process(task) {
        if (task->pid == id_to_find) {
            printk(KERN_EMERG "Process found");
            break;
        }
    }
    mm = task->mm;
    initial_vma = mm->mmap;
    //for(current_vma = initial_vma; current_vma != NULL; current_vma = current_vma->vm_next) {
    //    spaceSize += current_vma->vm_end - current_vma->vm_start;
    //}
    pgd = pgd_offset(mm, specAddr);
    if (pgd_none(*pgd) || pgd_bad(*pgd))
        return 0;
    pmd = pmd_offset(pgd, specAddr);
    if (pmd_none(*pmd) || pmd_bad(*pmd))
        return 0;
    pte = pte_offset_map_lock(mm, pmd, specAddr, &lock);
    //pte = pte_offset(pmd, specAddr);
    if (!ptep)
        return 0;

    present = pte_present(pte);
    pte_unmap_unlock(pte, lock);
    return present;
}
