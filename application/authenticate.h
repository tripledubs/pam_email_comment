#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include <stdio.h>
#include <sys/types.h>
#include <security/pam_appl.h>
#include <security/openpam.h>

int authenticate(char *user, char *service) ;

#endif


