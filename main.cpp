#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // for pair
#include <string>
// The following is a helper function that lets me print an int vector in a format I desire.
void printVec(const std::vector<std::pair<int, bool> > &printData) {
    for (const std::pair element: printData) {
        std::cout << element.first << " ";
    }
    std::cout << std::endl;
}

// This is derivative helper function that prints a 2D vector
void printVecMaze(const std::vector<std::vector<std::pair<int, bool> >> &printData) {
    for (std::vector<std::pair<int, bool> > aRow: printData) {
        printVec(aRow);
    }
}


int main() {
    std::ifstream file("./maze.txt"); //input file, needs to be placed in the build directory won't run otherwise
    std::string line; // this will read and store the string output from the file line by line
    std::vector<std::vector<std::pair<int, bool> > > maze;
    // 2D vector that stores our maze and wheter a cell has been transversed or not
    std::vector<std::pair<int, bool> > aRow;
    // a helper vector which stores a row that is later pushed onto our main 2D vector

    // Checks whether the file is open or not
    if (!file.is_open()) {
        std::cout << "File not open" << std::endl;
    }

    //While there is a line in the file, keep running
    while (std::getline(file, line)) {
        for (auto c: line) {
            int data = c - '0';
            aRow.push_back({data, true});
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

/*
 *
 * The data type needs to be a vector otherwise it will be hard to traverse the maze
 * Each cell of the maze grid will need 4 data points,
 * - The position data which will be provided by the vector position itself
 * - The type of cell it is will be defined by the data in the vector, if it is a 0 it means its pathable, if it is 1 it means it is a wall
 * - The history of the cell is also needed, meaning we need to know whether we have been to the cell or not.
 *
 * The problem right now is that I can't think of a way to dynamically insert all this data.
 * The only way I have in mind is to create a 2D vector with the contents of the maze and position
 * Then copy it over to a new maze, whose size we know because I know what the size of the 2D vector is.
 * Doing so will help me insert the default state of the cell which is that the cell has not been transversed
 */
