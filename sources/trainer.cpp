#include 	"trainer.h"

void    improve_weights(double weights[4][14], Student* students, int m)
{
    for(int h = 0 ; h < 4 ; h++)
        improve_thetas(weights[h], students, m, (House)h);
}

void    improve_thetas(double thetas[14], Student* students, int m, House house)
{
    double  tmp[14];
    int     i;

    for(i = 0 ; i < 14 ; i++)
        tmp[i] = thetas[i];
    for(i = 0 ; i < 14 ; i++)
        thetas[i] -= LEARNING_RATE * partial_derivative(i, tmp, students, m, house);
}
