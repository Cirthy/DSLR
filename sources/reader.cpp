#include <iostream>
#include <fstream>
#include <cstring>
#include "trainer.h"

/*
Student*    get_new_studs() {
    std::string line;
    char* tok;
    std::ifstream file("resources/dataset_test.csv");
    Student* students = NULL;

    if (file.is_open()) {
        while(getline(file, line)){
            tok = strtok(const_cast<char *>(line.c_str()), ";"); //Index column
            while(tok != NULL) {

            }
        }
        file.close();
    }
    else
        std::cout << "cannot open test file" << std::endl;
    return students;
}*///TODO

Student* 	get_datas(int const size , const char* const fileName)
{
    FILE* 		fd=NULL;
    int 		index;
    char 		bestHand[6];
    char 		hogwartsHouse[11];
    Student*	datas;

    fd = fopen(fileName, "r");
    if (not fd)
        return NULL;

    datas = (Student*)malloc(size*sizeof(Student));

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
        fscanf(fd , "%lf,"  , &(datas[i].notes[Arithmancy]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[Astronomy]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[Herbology]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[DefenseAgainstTheDarkArts]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[Divination]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[MuggleStudies]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[AncientRunes]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[HistoryOfMagic]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[Transfiguration]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[Potions]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[CareOfMagicalCreatures]));
        fscanf(fd , "%lf,"  , &(datas[i].notes[Charms]));
        fscanf(fd , "%lf\n" , &(datas[i].notes[Flying]));

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
