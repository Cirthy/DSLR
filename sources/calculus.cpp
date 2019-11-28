#include    "trainer.h"


double  cost(double* theta, Student* students, int m, House house)
{
    double  s;
    double  buf;

    s = 0;
    for(int i = 0 ; i < m ; i++)
    {
        buf = prob(theta, (students[i]).notes);
        if((students[i]).hogwartsHouse == house)
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


double  partial_derivative(int j, double* theta, Student* students, int m, House house)
{
    double  s;
    double  note;
    int     count;

    s = 0;
    for(int i = 0 ; i < m ; i++)
    {
        if(j == 0)
            note = 1;
        else
            note = (students[i]).notes[j];
        if(note == 0)
            count++;
        else
            s += ((prob(theta, (students[i]).notes)) - student_in_house(students[i], house)) * note;
    }
    return s / (m - count);
}
