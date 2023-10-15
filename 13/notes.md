Cancelling work
----------------

Work items can not be enabled/disabled but they can be canceled by calling cancel_work_sync()

bool cancel_work_sync(struct work_struct *work);

The call only stops the subsequent execution of the work item.

If the work item is already running at the time of the call, it will continue to run

Return
-------
	true	-	if work was pending
	false	-	otherwise
