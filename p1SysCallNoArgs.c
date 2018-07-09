/* Program to invoke a system call using assembly language */
/* This system call supports no arguments */

#include <stdio.h>

int main(void)
{
  int retVal = 0;

  /* Invoking System Call through ID 20 */
  /* In reality it is the ID of getPID() System Call */
  __asm__("movl $20, %eax");
  /* Programmed Interrupt 0x80 called as a Trap to switch
     from user mode to kernel mode */
  __asm__("int $0x80");
  /* Save the return value in retVal */
  /* The location offset will depend on the ABI */
  /* Please see .s file to locate the variable offset */
  __asm__("movl %eax, -12(%ebp)");
  printf("The value returned by syscall is %d\n",retVal);
  return 0;
}


/*
1. The INT n instruction generates a call to the interrupt or exception 
   handler specified with the destination operand. 
2. The destination operand specifies a vector from 0 to 255, encoded as 
   an 8-bit unsigned intermediate value. 
3. The INT n instruction is the general mnemonic for executing a 
   software-generated call to an interrupt handler.

Here, 0x80 is the destination operand. At this point the CPU knows that it 
should execute some code that resides in the Kernel, but what code to execute
is determined by the Interrupt Handler in Linux.
*/
