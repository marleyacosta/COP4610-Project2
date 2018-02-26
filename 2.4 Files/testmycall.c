#include<stdio.h>
#include "testmycall.h"
int main(void)
{
int x = 3914479;
int y = 5677483;
printf("%ld\n", syscall(__NR_mycall,x, y));
}
