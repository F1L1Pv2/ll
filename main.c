#include <stdio.h>
#include <malloc.h>

#define LINKED_LIST_IMPLEMENTATION
#include "ll.h"

typedef struct Baz Baz;

struct Baz{
    float foo;
    int bar;
    Baz* next;
};

void print_baz(Baz* baz){
    printf("baz: %f %d\n", baz->foo, baz->bar);
}

int main(){
    Baz* bazzess = NULL;
    
    ll_push(&bazzess, ((Baz){
        .foo = 4.20,
        .bar = 69,
    }), malloc);

    ll_push(&bazzess, ((Baz){
        .foo = 4.21,
        .bar = 70,
    }), malloc);

    ll_push(&bazzess, ((Baz){
        .foo = 4.25,
        .bar = 30,
    }), malloc);

    Baz* item = ll_at(bazzess, 1);
    print_baz(item);

    printf("--------- listing -----------\n");

    for(Baz* baz = bazzess; baz != NULL; baz = baz->next){
        print_baz(baz);
    }

    return 0;
}