#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
    struct OrderConfirmation *conf = NULL;
    int status = 0;

    if (!request)
        return -1;
    if (check_restaurant_status(request))
        conf = create_standard_confirmation();
    else
        conf = create_preorder_confirmation();
    if (!conf)
        return -1;
    send_confirmation_notification(conf);
    free(conf);
    return status;
}