#include <iostream>
#include <vector>

void greet();
void display_board(std::vector<char> spaces);
std::vector<char> take_turn(bool player_one, std::vector<char> spaces);
bool check_board(std::vector<char> spaces);