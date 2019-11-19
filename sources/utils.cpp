#include	"trainer.h"



double min(student* students, int size, features feature)
{
	double 	min = students[0].notes[feature];
	for(int i = 0 ; i < size ; i++)
		if (students[i].notes[feature] < min)
			min = students[i].notes[feature];
	return min;
}

double max(student* students, int size, features feature)
{
	double 	max = students[0].notes[feature];
	for(int i = 0 ; i < size ; i++)
		if (students[i].notes[feature] > max)
			max = students[i].notes[feature];
	return max;
}

/*
float first_qt(float * sorted, int size) {
	int qt_index = size / 4;

	return sorted[qt_index];
}

float second_qt(float * sorted, int size) {
	int qt_index = size / 2;

	return sorted[qt_index];
}

float third_qt(float * sorted, int size) {
	int qt_index = size * 3 / 4;

	return sorted[qt_index]
}
*/


double count(student* students, int size, features feature)
{
	return size; 
}

double mean(student* students, int size, features feature)
{
	double 	sum = 0.0;

	for(int i = 0 ; i < size ; i++)
		sum += students[i].notes[feature];

	return sum / size;
}

double std_d(student* students, int size, features feature)
{
	float 	sum = 0.0;
	float 	m = mean(students, size, feature);

	for(int i = 0 ; i < size ; i++)
		sum += (students[i].notes[feature] - m) * (students[i].notes[feature] - m);
	sum /= size;
	return sqrt(sum);
}

double     student_in_house(student student, house house)
{
    return (student.hogwartsHouse == house) ? 1.0 : 0.0;
}


void		normalize(student* students, int m, double ranges[2][13])
{
	for(int i = 0 ; i < m ; i++)
		for(int j = 0 ; j < 13 ; j++)
			((students[i]).notes[j] = (students[i]).notes[j] - ranges[0][i]) / (ranges[1][i] - ranges[0][i]);
}


void		unnormalize(double weights[4][14], double ranges[2][13])
{
	double	tmp[4][14];
	int		i;
	int		j;

	for(i = 0 ; i < 4 ; i++)
		for(j = 0 ; j < 14 ; j++)
			tmp[i][j] = weights[i][j];

	for(i = 0 ; i < 4 ; i++)
	{
		weights[i][0] = tmp[i][0];
		for(j = 1 ; j < 14 ; j++)
		{
			weights[i][0] -= tmp[i][j] * ranges[0][i] / (ranges[1][i] - ranges[0][i]);
			weights[i][j] = tmp[i][j] / (ranges[1][i] - ranges[0][i]);
		}
	}
}