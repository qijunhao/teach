#include "inc/main.h"
void Func(float data) { printf("%.2f,", data); }
int	 main()
{
	List* list = InitList();

	ListHeadInsert(list, 10);
	ListHeadInsert(list, 9);
	ListHeadInsert(list, 8);

	TravelList(list, Func, ListFront2Tail);
	printf("\n");
	TravelList(list, Func, ListTail2Front);
	printf("\n");

	ListTailInsert(list, 10);
	ListTailInsert(list, 8);
	TravelList(list, Func, ListFront2Tail);
	printf("\n");
	TravelList(list, Func, ListTail2Front);
	printf("\n");

	float data;
	ListHeadDelete(list, &data);
	printf("%.2f,", data);
	ListTailDelete(list, &data);
	printf("%.2f\n", data);

	TravelList(list, Func, ListFront2Tail);
	printf("\n");
	TravelList(list, Func, ListTail2Front);
	printf("\n");
	return 0;
};
