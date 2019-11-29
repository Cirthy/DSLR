#include "trainer.h"

House       estimate_house(Student student, std::vector<std::vector<double>> weights) {
    double probas[4];
    double thetas[14];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 14; j++) {
            thetas[j] = weights[i][j];
        }
        probas[i] = prob(thetas, student.notes);
    }

    double tmp = 0;
    int l = -1;
    for(int k = 0; k < 4; k++) {
        if(tmp < probas[k]) {
            tmp = probas[k];
            l = k;
        }
    }

    return (House)l;
}