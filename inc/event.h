#pragma once

#include "myMath.h"

#include <stdarg.h>

typedef enum {
	EVENT_A,
	EVENT_B,
	EVENT_COUNT,	// Keep this at the end
} EventType;

typedef void (*EventCallback)(va_list);

void RegisterEvent(EventType type, EventCallback callback);
void DispatchEvent(EventType type, ...);

void EventExample();
