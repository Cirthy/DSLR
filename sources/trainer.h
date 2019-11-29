#ifndef 	__TRAINER_H__
#define 	__TRAINER_H__

#define 	DATAS_PATHFILE 		"resources/dataset_train.csv"
#define     TESTS_PATHFILE      "resources/dataset_test.csv"
#define     WEIGHTS_PATHFILE    "resources/weights.csv"
#define     PREDICS_PATHFILE    "resources/houses.csv"
#define     EPOCHS      10000
#define     LEARNING_RATE   0.8


#include    <cmath>
#include    <cstdio>
#include    <cstdlib>
#include    <vector>


typedef enum Hand {
	Right,
	Left
}Hand;

typedef enum House {
	Ravenclaw,
	Slytherin,
	Gryffindor,
	Hufflepuff
} House;

typedef enum Features {
	Arithmancy,
	Astronomy,
	Herbology,
	DefenseAgainstTheDarkArts,
	Divination,
	MuggleStudies,
	AncientRunes,
	HistoryOfMagic,
	Transfiguration,
	Potions,
	CareOfMagicalCreatures,
	Charms,
	Flying
}Features;

typedef struct Date
{
	int 	day;
	int 	month;
	int 	year;
} Date;

typedef struct Range {
    double  min;
    double  max;
} Range;

typedef struct Student
{
	House 	hogwartsHouse;
	char 	firstName[21];
	char 	lastName[21];
	Date 	birthday;
	Hand 	bestHand;
	double 	notes[13];
} Student;



// MANAGMENT.CPP //////////

void        init_weights(double weights[4][14]);
void 		print_house(Student* const s);
void 		print_best_hand(Student* const s);
void 		print_birthday_date(Student* const s);

void 		print_student(Student* const s);


// TRAINER.CPP ////////////

void        improve_weights(double weights[4][14], Student* students, int m);
void        improve_thetas(double thetas[14], Student* students, int m, House house);


// UTIL.CPP ///////////////

double 		min(Student* students, int size, Features feature);
double 		max(Student* students, int size, Features feature);
double 		mean(Student* students, int size, Features feature);
double 		std_d(Student* students, int size, Features feature);
double      student_in_house(Student student, House house);
Range       *get_range(Student* students, int size);
void		normalize(Student* students, int m, Range * ranges);
void		unnormalize(double weights[4][14], Range * ranges);


// CALCULUS.CPP

double		cost(double* theta, Student* students, int m, House house);
double		prob(double* theta, double notes[13]);
double		partial_derivative(int j, double* theta, Student* students, int m, House house);

// WRITER.CPP

void        write(double weights[4][14]);

// PREDICT.CPP

House       estimate_house(Student student, std::vector<std::vector<double>> weights);

// READER.CPP

std::vector<std::vector<double>> deser_weights();
Date        deser_date(char * str_date);
Hand        deser_hand(char * hand);
House       deser_house(char * house);
std::vector<Student>   deser_new_studs();
Student* 	get_datas(int const size , const char* const fileName);
int 		get_size_of_datas(const char* const fileName);
void 		get_string_until_comma(FILE* const fd , char* str);

#endif