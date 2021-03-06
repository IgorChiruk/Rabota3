// Rab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


							//1.	Напишите функцию, создающую двунаправленный список по заданному однонаправленному.

//struct item {
//	int value;
//	struct item *next;
//};
//
//struct itemDV
//{
//	int value;
//	struct itemDV *next;
//	struct itemDV *prev;
//};
//
//void insert(int value);
//void convert(struct item *list);
//
//struct item *list = NULL;
//struct itemDV *list2 = NULL;
//struct itemDV *tail = NULL;
//
//int main()
//{
//	srand(time(0));
//	setlocale(LC_ALL, "RUS");
//
//	for (int i = 0; i < 100; i++) 
//	{
//		int value = 10 + rand() % 1000;
//		insert(value);
//	}
//	convert(list);
//
//	struct item *p = list;
//
//	printf("Односвязный массив from Head to End:\n\n");
//	while (p!=nullptr)
//	{
//		printf("%d\n",p->value);
//		p = p->next;
//	}
//	free(p);
//
//	struct itemDV *p2 = tail;
//
//	printf("\nДвусвязный массив from Tail to Head:\n\n");
//	while (p2 != nullptr)
//	{
//		printf("%d\n", p2->value);
//		p2 = p2->prev;
//	}
//
//	getchar();
//	return 0;
//}
//
//void insert(int value) 
//{
//	struct item *cur = list;
//	struct item *p = new item;
//	p->value = value;
//	p->next = NULL;
//
//	if (list == NULL) 
//	{
//		list = p;
//	}
//	else
//	{
//		if (list->value <=p->value) 
//		{
//			p->next = list;
//			list = p;
//		}
//		else
//		{
//			p = list;
//			while (p != NULL && p->value > value)
//			{
//				cur = p;
//				p = p->next;
//			}
//			struct item *temp = new item;
//			temp->value = value;
//			temp->next = p;
//			cur->next = temp;
//		}
//	}
//	
//	
//}
//
//void convert(struct item *list) 
//{
//	struct item *cur;
//	
//	/*struct itemDV *prev2 = new itemDV;
//	struct itemDV *next2 = new itemDV;*/
//
//	if (list != nullptr) 
//	{
//		cur = list;
//		struct itemDV *cur2 = new itemDV;
//		cur2->value = cur->value;
//		cur2->prev = NULL;
//		list2 = cur2;
//
//		while (cur != NULL)
//		{
//			struct itemDV *temp = new itemDV;
//			cur = cur->next;
//			if (cur != nullptr) 
//			{
//			temp->value = cur->value;
//			temp->prev = cur2;
//			cur2 = temp;
//			}
//		}
//		cur2->next = NULL;
//		tail = cur2;
//	}
//
//}






						//2.	Напишите функцию, которая выполняет рекурсивный поиск заданного значения в списке.
						//В том случае, если оно обнаружено, функция должна возвращать указатель на значение; 
						//в противном случае должно возвращаться значение NULL.

struct item {
	int value;
	struct item *next;
};

void insert(int value);
item* find(int value, struct item *p);

struct item *list = NULL;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RUS");
	
	for (int i = 0; i < 100; i++) 
	{
		int value = 10 + rand() % 50;
		insert(value);
	}

	struct item *p = list;

	printf("Односвязный массив from Head to End:\n\n");
	while (p!=nullptr)
	{
		printf("%d\n",p->value);
		p = p->next;
	}

	p = list;
	p = find(50, p);

	if (p == nullptr)
		printf("Значение не найдено");
	else
		printf("Значение найдено: %d", p->value);
	getchar();

	return 0;
}

item* find(int value, struct item *p) 
{
	if (p == nullptr)
		return p;
	if (p->value==value)
		return p;
	p = p->next;
	find(value, p);
}

void insert(int value)
{
	struct item *cur = list;
	struct item *p = new item;
	p->value = value;
	p->next = NULL;

	if (list == NULL)
	{
		list = p;
	}
	else
	{
		if (list->value <= p->value)
		{
			p->next = list;
			list = p;
		}
		else
		{
			p = list;
			while (p != NULL && p->value > value)
			{
				cur = p;
				p = p->next;
			}
			struct item *temp = new item;
			temp->value = value;
			temp->next = p;
			cur->next = temp;
		}
	}
}