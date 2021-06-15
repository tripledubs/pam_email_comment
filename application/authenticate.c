#include <stdio.h>
#include <sys/types.h>
#include <security/pam_appl.h>
#include <security/openpam.h>

int authenticate(char *user, char *service) {
    struct pam_conv conv;
    conv.conv = openpam_ttyconv;
    struct pam_handle_t *pamh;
    int retval = pam_start(service, user, &conv, &pamh);
    if (retval != PAM_SUCCESS) {
        pam_strerror(pamh, retval);
    }
    retval = pam_authenticate(pamh, 0);
    switch (retval) {
    case PAM_SUCCESS: {
        int acct = pam_acct_mgmt(pamh, retval);
        return acct;
    }
    case PAM_AUTH_ERR:
        printf("%s\n", pam_strerror(pamh, retval));
        break;
    default:
        printf("%s\n", pam_strerror(pamh, retval));
        break;
    }
}
