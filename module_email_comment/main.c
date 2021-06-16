#include "domain_list.h"

int main(int argc, char *argv[]) {
    domain_list *list = new_domain_list("gmail.com");
    add_domain(list, "apple.com");
    print_domain_list(list);
}
