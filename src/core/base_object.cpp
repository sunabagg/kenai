//
// Created by lucas on 1/31/2025.
//

#include "base_object.h"

namespace sunaba::core
{
    
    const JSClassDef BaseObject::baseObjectJsClass = {
        "BaseObject",
        .finalizer = jsBaseObjectFinalizer,
    };
}

using namespace sunaba::core;

void BaseObject::notification(const int p_notification, bool p_reversed)
{
    if (p_reversed) {
        onNotification(p_notification);
    }
    else {
        onNotification(-p_notification);
    }


}