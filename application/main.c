#include <assert.h>
#include "includes.h"

int launch() {
    coordinates *coords = getCoordsFromUser();
    getTreasure(coords);
}

int main(int argc, char *argv[]) {
    if ((authenticate("dubs", "nukes") == PAM_SUCCESS)) {
        launch();
    }
}
