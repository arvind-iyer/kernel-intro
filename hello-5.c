// Demonstrate command line argument passing

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Arvind Iyer");

static short int myshort = 1;
static int myint = 420; // so dank
static long int mylong = 6969;
static char *mystring = "dat boi";
static int myintArray[2] = { -1, -1 };
static int arr_argcc = 0;

/*
 * Parameters using  module_param(foo, type, 0000);
 * 1: Parameter name
 * 2: Parameter data type
 * 3: Permissions
 */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint,   int,   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long int");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

/*
 * Parameters using module_param_array(myarray, type, &arr, 0000);
 * 1: Parameter name 
 * 2: Data type of elements
 * 3: Pointer to the variable that will store the number
 * 4: Permissions
 */

module_param_array(myintArray, int, &arr_argcc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");

static int __init hello_5_init(void) 
{
	int i;
	printk(KERN_INFO "Hello world 5\n");
	printk(KERN_INFO "myshort : %hd\n", myshort);
	printk(KERN_INFO "myint : %d\n", myint);
	printk(KERN_INFO "mylong : %ld\n", mylong);
	printk(KERN_INFO "mystring : %s\n", mystring);
	for(i = 0; i < (sizeof myintArray / sizeof (int)); i++)
	{
		printk(KERN_INFO " myintArray[%d] : %d\n", i, myintArray[i]);
	}
	printk(KERN_INFO "Got %d arguments for myintArray. \n", arr_argcc);
	return 0;
}

static void __exit hello_5_exit(void)
{
	printk(KERN_INFO "Goodbye world 5\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);


