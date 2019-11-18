#include    "trainer.h"


double  cost(double* theta, student* students, int m, house house)
{
    double  s;
    double  buf;

    s = 0;
    for(int i = 0 ; i < m ; i++)
    {
        buf = prob(theta, (student[i]).notes);
        if((student[i]).house == house)
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
    double  note;

    if(j == 0)
        note = 1;
    else
        note = (student[i]).notes[j];
        note =
    s = 0;
    for(int i = 0 ; i < m ; i++)
        s += (prob(theta, note) - student_in_house(students[i], house) * note;
    return s / m;
}
