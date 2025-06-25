//
// Created by lucas on 1/31/2025.
//

#include "base_object.h"

using namespace lucidware::core;

void BaseObject::notification(const int p_notification, bool p_reversed)
{
    if (p_reversed) {
        onNotification(p_notification);
    }
    else {
        onNotification(-p_notification);
    }
}