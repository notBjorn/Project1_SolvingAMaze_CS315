#include "maze.h"

int main() {
    maze aMaze;
    aMaze.importMaze("../maze.txt");
    std::cout << "importing Successful" << std::endl;
    aMaze.printMaze();
    std::cout << "printing Successful" << std::endl;
    aMaze.solveMaze();
    std::cout << "solving Successful" << std::endl;
    aMaze.createSolutionMaze();
    std::cout << "solution maze creation Successful" << std::endl;
    aMaze.printSolution();
    std::cout << "Printing Solution Successful" << std::endl;
}
