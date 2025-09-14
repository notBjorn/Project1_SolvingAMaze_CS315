//
// Created by Rishav Sharma on 9/10/25.
//

#include "maze.h"

void maze::importMaze(const std::string &filename) {
    std::ifstream file(filename);
    std::string line; // used for reading file data
    std::vector<std::pair<int, bool> > aRow; // temp vector used to push data into the 2D vector

    // check whether the file is open or not
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

    findKeyVariables();

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

// The following functions analyzes the maze vector to find all the key coordinates and variables like the start and end
// points of a maze, and what are the bounds of the maze.
void maze::findKeyVariables() {
    std::vector<std::pair<int, int> > openings; // temp vector with the openings

    if (vMaze.empty()) return;

    lastXIdx = vMaze[0].size() - 1;
    lastYIdx = vMaze.size() - 1;

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

    // The following statement checks whether we have enough data for start and end, if we do store the data into those variables.
    if (openings.size() >= 2) {
        start = openings.at(0);
        end = openings.at(1);
    } else {
        std::cout << "no valid start/end" << std::endl;
    }
}

// checks whether the coordinate is a path or not
bool maze::isPath(int x, int y) {
    if (vMaze[y][x].first == 1) return false;
    return true;
}

// checks if cell can be visited or not by checking if it has been visited before.
bool maze::canVisit(int x, int y) {
    if (vMaze[y][x].second) return true;
    return false;
}

// checks whether we can travel to the designated cell
bool maze::canTravel(int x, int y) {
    // Check whether the coordinates are pathable or not
    if (!isPath(x, y)) {
        return false;
    }
    // check out of bounds, I may create a separate function for this later
    if (x < 0 || x > lastXIdx) return false;
    if (y < 0 || y > lastYIdx) return false;

    // Check if the cell has been visited before or not
    if (!canVisit(x, y)) return false;

    return true;
}
