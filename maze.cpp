//
// Created by Rishav Sharma on 9/10/25.
//

#include "maze.h"

void maze::importMaze(const std::string &filename) {
    std::ifstream file(filename);
    std::string line; // used for reading file data
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

    findOpening();

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
    std::cout << std::endl;
}

void maze::findOpening() {
    if (vMaze.empty())
        return;

    int lastXIdx = vMaze[0].size() - 1;
    int lastYIdx = vMaze.size() - 1;

    // This loops checks if there is a pathable cell in the top or bottom row, if there is one then it pushes it onto the openings vector
    for (int i = 0; i <= lastXIdx; i++) {
        if (isPath(i, 0)) {
            openings.push_back({i, 0});
        }

        if (isPath(i, lastYIdx)) {
            openings.push_back({i, lastYIdx});
        }
    }

    // This loops checks if there is a pathable cell in the left or right column, if there is one then it pushes it onto the opening vector.
    for (int i = 0; i <= lastYIdx; i++) {
        if (isPath(0, i)) {
            openings.push_back({0, i});
        }
        if (isPath(lastXIdx, i)) {
            openings.push_back({lastXIdx, i});
        }
    }
}

// index as the input
bool maze::isPath(int x, int y) {
    if (vMaze[y][x].first == 1)
        return false;
    else if (vMaze[y][x].first == 0)
        return true;
}


void maze::printOpen() {
    for (std::pair<int, int> i: openings) {
        std::cout << i.first << ", " << i.second << std::endl;
    }
}
