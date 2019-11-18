#include    "trainer.h"


double  cost(double* theta, student* students, int m, house house)
{
    double  s;
    double  buf;

    s = 0;
    for(int i = 0 ; i < n ; i++)
    {
        buf = prob(theta, student->notes);
        if(student->house == house)
            s += log(buf);
        else
            s += log(1 - buf);
    }
    return -s / m;
}


double  prob(double* theta, double notes[13])
{
    double  p;

    p = theta[0];
    for(int i = 0 ; i < 13 ; i++)
        p += theta[i + 1] * notes[i];
    return 1 / 1 + exp(-p);
}


double  partial_derivative(int j, double* theta, student* students, int m, house house)
{
    double  s;

    s = 0;
    for(int i = 0 ; i < m ; i++)
        s += (prob(theta, student->notes) - ((students->house == house) ? 1 : 0)) * student->notes[j];
    return s / m;
}