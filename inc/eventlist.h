#pragma once

#include "event.h"
#include "myMath.h"

bool EventAddListener(EventType event_type, EventCallback callback);
void EventBoradcast(EventType event_type, ...);
