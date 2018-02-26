/*
By: Maurely Acosta and Tomas Ortega

*/

#include <linux/linkage.h>
#include <linux/time.h>
#include <linux/sched.h>  //to get current->pid

asmlinkage long sys_mycall(int i, int j)
{
	struct tm result;
        struct timeval t;
        int hour;
        int min;
        int sec;
        int month;
        int mday;
        int year;
        int offset;
	
        printk("Maurely Acosta and Tomas Ortega called from process %d with panther ID: %d and %d.\n", current->pid, i, j);

        do_gettimeofday(&t);
        offset = -18000;
        time_to_tm(t.tv_sec, offset, &result);
        hour = result.tm_hour;
        min = result.tm_min;
        sec = result.tm_sec;
        month = result.tm_mon + 1;
        mday = result.tm_mday;
        year = result.tm_year + 1900;

        printk("COP4610 %d:%d:%d  %d, %d, %d \n", hour, min, sec, month, mday, year);

        return 0;

}
