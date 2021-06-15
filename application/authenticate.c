#include "includes.h"
#include "authenticate.h"


int test_conv(int num_msg, const struct pam_message **msg,
              struct pam_response **resp, void *appdata_ptr) {
    const struct pam_message *msg_ptr = *msg;
    struct pam_response *resp_ptr = NULL;
    int x = 0;
    *resp = calloc(sizeof(struct pam_response), num_msg);
    for (x = 0; x < num_msg; x++, msg_ptr++) {
        char *resp_str;
        switch (msg_ptr->msg_style) {
        case PAM_PROMPT_ECHO_OFF:
        case PAM_PROMPT_ECHO_ON:
            resp_str = getpass(msg_ptr->msg);
            resp[x]->resp = strdup(resp_str);
            break;
        case PAM_ERROR_MSG:
        case PAM_TEXT_INFO:
            printf("Error (Conversion Function) Line: %i,%s\n", __LINE__,
                   msg_ptr->msg);
            break;
        default:
            assert(0);
        }
    }
    return PAM_SUCCESS;
}


int authenticate(char *user, char *service) {
    struct pam_conv conv;
    conv.conv = test_conv;
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
