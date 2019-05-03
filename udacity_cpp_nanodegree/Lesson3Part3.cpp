//
//  Lesson3Part3.cpp
//  udacityCplusplusNanoDegree
//
//  Created by Santosh Bhushan on 5/3/19.
//  Copyright © 2019 sb. All rights reserved.
//

#include "Lesson3Part3.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;


namespace Lesson3Part3 {
    
    
enum class State {kEmpty, kObstacle};


vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
        if (n == 0) {
            row.push_back(State::kEmpty);
        } else {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path) {
    ifstream myfile (path);
    vector<vector<State>> board{};
    if (myfile) {
        string line;
        while (getline(myfile, line)) {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

// TODO: Write the Search function stub here.
/**
 * Implementation of A* search algorithm
 Search( grid, initial_point, goal_point ) :
 
 Initialize an empty list of open nodes.
 Initialize a starting node with the following:
 
 x and y values given by initial_point.
 g = 0, where g is the cost for each move.
 h given by the heuristic function (a function of the current coordinates and the goal).
 Add the new node to the list of open nodes.
 while the list of open nodes is nonempty:
 
 Sort the open list by f-value and pop the optimal cell (called the current cell).
 Mark the cell's coordinates in the grid as part of the path.
 if the current cell is the goal cell:
 
 return the grid.
 else, expand the search to the current node's neighbors. This includes the following steps:
 
 Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
 If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
 Mark the cell as closed.
 If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.
 */
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
    cout << "No path found!" << "\n";
    return std::vector<vector<State>> {};
}

string CellString(State cell) {
    switch(cell) {
        case State::kObstacle: return "⛰️   ";
        default: return "0   ";
    }
}


void PrintBoard(const vector<vector<State>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}


void run() {
    int init[2]{0, 0};
    int goal[2]{4, 5};
    auto board = ReadBoardFile("1.board");
    PrintBoard(board);
    auto solution = Search(board, init, goal);
    PrintBoard(solution);
    
    // TODO: Declare 2D "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
    // auto board = ReadBoardFile("1.board");
    // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
    // TODO: Change the following line to pass "solution" to PrintBoard.
    // PrintBoard(board);
}

}
