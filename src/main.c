#include "inc/main.h"

void Func1(va_list args);
void Func2(va_list args);
void Func3(va_list args);
void Func4(va_list args);
void Func5(va_list args);
void Func6(va_list args);

int main()
{
	EventAddListener(EVENT_A, Func1);
	EventAddListener(EVENT_B, Func2);
	EventAddListener(EVENT_A, Func3);
	EventAddListener(EVENT_B, Func4);
	EventAddListener(EVENT_B, Func5);
	EventAddListener(EVENT_A, Func6);

	EventBroadcast(EVENT_A, 1.2345678, "data from EVENT_A");
	EventBroadcast(EVENT_B, 8.7654321, "data from EVENT_B", "jiejiejie");

	return 0;
};

void Func1(va_list args)
{
	float		floatValue	= (float) va_arg(args, double);	   // float values are promoted to double when passed through '...'
	const char* stringValue = va_arg(args, const char*);
	printf("Retain 1 decimal place:%.1f,%s\n", floatValue, stringValue);
};
void Func2(va_list args)
{
	float		floatValue	 = (float) va_arg(args, double);	// float values are promoted to double when passed through '...'
	const char* stringValue1 = va_arg(args, const char*);
	const char* stringValue2 = va_arg(args, const char*);
	printf("Retain 2 decimal place:%.2f,%s,%s\n", floatValue, stringValue1, stringValue2);
};

void Func3(va_list args)
{
	float		floatValue	= (float) va_arg(args, double);	   // float values are promoted to double when passed through '...'
	const char* stringValue = va_arg(args, const char*);
	printf("Retain 3 decimal place:%.3f,%s\n", floatValue, stringValue);
};
void Func4(va_list args)
{
	float		floatValue	 = (float) va_arg(args, double);	// float values are promoted to double when passed through '...'
	const char* stringValue1 = va_arg(args, const char*);
	const char* stringValue2 = va_arg(args, const char*);
	printf("Retain 4 decimal place:%.4f,%s,%s\n", floatValue, stringValue1, stringValue2);
};
void Func5(va_list args)
{
	float		floatValue	 = (float) va_arg(args, double);	// float values are promoted to double when passed through '...'
	const char* stringValue1 = va_arg(args, const char*);
	const char* stringValue2 = va_arg(args, const char*);
	printf("Retain 5 decimal place:%.5f,%s,%s\n", floatValue, stringValue1, stringValue2);
};
void Func6(va_list args)
{
	float		floatValue	= (float) va_arg(args, double);	   // float values are promoted to double when passed through '...'
	const char* stringValue = va_arg(args, const char*);
	printf("Retain 6 decimal place:%.6f,%s\n", floatValue, stringValue);
};