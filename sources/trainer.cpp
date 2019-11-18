#include 	<stdio.h>
#include 	<stdlib.h>

#include 	"trainer.h"



void 		print_student(student* const s)
{
	printf("%s %s\n",s->firstName,s->lastName);
	print_house(s);
	
	printf("\nschool notes :\n");
	printf("                   Arithmancy : %f\n" , s->notes[arithmancy]);
	printf("                    Astronomy : %f\n" , s->notes[astronomy]);
	printf("                    Herbology : %f\n" , s->notes[herbology]);
	printf("Defense Against the Dark Arts : %f\n" , s->notes[defenseAgainstTheDarkArts]);
	printf("                   Divination : %f\n" , s->notes[divination]);
	printf("               Muggle Studies : %f\n" , s->notes[muggleStudies]);
	printf("                Ancient Runes : %f\n" , s->notes[ancientRunes]);
	printf("             History of Magic : %f\n" , s->notes[historyOfMagic]);
	printf("              Transfiguration : %f\n" , s->notes[transfiguration]);
	printf("                      Potions : %f\n" , s->notes[potions]);
	printf("    Care of Magical Creatures : %f\n" , s->notes[careOfMagicalCreatures]);
	printf("                       Charms : %f\n" , s->notes[charms]);
	printf("                       Flying : %f\n" , s->notes[flying]);
}


student* 	get_datas(int const size , const char* const fileName)
{
	FILE* 		fd=NULL;
	int 		index;
	char 		bestHand[6];
	char 		hogwartsHouse[11];
	student*	datas;

	fd = fopen(fileName, "r");
	if (not fd)
		return NULL;

	datas = (student*)malloc(size*sizeof(student));

	fscanf(fd, "Index,Hogwarts House,First Name,Last Name,Birthday,Best Hand,Arithmancy,Astronomy,Herbology,Defense Against the Dark Arts,Divination,Muggle Studies,Ancient Runes,History of Magic,Transfiguration,Potions,Care of Magical Creatures,Charms,Flying\n");
	for(int i = 0 ; i < size ; i++)
	{
		fscanf(fd , "%d,"  , &index);
 		get_string_until_comma(fd , hogwartsHouse);
 		get_string_until_comma(fd , datas[i].firstName);
 		get_string_until_comma(fd , datas[i].lastName);
		fscanf(fd , "%d-"  , &(datas[i].birthday.year));
		fscanf(fd , "%d-"  , &(datas[i].birthday.month));
		fscanf(fd , "%d,"  , &(datas[i].birthday.day));
 		get_string_until_comma(fd , bestHand);
		fscanf(fd , "%lf,"  , &(datas[i].notes[arithmancy]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[astronomy]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[herbology]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[defenseAgainstTheDarkArts]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[divination]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[muggleStudies]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[ancientRunes]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[historyOfMagic]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[transfiguration]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[potions]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[careOfMagicalCreatures]));
		fscanf(fd , "%lf,"  , &(datas[i].notes[charms]));
		fscanf(fd , "%lf\n" , &(datas[i].notes[flying]));

		switch (hogwartsHouse[0])
		{
			case 'R' :
				datas[i].hogwartsHouse = Ravenclaw;
				break;
			case 'S' :
				datas[i].hogwartsHouse = Slytherin;
				break;
			case 'G' :
				datas[i].hogwartsHouse = Gryffindor;
				break;
			case 'H' :
				datas[i].hogwartsHouse = Hufflepuff;
				break;
			default:
				printf("Error in get_datas at student %d to set Hogwarts house.\n" , i);
				break;
		}

		switch (bestHand[0])
		{
			case 'R' :
				datas[i].bestHand = Right;
				break;
			case 'L' :
				datas[i].bestHand = Left;
				break;
			default:
				printf("Error in get_datas at student %d to set best hand.\n" , i);
				break;
		}
	}
	fclose(fd);

	return datas;
}

int 		get_size_of_datas(const char* const fileName)
{
	FILE* 	fd=NULL;
	char 	c;
	int 	size = -1;

	fd = fopen(fileName, "r");
	if (not fd)
		return 0;

	while ((c = fgetc(fd)) != EOF)
		if (c=='\n')
			size++;

	fclose(fd);
	return size;
}

