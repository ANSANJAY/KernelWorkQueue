Inline functions
-----------------

schedule_work - put work task in global workqueue

schedule_work_on - put work task on a specific cpu

static inline bool schedule_work(struct work_struct *work)
{
        return queue_work(system_wq, work);
}

static inline bool schedule_work_on(int cpu, struct work_struct *work)
{
        return queue_work_on(cpu, system_wq, work);
}

