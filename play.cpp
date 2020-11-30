#include <iostream>
#include <vector>

void greet() {

  std::cout << "=============\n";
  std::cout << "Tic Tac Toe\n";
  std::cout << "=============\n";
  std::cout << "Instructions: Take turns placing an X or an O on the board. The first player to get three in a row wins!\n";

}


void display_board(std::vector<char> spaces) {

    std::cout << "===================\n";
    std::cout << "|   Tic Tac Toe   |\n";
    std::cout << "===================\n";
    std::cout << "|1    |2    |3    |\n";
    std::cout << "|  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  |\n";
    std::cout << "|     |     |     |\n";
    std::cout << "+-----+-----+-----+\n";
    std::cout << "|4    |5    |6    |\n";
    std::cout << "|  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  |\n";
    std::cout << "|     |     |     |\n";
    std::cout << "+-----+-----+-----+\n";
    std::cout << "|7    |8    |9    |\n";
    std::cout << "|  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  |\n";
    std::cout << "|     |     |     |\n";
    std::cout << "-------------------\n";

}

std::vector<char> take_turn(bool player_one, std::vector<char> spaces) {
    
    int space;
    bool valid_space = false;

    if (player_one) {
        std::cout << "Player One's turn.\n";
    } else {
        std::cout << "Player Two's turn.\n";
    }

    while (!valid_space) {
        std::cout << "Choose a space: ";
        std::cin >> space;
        std::cout << "\n";

        if (space >= 1 && space <= 9 && spaces[space-1] == ' ') {
            if (player_one) {
                spaces[space-1] = 'O';
            } else {
                spaces[space-1] = 'X';
            }
            valid_space = true;
        }
    }    

    return spaces;

}

bool check_board(std::vector<char> spaces) {

    bool game_over = false;
    bool empty_space = false;
    for (int i=0; i<spaces.size(); i++) {
        if (spaces[i]==' ') {
            empty_space = true;
        }
    }

    std::vector<std::vector<int>> winning_layouts = { {0,1,2}, {0,4,8}, {0,3,6}, {1,4,7},
                                                      {2,5,8}, {3,4,5}, {6,7,8}, {2,4,6} };
    bool player_one_win = false;
    bool player_two_win = false;

    for (int i=0; i<winning_layouts.size(); i++) {
        if (spaces[winning_layouts[i][0]]=='O' && spaces[winning_layouts[i][1]]=='O' && spaces[winning_layouts[i][2]]=='O') {
            player_one_win = true;
        } else if (spaces[winning_layouts[i][0]]=='X' && spaces[winning_layouts[i][1]]=='X' && spaces[winning_layouts[i][2]]=='X') {
            player_two_win = true;
        }
    }

    if (player_one_win) {
        display_board(spaces);
        std::cout << "Hooray! Player One wins!\n";
        game_over = true;
    } else if (player_two_win) {
        display_board(spaces);
        std::cout << "Hooray! Player Two wins!\n";
        game_over = true;
    } else if (!empty_space) {
        display_board(spaces);
        std::cout << "You are out of spaces. Game over.\n";
        game_over = true;
    }

    return game_over;
    
}