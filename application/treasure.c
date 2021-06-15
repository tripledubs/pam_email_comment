#include "treasure.h"

coordinates *coordinates_new(double lat, double longitude) {
    coordinates *this = malloc(sizeof(coordinates));
    this->latitude = lat;
    this->longitude = longitude;
    return this;
}

void getTreasure(coordinates * donefor) {
    printf("Received Treasure From %g %g.\n", donefor->latitude, donefor->longitude);
}

coordinates *getCoordsFromUser() {
    char *latitude = readline("Please enter latitude: ");
    char *longitude = readline("Please enter longitude: ");
    double dlat = strtod(latitude, NULL);
    double dlong = strtod(longitude, NULL);
    free(latitude);
    free(longitude);
    coordinates *c = coordinates_new(dlat, dlong);
    return c;
}
