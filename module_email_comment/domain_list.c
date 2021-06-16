#include "domain_list.h"

domain_list *
new_domain_list(char *domain) {
    node *new = malloc(sizeof(node));
    new->next = NULL;
    new->domain = strdup(domain);
    domain_list *list = malloc(sizeof(domain_list));
    list->head = new;
    list->size = 1;
}

int add_domain(domain_list *list, char *domain) {
    assert(list);
    assert(domain);
    node *new = malloc(sizeof(node));
    new->domain = strdup(domain);
    new->next = list->head;
    list->head = new;
    return ++list->size;
}

void print_domain_list(domain_list *list) {
    node *start = list->head;
    do {
        printf("Domain: %s\n", start->domain);
    } while (start = start->next);
}
