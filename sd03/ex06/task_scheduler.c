#include "task_scheduler.h"

static int assign_tasks_to_cores(struct ScheduleResult *result, struct TaskProfile *profile, int core_count)
{
    int core = 0;
    int stop = 0;
    while (core < core_count)
    {
        int task_id = select_best_task(profile);
        if (task_id == -1)
            stop = 1;
        if (!stop)
            update_schedule_entry(result, core, task_id);
        core++;
    }
    return 0;
}

static void cleanup_scheduler(struct PriorityMap *priorities, struct TaskProfile *profile)
{
    free_priority_map(priorities);
    free_task_profile(profile);
}

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
    struct TaskProfile *profile = NULL;
    struct PriorityMap *priorities = NULL;
    struct ScheduleResult *result = NULL;
    int core_count = 0;

    profile = profile_tasks(tasks);
    if (!profile)
        return NULL;
    priorities = compute_priorities_mock(profile);
    if (!priorities)
    {
        free_task_profile(profile);
        return NULL;
    }
    core_count = get_available_core_count();
    result = create_schedule_result(core_count);
    if (!result)
    {
        cleanup_scheduler(priorities, profile);
        return NULL;
    }
    assign_tasks_to_cores(result, profile, core_count);
    cleanup_scheduler(priorities, profile);
    return result;
}