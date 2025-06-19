#include "recipe_generator.h"

static int try_create_recipe(struct Ingredients *ingredients, struct TasteProfile *taste, struct Recipe **recipe)
{
    int approved = 0;
    int done = 0;

    while (!approved && !done)
    {
        if (*recipe)
        {
            free_recipe(*recipe);
            *recipe = NULL;
        }
        *recipe = create_recipe(ingredients, taste);
        if (*recipe)
            approved = get_user_approval(*recipe);
        else
            done = 1;
    }
    return approved;
}

struct Recipe *create_custom_recipe(void)
{
    struct Ingredients *ingredients = NULL;
    struct TasteProfile *taste = NULL;
    struct Recipe *recipe = NULL;
    int approved = 0;

    ingredients = get_current_ingredients();
    if (!ingredients)
        return NULL;
    taste = get_user_taste_profile();
    if (!taste)
    {
        free_ingredients(ingredients);
        return NULL;
    }
    approved = try_create_recipe(ingredients, taste, &recipe);
    if (!approved && recipe)
    {
        free_recipe(recipe);
        recipe = NULL;
    }
    free_ingredients(ingredients);
    free_taste_profile(taste);
    return recipe;
}