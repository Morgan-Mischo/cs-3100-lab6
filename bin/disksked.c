// Morgan Mischo
// Lab 6
// CS 3100

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #include <limits.h>

// int R_BIG = 20000;
// int R_SMALL = -20000;

//FCFS
// const char* FCFS(int argc, char **argv) {
//     int values[10];

//     for (int i = 0; i <= 9; ++i) {
//         values[i] = atoi(argv[i]);
//     }
// }

/**
 * From https://stackoverflow.com/questions/4710795/finding-the-smallest-number-in-an-array-of-integers
 */
int smallest(int* values, int count) {
    int smallest_value = INT_MAX;
    for (int i = 0; i < count; ++i) {
        if (values[i] < smallest_value) {
            smallest_value = values[i];
        }
    }
    return smallest_value;
}

/**
 * From https://stackoverflow.com/questions/15094834/check-if-a-value-exist-in-a-array
 */
bool isValueInArray(int val, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val)
            return true;
    }
    return false;
}

/**
 * from https://stackoverflow.com/questions/8199403/how-to-check-if-an-array-has-any-duplicates
 */
bool arrayHasDuplicates(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

//SSTF
const char* SSTF(int argc, char **argv) {
    int values[10];
    // int processing[15] = {R_BIG};
    int distance[10];

    for (int i = 0; i <= 9; ++i) {
        values[i] = atoi(argv[i]);
    }


    // processing[1] = values[1];
    // values[1] = R_BIG;

    for (int i = 1; i <= 9; i++) {

        // int lowest = R_BIG;
        int lowest_index;
        // int comparing = processing[i];

        for (int j = 1; j <= 9; j++) {
            int inner = values[j];
            // int abs_val = abs(inner - comparing);

            // if (abs_val < lowest) {
            //     lowest = abs_val;
            //     lowest_index = j;
            // }
        }
        // processing[i+1] = values[lowest_index];
        // values[lowest_index] = R_BIG;
    }
}

void printArray(char *arrayName, int *arr, int size) {
    printf("Array %s: ", arrayName);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void determineLarger(int value, int valuePosition, int *comparingArr, int comparingSize, int *largerArray) {
    for (int i = 0; i < comparingSize; i++) {
        if (value <= comparingArr[i] && i != valuePosition) { 
            largerArray[i] = comparingArr[i];
        }
    }
}

void determineSmaller(int value, int *comparingArr, int comparingSize, int *smallerArray) {
    for (int i = 0; i < comparingSize; i++) {
        if (value > comparingArr[i]) {
            smallerArray[i] = comparingArr[i];
        }
    }
}

/**
 * From https://stackoverflow.com/questions/3893937/c-array-sorting-tips
 */
int compare(const void* a, const void* b) {
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );

    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}

//SCAN
const char* SCAN(int argc, char **argv) {
    // int total = 0;
    int values[10] = {0};
    // int processing[15] = {R_BIG};
    // int distance[15] = {0};
    // int largerThanStart[10] = {R_BIG, R_BIG, R_BIG, R_BIG, R_BIG,
    //                            R_BIG, R_BIG, R_BIG, R_BIG, R_BIG};
    // int smallerThanStart[10] = {R_BIG, R_BIG, R_BIG, R_BIG, R_BIG,
    //                             R_BIG, R_BIG, R_BIG, R_BIG, R_BIG};;

    for (int i = 0; i <= 9; ++i) {
        values[i] = atoi(argv[i]);
    }
    // values[0] = R_BIG;
    // processing[1] = values[1];

    // determineLarger(processing[1], 1, values, sizeof(values) / sizeof(int), largerThanStart);
    // determineSmaller(processing[1], values, sizeof(values) / sizeof(int), smallerThanStart);

    // qsort(largerThanStart, sizeof(largerThanStart) / sizeof(int), sizeof(int), compare);
    // qsort(smallerThanStart, sizeof(smallerThanStart) / sizeof(int), sizeof(int), compare);

    // values[1] = R_SMALL;
    int next = 2; 

}

//C-SCAN

const char* C_SCAN(int argc, char **argv) {
    // int total = 0;
    int values[10] = {0};

    // int processing[15] = {R_BIG};
    // int distance[15] = {0};

    // int largerThanStart[10] = {R_BIG, R_BIG, R_BIG, R_BIG, R_BIG,
    //                            R_BIG, R_BIG, R_BIG, R_BIG, R_BIG};
    // int smallerThanStart[10] = {R_BIG, R_BIG, R_BIG, R_BIG, R_BIG,
    //                             R_BIG, R_BIG, R_BIG, R_BIG, R_BIG};;

    for (int i = 0; i <= 9; ++i) {
        values[i] = atoi(argv[i]);
    }

    // values[0] = R_BIG;
    // processing[1] = values[1];

    // determineLarger(processing[1], 1, values, sizeof(values) / sizeof(int), largerThanStart);
    // determineSmaller(processing[1], values, sizeof(values) / sizeof(int), smallerThanStart);

    // qsort(largerThanStart, sizeof(largerThanStart) / sizeof(int), sizeof(int), compare);
    // qsort(smallerThanStart, sizeof(smallerThanStart) / sizeof(int), sizeof(int), compare);

    // values[1] = R_SMALL;
    // int next = 2; 
    
    // for (int i = 0; i <= 9; ++i) {
        // if (largerThanStart[i] != R_BIG) {
        //     processing[i+2] = largerThanStart[i]; 
    //         next++;
    //     }
    // }

    // for (int i = 9; i >= 0; --i) {
    //     if (smallerThanStart[i] != R_BIG) {
    //         int position = next;
    //         processing[position] = smallerThanStart[i];
    //         next++;
    //     }
    // }
}

// int main(int argc, char *argv[]) {
//     if (argc != 10) {
//         fprintf(stderr, "Usage: ./disksked START T1 T2 T3 T4 T5 T6 T7 T8\n");
//         exit(1);
//     }

//     FCFS(argc, argv);
//     SSTF(argc, argv);
//     SCAN(argc, argv);
//     C_SCAN(argc, argv);

    // return 0;
}

//edit