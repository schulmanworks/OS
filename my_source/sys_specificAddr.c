#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
//#include <asm/pgtable.h>

#include <linux/pagemap.h>
#include <linux/rmap.h>
#include <linux/swap.h>
#include <linux/swapops.h>
#include <linux/mmu_notifier.h>
#include <linux/hugetlb.h>
#include <linux/pagemap.h>
#include <linux/shmem_fs.h>


asmlinkage int sys_specificAddr(unsigned long int specAddr) {
    long int id_to_find;
    struct task_struct *task;
    struct mm_struct *mm;
    struct vm_area_struct *initial_vma;
    pgd_t *pgd;
    pud_t * pud;
    pmd_t *pmd;
    pte_t *ptep, pte;
    spinlock_t * lock;
    int present;
    printk(KERN_EMERG "spec 1\n");
    id_to_find = current->pid;
    printk(KERN_EMERG "spec 2\n");
    printk(KERN_EMERG "Process is running\n");
    for_each_process(task) {
        if (task->pid == id_to_find) {
            printk(KERN_EMERG "Process found\n");
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
    pud = pud_offset(pgd, specAddr);
    if (pud_none(*pud) || pud_bad(*pud))
        return 0;
    pmd = pmd_offset(pud, specAddr);
    if (pmd_none(*pmd) || pmd_bad(*pmd))
        return 0;
    ptep = pte_offset_map_lock(mm, pmd, specAddr, &lock);
    //pte = pte_offset(pmd, specAddr);
    if (!ptep)
        return 0;
    pte = *ptep;
    present = pte_present(pte);
    pte_unmap_unlock(ptep, lock);
    return present;
}
