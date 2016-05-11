// Simple hello world kernel module

#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
	printk(KERN_INFO "Hello world 1. \n");
	return 0;
	// non-zero return => init_module fial => module cant be loaded
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}

