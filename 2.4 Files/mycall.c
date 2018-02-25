/*
By: Maurely Acosta and Tomas Ortega

*/

#include <linux/linkage.h>
#include <linux/time.h>
#include <linux/sched.h>  //to get current->pid

void do_gettimeofday(struct timeval *tv);

int offset = 0;
int getMonth = 0;
int getDay = 0;
int getYear = 0; 

asmlinkage long sys_mycall(int i, int j)
{
  
  printk("Maurely Acosta and Tomas Ortega call from process %d with panther ID %d and %d.\n"
	, current->pid,	i ,j  );

  /* Code for displaying the current time*/
  offset = -18000; // Time zone offset for Eastern Time Zone.  
  
  struct timeval totalsecs; // Total seconds elapsed

  struct tm broken; // Calendar time in broken down format
  	  

  do_gettimeofday(&totalsecs);

  time_to_tm(totalsecs.tv_sec, offset, &broken);
	
  getMonth = broken.tm_mon;
  getDay = broken.tm_mday;
  getYear = broken.tm_year + 1900;  

  printk("COP4610 %d:%d:%d, %d, %d, %d", broken.tm_hour, broken.tm_min, broken.tm_sec, 
         getMonth, getDay, getYear);


  return 0;

}
