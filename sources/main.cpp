#include	"trainer.h"




int main(int argc, char const *argv[])
{
	int 		size;
	student* 	students;



	size = get_size_of_datas(DATAS_PATHFILE);
	students = get_datas(size , DATAS_PATHFILE);


	//printf("Student number : %d\n", size);

	print_student(&(students[size-1]));

	//printf("")



	return 0;
}