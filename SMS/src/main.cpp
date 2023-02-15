#include <iostream>
#include "Game.h"

int main()
{
    BEGINSESSION(TITLE);

    Insignia::Game(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);

    ENDSESSION();

    return EXIT_SUCCESS;
}