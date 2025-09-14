//
// Created by Rishav Sharma on 9/10/25.
//
#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <utility> // for pair
#include <string>


class maze {
public:
    void importMaze(const std::string &filename); // a function to translate the text file to maze file
    void printMaze(); // print the mazeeee
    void solveMaze();
    void createSolutionMaze();
    void printSolution();

    // a helper function to find the index of entry/exit
    // a helper function that knows where to travel
private:
    std::vector<std::vector<std::pair<int, bool> > > primeMaze; // the vector that will store the maze
    std::vector<std::vector<char> > solvedMaze;
    std::stack<std::pair<int, int>> path;
    std::size_t lastXIdx,  lastYIdx;
    std::pair<int, int> start = {-1, -1};
    std::pair<int, int> end = {-1, -1};


    void markVisited(int, int);
    bool isPath(int, int); // a helper function that lets us check if the cell is pathable or not
    bool canTravel (int, int);
    bool canVisit(int, int);
    void findKeyVariables();  // a helper functions that goes through the maze and finds the key variables in the maze
    bool inBounds(int x, int y) const;
};
