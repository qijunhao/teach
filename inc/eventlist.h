#pragma once

#include "event.h"
#include "myMath.h"

typedef void (*EventCallback)(va_list);

typedef struct EventListNode {
	EventCallback		  func;
	struct EventListNode* next;
} EventListNode;

typedef struct EventGroup {
	EventListNode eventList[EVENT_COUNT];
} EventGroup;

bool EventAddListener(EventType event_type, EventCallback callback);
void EventBoradcast(EventType event_type, ...);

extern EventGroup g_eventGroup;