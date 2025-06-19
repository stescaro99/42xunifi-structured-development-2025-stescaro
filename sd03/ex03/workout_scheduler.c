#include "workout_scheduler.h"

static struct WorkoutPlan *prepare_plan(struct UserData *user)
{
    struct WorkoutPlan *plan = NULL;

    plan = build_base_plan(user);
    if (plan)
        plan = refine_plan(plan, user);
    return plan;
}

static void assign_daily_tasks(struct WorkoutPlan *plan, int duration)
{
    for (int day = 1; day <= duration; ++day)
    {
        assign_daily_exercises(plan, day);
        assign_daily_tips(plan, day);
    }
}

struct WorkoutPlan *create_workout_schedule(char *username)
{
    struct UserData *user = NULL;
    struct WorkoutPlan *plan = NULL;
    int duration = 0;
    struct WorkoutPlan *result = NULL;

    user = get_user_data(username);
    if (user)
    {
        plan = prepare_plan(user);
        if (plan)
        {
            duration = determine_duration(plan);
            if (duration > 0)
            {
                assign_daily_tasks(plan, duration);
                result = plan;
            }
            else
            {
                free_workout_plan(plan);
            }
        }
        free_user_data(user);
    }
    return result;
}