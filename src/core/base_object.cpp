//
// Created by lucas on 1/31/2025.
//

#include "base_object.h"

using namespace newhaven_core;

void BaseObject::free()
{
    this->onFree();
    delete this;
}

void BaseObject::notification(const int p_notification, bool p_reversed) const
{
    if (p_reversed) {
        this->onNotification(p_notification);
    }
    else {
        this->onNotification(-p_notification);
    }
}