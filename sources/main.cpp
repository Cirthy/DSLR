#include	"trainer.h"




int main()
{
	int 		size;
	Student* 	students;
    Range*      ranges;
	double      weights[4][14];

	size = get_size_of_datas(DATAS_PATHFILE);
	students = get_datas(size , DATAS_PATHFILE);
	ranges = get_range(students, size);
	normalize(students, size, ranges);

	init_weights(weights);
    for(int i = 0 ; i < ITERATIONS ; i++)
    {
    	printf("\ntour %d\n",i);
        improve_weights(weights, students, size);
        for(int w = 0 ; w < 14 ; w++)
        	printf("%lf\n", weights[0][w]);

    }
    unnormalize(weights, ranges);
    free(students);
    free(ranges);
	return 0;
}