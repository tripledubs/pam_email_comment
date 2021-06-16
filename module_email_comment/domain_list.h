#ifndef DOMAIN_LIST_H
#define DOMAIN_LIST_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

typedef struct node {
    struct node *next;
    char *domain;
} node;

typedef struct domain_list {
    node *head; 
    size_t size;
} domain_list;

domain_list * new_domain_list(char *domain);
int add_domain(domain_list *list, char *domain);
void print_domain_list(domain_list *list);

#endif
