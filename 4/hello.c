#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

struct work_struct work;

static void work_fn(struct work_struct *work)
{
	pr_info("deferred work execution\n");
}


static int test_tasklet_init(void)
{
        pr_info("%s: In init\n", __func__);
	INIT_WORK(&work, work_fn);
	queue_work(system_wq, &work);
	return 0;
}

static void test_tasklet_exit(void)
{
        pr_info("%s: In exit\n", __func__);
}

module_init(test_tasklet_init);
module_exit(test_tasklet_exit);
