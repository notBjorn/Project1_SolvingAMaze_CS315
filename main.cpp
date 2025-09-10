#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// The following is a helper function that lets me print an int vector in a format I desire.
void printVec(const std::vector<int> &printData ) {
    for (const int element: printData) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


// This is derivative helper function that prints a 2D vector
void printVecMaze(const std::vector<std::vector<int>> &printData ) {
    for (std::vector<int> aRow : printData) {
        printVec(aRow);
    }
}

int main() {
    std::ifstream file("./maze.txt");
    std::string line;
    std::vector<std::vector<int> > maze;

    if (!file.is_open()) {
        std::cout << "File not open" << std::endl;
    }
    std::vector<int> aRow;
    int row = 0;
    while (std::getline(file, line)) {
        //getting an extra 0 there for some reason, will diagnose that tomorrow.

        for (auto c: line) {
            aRow.push_back(c - '0');
            // - '0' converts char to int, learned this from the first search result on google...
        }
        std::cout << "This is the data in the vector" << std::endl;


        // The following code should push the temp vector and place it in the desired row of our 2D maze vector
        maze.push_back(aRow);
        aRow.clear(); // This will empty the temp vector for future use



        //printVec(maze[row]);

        row++;
    }

    printVecMaze(maze);

    file.close();
    return 0;
}
