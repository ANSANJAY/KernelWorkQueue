Work Queues
-----------

Introduced in Linux 2.6

They allow kernel functions to be activated and later executed by special kernel threads called worker threads.

Worker threads run in process context.

It is the only choice when you need to sleep in your bottom half (I/O data, hold mutexes/semaphores and all other functions that internally sleep)

Implementation: kernel/workqueue.c

Design
-----------

work item: struct which hold the pointer to the function to be executed asynchronously

work queue: a queue of work items

Drivers add work item into the work queue

Worker Threads: Special purpose threads which execute the functions from the queue, one after the other

		If no work is queued, the worker threads become idle,

		ps -ef | grep kworker

Worker Pools:	A thread pool that is used to manage the worker threads

		There are two worker-pools, 
			one for normal work items and 
			the other for high priority ones,
			some extra worker-pools to serve work items queued on unbound workqueues

		create_worker is the function where kthreads are created



Legacy Workqueues
------------------

Legacy workqueues have dedicated threads associated with them.

The new workqueues do away with that. There are no threads dedicated to any specific workqueue

Instead, there is a global pool of threads attached to each CPU in the system

When a work item is enqueued, it will be passed to one of the global threads at the right time



