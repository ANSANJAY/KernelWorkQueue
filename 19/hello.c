#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");

struct delayed_work work;
int cpu = 2;
module_param(cpu, int, 0);

static void work_fn(struct work_struct *work)
{
	pr_info("processor id:%d\tdeferred work execution\n", smp_processor_id());
}


static int test_tasklet_init(void)
{
        pr_info("processor id:%d: In init\n", smp_processor_id());
	INIT_DELAYED_WORK(&work, work_fn);
	schedule_delayed_work_on(cpu, &work, msecs_to_jiffies(5000));
	flush_delayed_work(&work);
	return 0;
}

static void test_tasklet_exit(void)
{
        pr_info("%s: In exit\n", __func__);
}

module_init(test_tasklet_init);
module_exit(test_tasklet_exit);
