#include	"trainer.h"


int main(int ac, char **av)
{
    int 		size;

    if (ac != 2) {
        printf("-p pour predict, -t pour train");
        return 0;
    }
    else if (av[1] == "-p") {
        std::vector<Student> students = deser_new_studs();
        std::vector<std::vector<double>> weights = deser_weights();
        //TODO
    }
    else if (av[1] == "-t") {
        double      weights[4][14];
        Student* 	students;
        Range*      ranges;
        size = get_size_of_datas(DATAS_PATHFILE);
        students = get_datas(size, DATAS_PATHFILE);
        ranges = get_range(students, size);

        normalize(students, size, ranges);
        init_weights(weights);
        for (int i = 0; i < EPOCHS; i++) {
            improve_weights(weights, students, size);
            if (i % 1000 == 0) {
                printf("\ntour %d\n", i);
                for (int w = 0; w < 14; w++)
                    printf("%lf\n", weights[0][w]);
            }
        }

        unnormalize(weights, ranges);
        write(weights);
        free(students);
        free(ranges);
    }
	return 0;
}