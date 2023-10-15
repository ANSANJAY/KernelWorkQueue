API's to queue Work
--------------------

This function enqueues the given work item on the local CPU workqueue, but does not guarantee its execution on it

bool queue_work(struct workqueue_struct *wq, struct work_struct *work);

Once queued, the function associated with the work item is executed on any of the available CPUs by the relevant
kworker thread.
	
To queue work on a specific CPU
-----------------------------------
bool queue_work_on(int cpu, struct workqueue_struct *wq,
		struct work_struct *work)

    cpu: CPU number to execute work on

Return: false if work was already on a queue,
        true otherwise.
~                         
