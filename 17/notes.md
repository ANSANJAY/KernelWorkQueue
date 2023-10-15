Delayed work
--------------

Workqueue API allows you to queue work tasks whose execution is guaranteed to be delayed at least until a specified timeout.

This is achieved by binding a work task with a timer, which can be initialized with an expiry timeout, until which time the work task is not scheduled into the queue

struct delayed_work {
        struct work_struct work;
        struct timer_list timer;

        /* target workqueue and CPU ->timer uses to queue ->work */
        struct workqueue_struct *wq;
        int cpu;
};

timer is an instance of a dynamic timer descriptor, which is initialized with the expiry interval and armed while scheduling a work task

Initialization
---------------

Static:
----------

DECLARE_DELAYED_WORK(name, void(*function)(struct work_struct *));

Dynamic:
-----------

INIT_DELAYED_WORK(struct delayed_work *work, void(*function)(struct work_struct *));

Scheduling
------------

bool schedule_delayed_work(struct delayed_work *dwork,
                                         unsigned long delay);

bool schedule_delayed_work_on(int cpu, struct delayed_work *dwork,
                                            unsigned long delay);

delay needs to be provided in jiffies
