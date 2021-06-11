#ifndef NUKES_H
#define NUKES_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>

typedef struct coordinates {
    double latitude;
    double longitude;
} coordinates;

coordinates *
coordinates_new(double x, double y);

coordinates *
getCoordsFromUser();

void
launchNuke(coordinates *donefor);

#endif
