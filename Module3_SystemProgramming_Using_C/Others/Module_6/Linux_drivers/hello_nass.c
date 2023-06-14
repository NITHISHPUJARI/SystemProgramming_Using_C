#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_INFO(MODULE_NAME,"HELLO Nasscom");
MODULE_AUTHOR("Nithish");
MODULE_DESCRIPTION("HELLO Nasscom program");
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
printk(KERN_INFO "Hello world\n");
return 0;

}

static void hello_exit(void)
{
printk(KERN_ALERT "Good Bye\n");


}

module_init(hello_init);
module_exit(hello_exit);


