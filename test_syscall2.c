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
  int exists;
  printf("%s\n", argv[1]);
  tmp = strtoul(hold,&pEnd,16);
  printf("output: %uld, %x\n",tmp,tmp);
  printf("calling sys_specificAddr\n");
  exists =  syscall(341, tmp);
  if(exists)
     printf("found in memory\n");
  else
     printf("not found in memory\n");
  printf("returned: %d\n",exists);
  return 0;
}
