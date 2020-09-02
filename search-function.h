// A*Search-----------------------------------

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open_list,
               vector<vector<state>> &grid) {
  vector<int> node = {x, y, g, h};
  open_list.push_back(node);
  // grid[x][y] = kClosed;
};

int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
};

bool compare(const vector<int> &a, const vector<int> &b) {
  if ((a[3] + a[4]) < (b[3] + b[4]))
    return false;
  else
    return true;
};

bool CheckValidCell(int x, int y, const vector<vector<state>> &grid) {
  // cout << "Checking Cell: " << x << ", " << y << endl;
  if ((x < grid.size() && y < grid[0].size())) {
    // cout << "grid.cellvalue is: " << grid[x][y] << endl;
    if ((grid[x][y] == KEmpty || grid[x][y] == kFinish)) {
      return true;
    }
  }
  return false;
};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

// TODO: use goal[] as reference here
void ExpandNeighbours(vector<int> &CurrentNode, vector<vector<int>> &open_list,
                      vector<vector<state>> &grid, int goal[]) {
  grid[CurrentNode[0]][CurrentNode[1]] = kPath;

  // int x = CurrentNode[0];
  // int y = CurrentNode[1];

  // add the expanded node as path

  // Loop through current node's potential neighbors
  for (size_t i = 0; i < 4; i++) {
    // Check that the potential neighbor's x2 and y2 values are on the grid and
    // not closed.
    int x2 = delta[i][0] + CurrentNode[0];
    int y2 = delta[i][1] + CurrentNode[1];
    if (CheckValidCell(x2, y2, grid)) {
      // cout << "Valid Cell : " << x2 << ", " << y2 << endl;

      // Increment g value, compute h value, and add neighbor to open
      int g = CurrentNode[2] + 1;
      int h = Heuristic(x2, y2, goal[0], goal[1]);
      AddToOpen(x2, y2, g, h, open_list, grid);
    }
  }
};

vector<vector<state>> Search(int start[], int goal[],
                             vector<vector<state>> &grid) {
  // create a list of open nodes to keep track of unvisited places
  vector<vector<int>> open_nodes;
  // creating a node with start values to begin with
  int x = start[0];
  int y = start[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);
  // adding the node to open list
  AddToOpen(x, y, g, h, open_nodes, grid);
  // while the list is not empty
  while (open_nodes.size() != 0) {
    // sort the list (decreasing order)
    sort(open_nodes.begin(), open_nodes.end(), compare);
    // this is the smallest value of g + h in the list
    vector<int> CurrentNode = open_nodes.back();
    // remove the node from the list
    open_nodes.pop_back();
    int x1 = CurrentNode[0]; // get  x and y coordinates from current node
    int y1 = CurrentNode[1];
    // grid[CurrentNode[0]][CurrentNode[1]] = kPath;
    if (x1 == goal[0] && y1 == goal[1]) {
      return grid;
    } else {
      ExpandNeighbours(CurrentNode, open_nodes, grid, goal);
    }
  }
  cout << "No path found" << '\n';
  return grid;
};