#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

int f_open(struct inode *pinode, struct file *pfile)
{
printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
return 0;
}

size_t f_read(struct file *pfile, char __user *buffer, size_t length,loff_t *offset)
{
printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
return 0;
}

size_t f_write(struct file *pfile, const char __user *buffer, size_t length,loff_t *offset)
{
printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
return length;
}

int f_close(struct inode *pinode, struct file *pfile)
{
printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
return 0;
}

struct file_operations f_file_operations = {
	.owner = THIS_MODULE,
	.open = f_open,
	.read = f_read,
	.write = f_write,
	.release = f_close,
};

int f_module_init(void)
{
	printk(KERN_ALERT "Inside the %s function\n" __FUNCTION__);
	register_chrdev(152/* Major Number */, 
				"Char_Drv" /* Name of the Driver */,
				&f_file_operations /* File operations */);
	return 0;
}

void f_module_exit(void)
{
	printk(KERN_ALERT "Inside the %s function\n " __FUNCTION__);
	unregister_chrdev(152, "Char_Drv");
}

MODULE_LICENSE(" GPL");

module_int(f_module_init);
module_exit(f_module_exit);
	
	
	
	
	
	
	
	
