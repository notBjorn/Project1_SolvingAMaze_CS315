#include "maze.h"

int main() {
    std::cout << "START" << std::endl;
    maze aMaze;
    aMaze.importMaze("maze.txt");
    //std::cout << "importing Successful" << std::endl;
    aMaze.printMaze();
   // std::cout << "printing Successful" << std::endl;
    aMaze.solveMaze();
    //std::cout << "solving Successful" << std::endl;
    aMaze.printSolution();
    std::cout << "END" << std::endl;
}
