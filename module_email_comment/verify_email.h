#ifndef VERIFY_EMAIL_C
#define VERIFY_EMAIL_C

#include <assert.h>
#include <err.h>
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
#include "domain_list.h"

#ifdef DEBUG
    #define D if (1)
#else
    #define D if (0)
#endif


#endif
