#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
enum state { KEmpty, kObstacle, kClosed, kPath, kStart, kFinish };

#include "file-operations.h"

#include "search-function.h"

// --------------------------------------MAIN----------------------------------

int main(int argc, char const *argv[]) {
  vector<vector<state>> board = ReadBoardFile("input.txt");
  // setting start and finish points
  int start[] = {0, 0};
  int goal[] = {4, 5};
  // marking the start and finish points on the grid
  board[goal[0]][goal[1]] = state::kFinish;
  // PrintBoard(board);
  vector<vector<state>> solution = Search(start, goal, board);
  board[start[0]][start[1]] = state::kStart;
  PrintBoard(solution);
  return 0;
}

