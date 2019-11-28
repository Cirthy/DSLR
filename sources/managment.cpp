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


void        init_weights(double weights[4][14])
{
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 14 ; j++)
            weights[i][j] = 0;
}


void 		print_house(Student* const s)
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


void 		print_best_hand(Student* const s)
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


void 		print_birthday_date(Student* const s)
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


void 		print_student(Student* const s)
{
	printf("%s %s\n",s->firstName,s->lastName);
	print_house(s);
	
	printf("\nschool notes :\n");
	printf("                   Arithmancy : %f\n" , s->notes[Arithmancy]);
	printf("                    Astronomy : %f\n" , s->notes[Astronomy]);
	printf("                    Herbology : %f\n" , s->notes[Herbology]);
	printf("Defense Against the Dark Arts : %f\n" , s->notes[DefenseAgainstTheDarkArts]);
	printf("                   Divination : %f\n" , s->notes[Divination]);
	printf("               Muggle Studies : %f\n" , s->notes[MuggleStudies]);
	printf("                Ancient Runes : %f\n" , s->notes[AncientRunes]);
	printf("             History of Magic : %f\n" , s->notes[HistoryOfMagic]);
	printf("              Transfiguration : %f\n" , s->notes[Transfiguration]);
	printf("                      Potions : %f\n" , s->notes[Potions]);
	printf("    Care of Magical Creatures : %f\n" , s->notes[CareOfMagicalCreatures]);
	printf("                       Charms : %f\n" , s->notes[Charms]);
	printf("                       Flying : %f\n" , s->notes[Flying]);
}