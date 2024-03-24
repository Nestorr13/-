#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void readCoordinatesFromFile(const std::string& filename, std::vector<std::vector<int>>& coordinates) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> coords;
        std::istringstream iss(line);
        int coord;
        while (iss >> coord) {
            coords.push_back(coord);
        }
        coordinates.push_back(coords);
    }

    file.close();
}

void writeCoordinatesToFile(const std::string& filename, const std::vector<std::vector<int>>& coordinates) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (size_t i = 0; i < coordinates.size(); ++i) {
        for (size_t j = 0; j < coordinates[i].size(); ++j) {
            file << coordinates[i][j] << " ";
        }
        file << std::endl;
    }

    file.close();
}

int main() {
    std::vector<std::vector<int>> coordinates;
    readCoordinatesFromFile("input.txt", coordinates);

    std::vector<int> xCoords, yCoords;
    for (const auto& coordSet : coordinates) {
        for (size_t i = 0; i < coordSet.size(); ++i) {
            if (i % 2 == 0) {
                xCoords.push_back(coordSet[i]);
            } else {
                yCoords.push_back(coordSet[i]);
            }
        }
    }

    writeCoordinatesToFile("output.txt", {xCoords, yCoords});

    return 0;
}
