#include "workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
    struct UserData *user = NULL;
    struct WorkoutPlan *plan = NULL;
    int duration = 0;
    int day;
    user = get_user_data(username);
    if (!user)
        return NULL;
    plan = build_base_plan(user);
    if (!plan)
        return (free_user_data(user), NULL);
    plan = refine_plan(plan, user);
    if (!plan)
        return (free_user_data(user), NULL);
    duration = determine_duration(plan);
    if (duration <= 0)
        return (free_user_data(user), free_workout_plan(plan), NULL);
    for (day = 1; day <= duration; ++day)
    {
        assign_daily_exercises(plan, day);
        assign_daily_tips(plan, day);
    }
    free_user_data(user);
    return (free_user_data(user), plan);
}