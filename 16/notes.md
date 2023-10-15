Flushing work
--------------------

bool flush_work(struct work_struct *work)

	wait for a work to finish executing the last queueing instance

returns true if waited for the work to finish execution, false if it was already idle


