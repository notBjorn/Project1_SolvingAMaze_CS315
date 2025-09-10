#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// The following is a helper function that lets me print an int vector in a format I desire.
void printVec(const std::vector<int> &printData) {
    for (const int element: printData) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


// This is derivative helper function that prints a 2D vector
void printVecMaze(const std::vector<std::vector<int> > &printData) {
    for (std::vector<int> aRow: printData) {
        printVec(aRow);
    }
}


int main() {
    std::ifstream file("./maze.txt"); //input file, needs to be placed in the build directory won't run otherwise
    std::string line; // this will read and store the string output from the file line by line
    std::vector<std::vector<int> > maze; // 2D vector that stores our maze
    std::vector<int> aRow; // a helper vector which stores a row that is later pushed onto our main 2D vector

    // Checks whether the file is open or not
    if (!file.is_open()) {
        std::cout << "File not open" << std::endl;
    }

    //While there is a line in the file, keep running
    while (std::getline(file, line)) {
        for (auto c: line) {
            aRow.push_back(c - '0');
            // - '0' converts char to int, learned this from the first search result on google...
        }

        maze.push_back(aRow); // push the temp vector and place it in the desired row of our 2D maze vector
        aRow.clear(); // This will empty the temp vector for future use

        //printVec(maze[row]);
    }

    printVecMaze(maze);

    file.close();
    return 0;
}
