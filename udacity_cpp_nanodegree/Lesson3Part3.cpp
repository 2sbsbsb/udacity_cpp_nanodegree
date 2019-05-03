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
    
    struct Node {
        int x;
        int y;
        int g;
        int h;
    };
    
    enum class State {kEmpty, kObstacle, kPath};
    
    
    // Function for comparing two students according
    // to given rules
    bool compareNodeByFValue(Node a, Node b)
    {
        // If total marks are not same then
        // returns true for higher total
        int a_f = a.g  + a.h;
        int b_f = b.g  + b.h;
        return a_f > b_f;
    }
    
    
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
    
    int Heuristic(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
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
        
        vector<Node> openNodes;
        Node node;
        vector<Node>::iterator iterator;
        node.x = init[0];
        node.y = init[1];
        node.g = 0;
        node.h = Heuristic(node.x,node.y,goal[0],goal[1]);
        openNodes.push_back(node);
        while (!openNodes.empty()) {
            sort(openNodes.begin(),openNodes.end(),compareNodeByFValue);
            iterator = openNodes.begin();
            Node currentNode = *iterator;
            // Remove this after replacing vector with dqueue
            openNodes.erase(iterator);
            grid[currentNode.x][currentNode.y] = State::kPath;
            if(currentNode.x == goal[0] && currentNode.y == goal[1]) {
                return grid;
            } else {
                vector<Node> neighbour = neighbour(currentNode,);
            }
            
        }
        
//        cout << "No path found!" << "\n";
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[i].size(); j++) {
//                Node node;
//                node.x = i;
//                node.y = j;
//                node.h = j;
//                openNodes.push_back(node);
//                State state = grid[i][j];
//                switch(state) {
//                    case State::kEmpty:
//                        grid[i][j] = State::kPath;
//                    default:
//                        ;
//                }
//            }
//            cout << "\n";
//        }
        return grid;
        //return std::vector<vector<State>> {};
    }
    
 
    
    string CellString(State cell) {
        switch(cell) {
            case State::kObstacle: return "⛰️   ";
            case State::kPath: return "1   ";
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
        // TODO: Declare 2D "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
        int init[2]{0, 0};
        int goal[2]{4, 5};
        
        auto board = ReadBoardFile("1.board");
        PrintBoard(board);
        // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
        auto solution = Search(board, init, goal);
        // TODO: Change the following line to pass "solution" to PrintBoard.
        PrintBoard(solution);
    }
    
}
