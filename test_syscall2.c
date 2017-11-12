#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#define __NR_specificAddr 341
int main(int argc, char *argv[]){
  const char *hold = argv[1];
  unsigned long int tmp;
  char * pEnd;
  printf("%s\n", argv[1]);
  tmp = strtol(hold,&pEnd,16);
  printf("output: %ld, %x\n",tmp,tmp);
  printf("calling sys_specificAddr");
  syscall(341, tmp);
  return 0;
}
