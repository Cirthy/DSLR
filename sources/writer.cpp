#include <iostream>
#include <fstream>

void write(double weights[4][14]) {
    std::ofstream file;
    file.open("resources/weights.csv");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 14; j++) {
            if (j > 0) {
                file << ";";
            }
            file << std::to_string(weights[i][j]);
        }
        file << "\n";
    }
    file.close();
}