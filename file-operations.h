/* 
  Converts input string to a vector of integers/states
  Input: String str
  Return type: Vector
  Return Value: vector<state> values
  */
vector<state> ParseLine(const string str) {
  istringstream read_stream(str);
  int value;
  vector<state> temp_data;
  while (read_stream >> value) {
    temp_data.push_back((state)value);
  }
  return temp_data;
};

/*
  Converts input file as a std::vector of std::vector<enum> values
  Input: str filename
  Return type: std::vector<std::vector <enum>>
  Return Value: std::vector<std::vector <enum>> board
  */
vector<vector<state>> ReadBoardFile(const string &file_name) {
  vector<vector<state>> board;
  ifstream infile;
  infile.open(file_name);
  string value;
  while (getline(infile, value)) {
    board.push_back(ParseLine(value));
  }
  infile.close();
  return board;
};

/*
  Returns a string character based on the input enum
  Input: enum::state val
  Return Value:  string str
  */
string CellString(const state &val) {
  switch (val) {
  case kObstacle:
    return "⛰️ ";
    break;
  case KEmpty:
    return "0 ";
    break;
  case kClosed:
    return "X ";
    break;
  case kPath:
    return "🚗 ";
  case kStart:
    return "🚦 ";
    break;
  case kFinish:
    return "🏁 ";
    break;
  default:
    return "Error";
    break;
  }
};

// Might need to change the parameter taken as input
void PrintBoard(const vector<vector<state>> &board) {
  for (auto it = board.begin(); it != board.end(); it++) {
    for (auto jt = (*it).begin(); jt != (*it).end(); jt++) {
      cout << CellString((state)*jt) << " ";
    }
    cout << endl;
  }
};