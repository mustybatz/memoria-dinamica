#include "list.h"



LIST list_create()
{
	LIST tmp = malloc(sizeof(struct STRLIST));
	tmp->first = NULL;
	tmp->last = NULL;
	tmp->size = 0;
	tmp->prefirst = malloc(sizeof(struct STRNODE));
	tmp->postlast = malloc(sizeof(struct STRNODE));
	tmp->prefirst->prior = NULL;
	tmp->prefirst->data = NULL;
	tmp->postlast->next = NULL;
	tmp->postlast->data = NULL;
	return (tmp);
}

void list_insert(LIST list, TYPE data)
{
	NODE new = malloc(sizeof(struct STRNODE));
	new->data = data;
	new->next = NULL;
	new->prior = NULL;

	if (list->first == NULL) // La lista está vacía
	{
		list->first = new;
		list->prefirst->next = list->first;
	}
	else
	{
		new->prior = list->last;
		list->last->next = new;
	}
	list->last = new;
	list->postlast->prior = list->last;
}

void list_insert_int(LIST list,int n)
{
	int *intptr=malloc(sizeof(int));
	*intptr=n;
	list_insert(list,intptr);
}

TYPE list_remove(LIST list, int pos) {

}