#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H

#include "includes.h"

int test_conv(int num_msg, const struct pam_message **msg,
              struct pam_response **resp, void *appdata_ptr) ;

int authenticate(char *user, char *service) ;

#endif


