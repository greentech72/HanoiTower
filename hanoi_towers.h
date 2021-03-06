#ifndef HANOI_TOWERS_H
#define HANOI_TOWERS_H

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

vector<string> res;
vector<stack<int>> pins;
int disk_am;

vector<string> generate_moves(int amount);
void do_move(vector<stack<int>>* pins, string move);
vector<stack<int>> generate_pins(int amount);

#endif // HANOI_TOWERS_H

