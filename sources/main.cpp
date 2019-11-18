#include	<stdio.h>

#include	"trainer.h"




int main(int argc, char const *argv[])
{
	int 		size;
	student* 	students;
	double      weights[4][14];

	size = get_size_of_datas(DATAS_PATHFILE);
	students = get_datas(size , DATAS_PATHFILE);

	init_weights(weights);
    for(int i = 0 ; i < ITERATIONS ; i++)
        improve_weights();

	return 0;
}