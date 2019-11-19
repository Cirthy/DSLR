#ifndef 	__TRAINER_H__
#define 	__TRAINER_H__

#define 	DATAS_PATHFILE 		"../resources/dataset_train.csv"
#define     ITERATIONS      10
#define     LEARNING_RATE   0.1


#include    <math.h>
#include    <stdio.h>
#include    <stdlib.h>


typedef enum hand 		{ Right , Left } hand;
typedef enum house 		{ Ravenclaw = 0 , Slytherin , Gryffindor , Hufflepuff } house;
typedef enum features 	{ arithmancy , astronomy , herbology , defenseAgainstTheDarkArts , divination , muggleStudies , ancientRunes , historyOfMagic , transfiguration , potions , careOfMagicalCreatures , charms , flying } features;

typedef struct date
{
	int 	day;
	int 	month;
	int 	year;
}date;

typedef struct student
{
	house 	hogwartsHouse;
	char 	firstName[21];
	char 	lastName[21];
	date 	birthday;
	hand 	bestHand;
	double 	notes[13];
} student;



// MANAGMENT.CPP //////////

void 		get_string_until_comma(FILE* const fd , char* str);
void        init_weights(double weights[4][14]);
void 		print_house(student* const s);
void 		print_best_hand(student* const s);
void 		print_birthday_date(student* const s);

void 		print_student(student* const s);


// TRAINER.CPP ////////////

student* 	get_datas(int const size , const char* const fileName);
int 		get_size_of_datas(const char* const fileName);
void        improve_weights(double weights[4][14], student* students, int m);
void        improve_thetas(double thetas[14], student* students, int m, house house);


// UTIL.CPP ///////////////

double 		min(student* students, int size, features feature);
double 		max(student* students, int size, features feature);
double 		count(student* students, int size, features feature);
double 		mean(student* students, int size, features feature);
double 		std_d(student* students, int size, features feature);
double      student_in_house(student student, house house);
void		normalize(student* students, int m, double ranges[2][13]);
void		unnormalize(double weights[4][14], double ranges[2][13]);


// CALCULUS.CPP

double		cost(double* theta, student* students, int m, house house);
double		prob(double* theta, double notes[13]);
double		partial_derivative(int j, double* theta, student* students, int m, house house);



#endif