#include <linux/list.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/init.h>

struct birthday
{
	int day;
	int month;
	int year;
	struct list_head list;
};

LIST_HEAD(birthday_list);

int load_birthdays(void)
{
	struct birthday *person;

	person = kmalloc(sizeof(*person), GFP_KERNEL);
	person->day = 2;
	person->month = 8;
	person->year = 1995;

	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list, &birthday_list);

	list_for_each_entry(person, &birthday_list, list)
	{
		printk(KERN_INFO "Birthday: %d-%d-%d\n", person->month, person->day, person->year);
	}
	return 0;
}

int simple_init(void)
{
	printk(KERN_INFO "Loading Module\n");
	
	load_birthdays();
	return 0;
}

int remove_birthdays(void)
{
	struct birthday *ptr, *next;
  
	list_for_each_entry_safe(ptr, next, &birthday_list, list)
	{
		printk(KERN_INFO "Removing Birthday: %d-%d-%d\n", ptr->month, ptr->day, ptr->year);
		list_del(&ptr->list);
		kfree(ptr);
	}
 	return 0;
}

void simple_exit(void)
{
	printk(KERN_INFO "Removing module\n");
	remove_birthdays();
	printk(KERN_INFO "Freed memory\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
