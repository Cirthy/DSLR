#include 	"trainer.h"


void 		get_string_until_comma(FILE* const fd , char* str)
{
	char 	c;
	int 	i = 0;
	do{
		fscanf(fd, "%c", &c);
		str[i] = c;
		i++;
	}while (c != ',');
	str[i-1] = '\0';
}


void 		print_house(student* const s)
{
	switch (s->hogwartsHouse)
	{
		case Ravenclaw :
			printf("Ravenclaw");
			break;
		case Slytherin :
			printf("Slytherin");
			break;
		case Gryffindor :
			printf("Gryffindor");
			break;
		case Hufflepuff :
			printf("Hufflepuff");
			break;
	}
}

void 		print_best_hand(student* const s)
{
	switch (s->bestHand)
	{
		case Left :
			printf("Left");
			break;
		case Right :
			printf("Right");
			break;
	}
}


void 		print_birthday_date(student* const s)
{
	printf("Born the %d ", s->birthday.day);
	switch ((s->birthday).month)
	{
		case 1 :
			printf("january");
			break;
		case 2 :
			printf("february");
			break;
		case 3 :
			printf("march");
			break;
		case 4 :
			printf("april");
			break;
		case 5 :
			printf("may");
			break;
		case 6 :
			printf("june");
			break;
		case 7 :
			printf("july");
			break;
		case 8 :
			printf("august");
			break;
		case 9 :
			printf("september");
			break;
		case 10 :
			printf("october");
			break;
		case 11 :
			printf("november");
			break;
		case 12 :
			printf("december");
			break;
	}
	printf(" %d.", s->birthday.year);
}