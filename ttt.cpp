#include <iostream>
#include "play.hpp"

int main() {
    bool game_over = false;
    std::vector<char> spaces = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool player_one = true;

    greet();

    while (!game_over) {
        display_board(spaces);

        spaces = take_turn(player_one, spaces);

        if (player_one) {
            player_one = false;
        } else {
            player_one = true;
        }

        game_over = check_board(spaces);

    }

}