#include	"trainer.h"



double min(Student* students, int size, Features feature)
{
	double 	min = students[0].notes[feature];
	for(int i = 0 ; i < size ; i++)
		if (students[i].notes[feature]!=0.0 && students[i].notes[feature] < min) {
            min = students[i].notes[feature];
        }
	return min;
}

double max(Student* students, int size, Features feature)
{
	double 	max = students[0].notes[feature];
	for(int i = 0 ; i < size ; i++)
		if (students[i].notes[feature]!=0.0 && students[i].notes[feature] > max)
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

double count(Student* students, int size, Features feature)
{
	return size;
}
 */

double mean(Student* students, int size, Features feature)
{
	double 	sum = 0.0;

	for(int i = 0 ; i < size ; i++)
		sum += students[i].notes[feature];

	return sum / size;
}

double std_d(Student* students, int size, Features feature)
{
	float 	sum = 0.0;
	float 	m = mean(students, size, feature);

	for(int i = 0 ; i < size ; i++)
		sum += (students[i].notes[feature] - m) * (students[i].notes[feature] - m);
	sum /= size;
	return sqrt(sum);
}

double     student_in_house(Student student, House house)
{
    return (student.hogwartsHouse == house) ? 1.0 : 0.0;
}

Range		*get_range(Student * students, int size) {
	Range *ranges;
    ranges = (Range *)malloc(13 * sizeof(Range));

	for (int i = 0; i < 13; i++) {
		ranges[i].min = min(students, size, (Features)i);
		ranges[i].max = max(students, size, (Features)i);
	}

	return ranges;
}

void		normalize(Student* students, int m, Range *ranges)
{
	for(int i = 0 ; i < m ; i++)
		for(int j = 0 ; j < 13 ; j++)
			(students[i]).notes[j] = ((students[i]).notes[j] - ranges[j].min) / (ranges[j].max - ranges[j].min);
}


void		unnormalize(double weights[4][14], Range * ranges)
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
			weights[i][0] -= tmp[i][j] * ranges[j].min / (ranges[j].max - ranges[j].min);
			if (j > 0)
			weights[i][j] = tmp[i][j] / (ranges[j].max - ranges[j].min);
		}
	}
}