#include <stdlib.h>

typedef void *TYPE;

struct STRNODE
{
    TYPE data;
    struct STRNODE *prior, *next;
};

typedef struct STRNODE *NODE;

struct STRLIST
{
    NODE first, last, prefirst, postlast;
    int size;
    void (*destructor)(void *);
};

typedef struct STRLIST *LIST;
typedef NODE ITERATOR; 

LIST list_create();

void list_destroy(LIST l);

int list_size(LIST l);

void list_add(LIST l, TYPE e);

TYPE list_get(LIST l, int p);

void list_set(LIST l, TYPE e, int p);

TYPE list_remove(LIST l, int p);

#define list_begin(l) (l->prefirst)
#define has_next(i) (i->next)
#define iterator_data(i) (*((int *) i->data))
#define list_next(i) (i->next)
#define list_end(l) (l->postlast)
#define has_prior(i) (i->prior)
#define list_prior(i) (i->prior)