#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h> //for character driver

ssize_t char_drv_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
  printk(KERN_ALERT, "Inside function %s \n", __FUNCTION__);
  return 0;
}
ssize_t char_drv_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
  printk(KERN_ALERT, "Inside function %s \n", __FUNCTION__);
  return length;
}
int char_drv_open (struct inode *pinode, struct file * pfile)
{
  printk(KERN_ALERT, "Inside function %s \n", __FUNCTION__);
  return 0;
}
int char_drv_release (struct inode *pinode, struct file *pfile)
{
  printk(KERN_ALERT, "Inside function %s \n", __FUNCTION__);
  return 0;
}

/*Hold file operations on this device
  defined: /lib/modules/3.10.0-327.18.2.el7.x86_64/build/include/linux/fs.h
*/
struct file_operations file_ops = {
  .owner = THIS_MODULE,
  .open = char_drv_open,
  .read = char_drv_read,
  .write = char_drv_write,
  .release = char_drv_release,
};

int char_drv_init_module()
{
  printk(KERN_ALERT, "Inside function %s \n", __FUNCTION__);

  //register as character device driver
  register_chrdev(/*Major number*/ 77,
                   /*driver name*/ "Hello World",
                   /*file operations*/&file_ops
                  );
  return 0;
}
void char_drv_cleanup_module()
{
  printk(KERN_ALERT, "Inside function %s \n", __FUNCTION__);

  //UNregister as character device driver
  unregister_chrdev(/*Major number*/ 77,
                   /*driver name*/ "Hello World"
                  );

}

module_init(char_drv_init_module);
module_exit(char_drv_cleanup_module);

