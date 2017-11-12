#include <linux/kernel.h>
#include <linux/sched.h>
asmlinkage int sys_specificAddr(unsigned long int specAddr)
{
  printk(KERN_EMERG "TEST\n");
  return 0;
}
