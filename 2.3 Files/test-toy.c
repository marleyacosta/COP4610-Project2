#include <linux/module.h>

static int hello_init(void)
{
  printk("Hello world, we are Maurely Acosta and Tomas Ortega\n");
  printk("Hello World 2, we are Maurely Acosta and Tomas Ortega\n");
  printk("Hello World 3, we are Maurely Acosta and Tomas Ortega\n");
  return 0;
}

static void hello_exit(void)
{
  printk("Goodbye world, we are Maurely Acosta and Tomas Ortega\n");
  printk("Goodbye world 2, we are Maurely Acosta and Tomas Ortega\n");
  printk("Goodbye world 3, we are Maurely Acosta and Tomas Ortega\n");
  
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Maurely Acosta and Tomas Ortega");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello World");
