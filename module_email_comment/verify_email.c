#include "verify_email.h"

domain_list *approved_domains;

int hasAtChar(char *string) {
    return ( strchr(string, '@') != NULL);
}

void haveDomain(char *input) {
    if (approved_domains == NULL) {
        approved_domains = new_domain_list(input);
    } else {
        add_domain(approved_domains, input);
    }
    node *n = approved_domains->head;
    while (n) {
        printf("Approved DOmain: %s\n", n->domain);
        n = n->next;
    }
}

void parseOptions(const char *argv) {
    char *token, *string, *tofree;
    tofree = string = strdup(argv);
    if (string == NULL)
        err(1, "strdup");
    while ( (token = strsep(&string, "=")) != NULL) {
        if (strcmp(token, "domain") == 0) {
            haveDomain(string);
        }
    }
    free(tofree);
}

void print_pwent(struct passwd *pw) {
    printf("Name: %s\n", pw->pw_gecos);
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t * pamh,
                                int flags, int argc, const char **argv) {
    for (int i=0; i < argc; i++) {
        parseOptions(argv[i]);
    }
    struct passwd *pw = getpwuid(getuid());
    if (!hasAtChar(pw->pw_gecos)) {
        printf("It looks like we do not have your e-mail on file\n");
        printf("You passwd %i arguments.\n", argc);
        //char *email = readline("Please enter your e-mail address. ");
    } else {
        printf("We have your e-mail on file, thank you.");
    }
    return PAM_SUCCESS;
}
