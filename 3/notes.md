Data structures
------------------

workqueue 		--	struct workqueue_struct
work items		-- 	struct work_struct

struct work_struct {
        atomic_long_t data;
        struct list_head entry;
        work_func_t func;
};

func is a pointer that takes the address of the deferred routine

typedef void (*work_func_t)(struct work_struct *work);

Initialization of Work Items
-----------------------------

Header File: <linux/workqueue.h>

Static: declare and initialize a work item
-------
DECLARE_WORK(name, void (*function)(void *), void *data);

Dynamic: initialize an already declared work item.
--------
INIT_WORK(struct work_struct *work, void(*function)(struct work_struct *));

