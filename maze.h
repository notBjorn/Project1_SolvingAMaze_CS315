//
// Created by Rishav Sharma on 9/10/25.
//
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // for pair
#include <string>


class maze {
public:
    void importMaze(const std::string& filename);// a function to translate the text file to maze file
    void printMaze(); // print the mazeeee
    // a helper function to find the index of entry/exit
    // a helper function that knows where to travel
private:
    std::vector<std::vector<std::pair<int, bool> > > vMaze;// the vector that will store the maze
};