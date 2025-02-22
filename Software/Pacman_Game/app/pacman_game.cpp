
#include "pacman_game_logic.h"
#include "environment.h"
#include "ui.h"

int main()
{
    UI ui;

    PacmanGameLogic gameLogic;

    Input input;
    Environment env;

    // while (game != game_over && ui.window_not_closed)
    while ((gameLogic.isGameOver() == false) && (ui.isTerminated() == false))
    {
        // inputs = ui.getInputs()
        input = Input::NoInput;

        // outputs = game_logic.udpate(const inputs& in)
        gameLogic.update(&env, input);

        // ui.render(outputs)
        ui.render();
    }
    return 0;
}