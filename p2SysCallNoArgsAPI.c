/* Program to invoke a system call API function which uses assembly language */
/* This system call supports no arguments */
/* The sys_call() acts as a wrapper function to the actual system call code
   in assembly - Example how library calls are a wrapper to system calls */

#include <stdio.h>

int sys_call(void)
{  
  int res = 0;
  __asm__("movl $20, %eax");
  __asm__("int $0x80");
  __asm__("movl %eax, -4(%ebp)"); 
  return res;
}

int main(void)
{
  int retVal = 0;
  /* API to User, system call invoked internally */
  retVal = sys_call();
  printf("The value returned by the syscall is %d\n",retVal);
  return 0;
}

