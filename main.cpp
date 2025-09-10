#include <iostream>
#include <fstream>
#include <vector>
#include <string>


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

        for (auto c : line) {
            aRow.push_back(c - '0'); // - '0' converts char to int, learned this from the first search result on google...
        }
        std::cout << "This is the data in the vector" << std::endl;


        // The following code should push the temp vector and place it in the desired row of our 2D maze vector
        maze.push_back(aRow);
        aRow.clear(); // This will empty the temp vector for future use

        // to see if the maze has the correct data

        for (auto i: maze[row]) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;

        row++;
    }

    file.close();
    return 0;
}
