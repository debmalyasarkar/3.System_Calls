/* Program to invoke a system call API function using assembly language */
/* Attempting to simulate invoking a system call with arguments */
/* Check system call list for Linux 32 or 64 bit platform and see
   which arguments are expected in which register */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char str[] = "foo.txt";

#if 0
/* Actual C Code that we are attempting to simulate in assembly */
int main(void)
{
  int fd = 0;
  fd = open(str, O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
  printf("The value returned by the syscall is %d\n",fd);
  return 0;
}
#endif

int sys_call(void)
{  
  int res = 0;
  __asm__("movl $5, %eax");
  __asm__("movl $str, %ebx");
  __asm__("movl $64, %ecx");
  __asm__("movl $511, %edx");
  __asm__("int $0x80");
  __asm__("movl %eax, -4(%ebp)");
  return res;
}

int main(void)
{
  int retVal = 0;
  retVal = sys_call();
  printf("The value returned by the syscall is %d\n",retVal);
  return 0;
}

