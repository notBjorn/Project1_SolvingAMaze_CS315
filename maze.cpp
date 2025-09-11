//
// Created by Rishav Sharma on 9/10/25.
//

#include "maze.h"
void maze::importMaze(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;                        // used for reading file data
    std::vector<std::pair<int, bool> > aRow; // temp vector used to push data into the 2D vector

    // check wheter the file is open or not
    if (!file.is_open()) {
        std::cout << "File not open" << std::endl;
    }

    while (std::getline(file, line)) {
        for (auto c: line) {
            int data = c - '0';
            aRow.push_back({data, true});
            // - '0' converts char to int, learned this from the first search result on google...
        }

        vMaze.push_back(aRow); // push the temp vector and place it in the desired row of our 2D maze vector
        aRow.clear(); // This will empty the temp vector for future use

    }

    file.close();
}


void maze::printMaze() {
    for (std::vector<std::pair<int, bool> >
        &aRow: vMaze) {
        for (const std::pair element: aRow) {
            std::cout << element.first << " ";
        }
        std::cout << std::endl;
    }
}





