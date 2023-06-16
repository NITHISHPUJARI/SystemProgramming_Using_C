#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>		/* For the character driver support */

int f_open(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}

ssize_t f_read(struct file *pfile, char __user *buffer,size_t length,loff_t *offset){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}
ssize_t f_write(struct file *pfile, const char __user *buffer,size_t length,loff_t *offset){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return length;
}
int f_close(struct inode *pinode,struct file *pfile){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}

/* To hold the file operations performed on this device */
struct file_operations ex07_file_operations = {
	.owner	 = THIS_MODULE,
	.open	 = f_open,
	.read	 = f_read,
	.write	 = f_write,
	.release = f_close,
};

int ex07_simple_module_init(void)
{
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	/* Register with the kernel and indicate that we are registering a character device driver */
	register_chrdev(125/* Major Number */,
			"Simple_Char_Drv" /* Name of the driver */,
			&ex07_file_operations /* File Operations */);
	return 0;
}

void ex07_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);

	/* Unregister the character device driver */
	unregister_chrdev(125,"Simple_Char_Drv");
}
MODULE_LICENSE("GPL");
module_init(ex07_simple_module_init);
module_exit(ex07_simple_module_exit);
