#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>


#include <readline/readline.h>

#ifdef DEBUG
#define D if (1)
#else
#define D if (0)
#endif

bool confirm(char *answer) {
    printf("Does this look correct? '%s'\n", answer);
    char confirm = getchar();
    if (confirm == 'Y' || confirm == 'y') {
        return true;
    }
    return false;
}

int hasAtChar(char *string) {
    char *looker = strdup(string);
    bool found = false;
    while (*looker && !found) {
        if (*looker == '@') {
            found = true;
        }
        looker++;
    }
    free(looker);
    return found;
}

int getDomain

int print_pwent(struct passwd *pw) {
    printf("Name: %s\n", pw->pw_gecos);
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t * pamh,
                                int flags, int argc, const char **argv) {
    struct passwd *pw = getpwuid(getuid());
    if (!hasAtChar(pw->pw_gecos)) {
        printf("It looks like we do not have your e-mail on file\n");
        char *email = readline("Please enter your e-mail address. ");
    } else {
        printf("We have your e-mail on file, thank you.");
    }
    return PAM_SUCCESS;
}
