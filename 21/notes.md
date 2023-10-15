Differences between Tasklets, softirqs and Workqueues
========================================================
		------------------------------------------------------------------------------
		Softirqs			Tasklets			Workqueues
		-----------------------------------------------------------------------------
Execution	Interrupt context		Interrupt Context		Process Context
Context
----------------------------------------------------------------------------------------------------------------
Reentrancy	Yes(can run simultaneously	Cannot run same tasklets	Yes (can run simultaneously
		on different CPUs)		on different CPUs. Different	on different CPUs)
						CPUs can run different tasklets
--------------------------------------------------------------------------------------------------------------
Sleep		Cannot sleep			Cannot Sleep			Can Sleep
--------------------------------------------------------------------------------------------------------------
Preemption	Cannot be preempted/scheduled	Cannot be preempted/scheduled	May be preempted/scheduled
-----------------------------------------------------------------------------------------------------------
Ease of use	Not easy to use			Easy to use			Easy to use
-------------------------------------------------------------------------------------------------------------
When to use	If deferred work will not       If deferred work will not go    If deferred work needs to sleep
		go to sleep and have crucial	to sleep
		scalability or speed
		requirements
----------------------------------------------------------------------------------------------------------------
