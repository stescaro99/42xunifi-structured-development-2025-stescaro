#include "recipe_generator.h"

struct Recipe *create_custom_recipe(void)
{
    struct Ingredients *ingredients = get_current_ingredients();
    if (!ingredients)
        return NULL;
    struct TasteProfile *taste = get_user_taste_profile();
    if (!taste)
        return (free_ingredients(ingredients), NULL);
    struct Recipe *recipe = NULL;
    int approved = 0;
    while (!approved)
    {
        if (recipe)
            free_recipe(recipe);
        recipe = create_recipe(ingredients, taste);
        if (!recipe)
            break;
        approved = get_user_approval(recipe);
    }
    if (!approved && recipe)
    {
        free_recipe(recipe);
        recipe = NULL;
    }
    return (free_ingredients(ingredients), free_taste_profile(taste), recipe);
}