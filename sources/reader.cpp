#include <iostream>
#include <fstream>
#include <cstring>
#include "trainer.h"

std::vector<double> deser_thetas(std::string line) {
    std::vector<double> thetas;
    std::vector<char *> tokens;

    tokens.push_back(strtok(const_cast<char *>(line.c_str()), ";"));
    thetas.push_back(atoi(tokens.back()));
    while(tokens.back() != nullptr) {
        tokens.push_back(strtok(nullptr, ";"));
        thetas.push_back(atoi(tokens.back()));
    }

    return thetas;
}

std::vector<std::vector<double>> deser_weights() {
    std::string line;
    std::vector<std::vector<double>> weights;
    std::ifstream file(WEIGHTS_PATHFILE);

    if (file.is_open()) {
        while(getline(file, line)) {
            weights.push_back(deser_thetas(line));
        }
    }

    return weights;
}

Student     tok_to_new_student(std::vector<char *> tokens) {
    Student student;

    printf("a\n");
    student.hogwartsHouse = Gryffindor;
    printf("b\n");
    strncpy(student.firstName, tokens[1], 21);
    printf("c\n");
    strncpy(student.lastName, tokens[2], 21);
    printf("d\n");
    student.birthday = deser_date(tokens[3]);
    printf("e\n");
    student.bestHand = deser_hand(tokens[4]);
    printf("f\n");
    for(int i = 0; i < 13; i++) {
        student.notes[i] = strtod(tokens[i+5], nullptr);
    }

    return student;
}

std::vector<Student>    deser_new_studs() {
    std::string line;
    std::vector<char*> tokens;
    std::ifstream file(TESTS_PATHFILE);
    std::vector<Student> students;
    Student stud;
    char * cstr;

    if (file.is_open()) {
        getline(file, line);//discard first line
        while(getline(file, line)){
            cstr = (char *)malloc(line.size());
            strncpy(cstr, const_cast<char *>(line.c_str()), line.size());
            tokens.push_back(strtok(const_cast<char *>(cstr), ",")); //Index column
            while(tokens.back() != nullptr) {
                tokens.push_back(strtok(nullptr, ","));
            }
            free(cstr);
            int pos = 0;
            for(int i = 0; line[i]; i++) {
                std::vector<char *>::iterator it = tokens.begin();

                if(line[i] == ','){
                    pos++;
                    if (line[i+1] == ',' && pos != 1) {
                        tokens.insert(it+pos, const_cast<char *>("0"));
                    }
                }
            }
            stud = tok_to_new_student(tokens);
            tokens.clear();
            students.push_back(stud);
            printf("%lu\n", students.size());
        }
        file.close();
    }
    else
        std::cout << "cannot open test file" << std::endl;

    return students;
}

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

        datas[i].hogwartsHouse  = deser_house(hogwartsHouse);
        datas[i].bestHand = deser_hand(bestHand);
    }
    fclose(fd);

    return datas;
}

Date    deser_date(char * str_date) {
    Date date;

    date.year = atoi(strtok(str_date, "-"));
    date.month = atoi(strtok(nullptr, "-"));
    date.day = atoi(strtok(nullptr, "-"));

    return date;
}

Hand    deser_hand(char * hand) {
    switch (hand[0]) {
        case 'L' : return Left;
        case 'R' : return Right;
        default:
            printf("Error in get_datas to set best hand.\n");
            return Left;
    }
}

House   deser_house(char* house) {
    switch (house[0]) {
        case 'R' : return Ravenclaw;
        case 'S' : return Slytherin;
        case 'G' : return Gryffindor;
        case 'H' : return Hufflepuff;
        default:
            printf("Error in get_datas to set Hogwarts house.\n");
            return Gryffindor;
    }
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
