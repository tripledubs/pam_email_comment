#include <assert.h>
#include "includes.h"

int launch() {
    coordinates *coords = getCoordsFromUser();
    launchNuke(coords);
}

int main(int argc, char *argv[]) {
    if ((authenticate("dubs", "nukes") == PAM_SUCCESS)) {
        launch();
    }
}
