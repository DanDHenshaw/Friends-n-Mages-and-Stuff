#include <iostream>
#include "Game.h"

int main()
{
    BEGIN_SESSION(TITLE);

    Insignia::Game(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);

    END_SESSION();

    return EXIT_SUCCESS;
}