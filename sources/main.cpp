#include	"trainer.h"




int main(int argc, char const *argv[])
{
	int 		size;
	student* 	students;
	double      weights[4][14];

	size = get_size_of_datas(DATAS_PATHFILE);
	students = get_datas(size , DATAS_PATHFILE);
	normalize(students, size, ranges);

	init_weights(weights);
    for(int i = 0 ; i < ITERATIONS ; i++)
    {
    	printf("\ntour %d\n",i);
        improve_weights(weights, students, size);
        for(int w = 0 ; w < 14 ; w++)
        	printf("%lf\n", weights[0][w]);

    }
    unnomarlize(weights, ranges);

	return 0;
}