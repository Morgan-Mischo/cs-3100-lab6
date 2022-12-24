// Morgan Mischo
// Lab 6
// CS 3100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int debug = 1;
int R_BIG = 20000;
int R_SMALL = -20000;


const char* FCFS(int argc, char **argv) {
    int total = 0;
    int values[10];
    int distance[10];


    for (int i = 0; i <= 9; ++i) {
        values[i] = atoi(argv[i]);
    }

    for (int i = 2; i <= 9; ++i) {
        distance[i] = abs(values[i] - values[i-1]);
        total += distance[i];
    }

    printf("FCFS: Start:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d Total:%d\n",
           values[1],
           values[2], distance[2],
           values[3], distance[3],
           values[4], distance[4],
           values[5], distance[5],
           values[6], distance[6],
           values[7], distance[7],
           values[8], distance[8],
           values[9], distance[9],
           total);
    return 0;
}

/**
 * Copied directly from https://stackoverflow.com/questions/4710795/finding-the-smallest-number-in-an-array-of-integers
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
 * Copied directly from https://stackoverflow.com/questions/15094834/check-if-a-value-exist-in-a-array
 */
bool isValueInArray(int val, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val)
            return true;
    }
    return false;
}

/**
 * Modified from the answer https://stackoverflow.com/questions/8199403/how-to-check-if-an-array-has-any-duplicates
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


const char* SSTF(int argc, char **argv) {
    int total = 0;

    int values[10];

    int my_processing[15] = {R_BIG};
    int distance[10];


    for (int i = 0; i <= 9; ++i) {
        values[i] = atoi(argv[i]);
    }

    my_processing[1] = values[1];
    values[1] = R_BIG;

    for (int i = 1; i <= 9; i++) {

        int lowest = R_BIG;
        int lowest_index;

        int comparing = my_processing[i];

        for (int j = 1; j <= 9; j++) {
            // Skip ourselves
            int inner = values[j];
            int abs_val = abs(inner - comparing);


            if (abs_val < lowest

                ) {

                lowest = abs_val;
                lowest_index = j;
            }
        }


        my_processing[i+1] = values[lowest_index];
        distance[i+1] = lowest;
        values[lowest_index] = R_BIG;
    }

    total = distance[2]+distance[3]+distance[4]+distance[5]+distance[6]+distance[7]+distance[8]+distance[9];


    printf("SSTF: Start:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d Total:%d\n",
           my_processing[1],
           my_processing[2], distance[2],
           my_processing[3], distance[3],
           my_processing[4], distance[4],
           my_processing[5], distance[5],
           my_processing[6], distance[6],
           my_processing[7], distance[7],
           my_processing[8], distance[8],
           my_processing[9], distance[9],
           total);
    return 0;
}

void printArray(char *arrayName, int *arr, int size) {
    printf("Array %s: ", arrayName);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void determineLarger(int value, int valuePosition, int *comparingArr, int comparingSize, int *largerArray) {
//    printf("Determining Larger. Size of Comparing Array: %d\n", sizeof(comparingArr) / sizeof(int));
    for (int i = 0; i < comparingSize; i++) {
        if (value <= comparingArr[i] && i != valuePosition) { // If its "me" then don't add it, but allow duplicates through
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
 * Copied directly from https://stackoverflow.com/questions/3893937/c-array-sorting-tips
 */
int compare(const void* a, const void* b) {
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );

    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}


const char* SCAN(int argc, char **argv) {
    int total = 0;
    int values[10] = {0};

    int my_processing[15] = {R_BIG};
    int distance[15] = {0};

    int largerThanStart[10] = {R_BIG, R_BIG, R_BIG, R_BIG, R_BIG,
                               R_BIG, R_BIG, R_BIG, R_BIG, R_BIG};
    int smallerThanStart[10] = {R_BIG, R_BIG, R_BIG, R_BIG, R_BIG,
                                R_BIG, R_BIG, R_BIG, R_BIG, R_BIG};;

  
    for (int i = 0; i <= 9; ++i) {
        values[i] = atoi(argv[i]);
    }
    values[0] = R_BIG;


    my_processing[1] = values[1];


    determineLarger(my_processing[1], 1, values, sizeof(values) / sizeof(int), largerThanStart);
    determineSmaller(my_processing[1], values, sizeof(values) / sizeof(int), smallerThanStart);


    qsort(largerThanStart, sizeof(largerThanStart) / sizeof(int), sizeof(int), compare);
    qsort(smallerThanStart, sizeof(smallerThanStart) / sizeof(int), sizeof(int), compare);

    values[1] = R_SMALL;

    int startNextChunkAt = 2; 
    for (int i = 0; i <= 9; ++i) {
        if (largerThanStart[i] != R_BIG) {
            my_processing[i+2] = largerThanStart[i]; 
            distance[i+2] = abs(my_processing[i+1] - my_processing[i+2]);
            startNextChunkAt++;
        }
    }

    for (int i = 0; i <= 9; ++i) {
        if (smallerThanStart[i] != R_BIG) {
            int position = i+startNextChunkAt;
            my_processing[position] = smallerThanStart[i]; 
            distance[i+startNextChunkAt] = abs(my_processing[position-1] - my_processing[position]);
        }
    }



    total = distance[2]+distance[3]+distance[4]+distance[5]+distance[6]+distance[7]+distance[8]+distance[9];


    printf("SCAN: Start:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d Total:%d\n",
           my_processing[1],
           my_processing[2], distance[2],
           my_processing[3], distance[3],
           my_processing[4], distance[4],
           my_processing[5], distance[5],
           my_processing[6], distance[6],
           my_processing[7], distance[7],
           my_processing[8], distance[8],
           my_processing[9], distance[9],
           total);
    return 0;
}


const char* C_SCAN(int argc, char **argv) {
    int total = 0;
    int values[10] = {0};

    int my_processing[15] = {R_BIG};
    int distance[15] = {0};

    int largerThanStart[10] = {R_BIG, R_BIG, R_BIG, R_BIG, R_BIG,
                               R_BIG, R_BIG, R_BIG, R_BIG, R_BIG};
    int smallerThanStart[10] = {R_BIG, R_BIG, R_BIG, R_BIG, R_BIG,
                                R_BIG, R_BIG, R_BIG, R_BIG, R_BIG};;

    for (int i = 0; i <= 9; ++i) {
        values[i] = atoi(argv[i]);
    }
    values[0] = R_BIG;

    my_processing[1] = values[1];


    determineLarger(my_processing[1], 1, values, sizeof(values) / sizeof(int), largerThanStart);
    determineSmaller(my_processing[1], values, sizeof(values) / sizeof(int), smallerThanStart);



    qsort(largerThanStart, sizeof(largerThanStart) / sizeof(int), sizeof(int), compare);
    qsort(smallerThanStart, sizeof(smallerThanStart) / sizeof(int), sizeof(int), compare);


    values[1] = R_SMALL;



    int startNextChunkAt = 2; 
    for (int i = 0; i <= 9; ++i) {
        if (largerThanStart[i] != R_BIG) {
            my_processing[i+2] = largerThanStart[i]; 
            distance[i+2] = abs(my_processing[i+1] - my_processing[i+2]);
            startNextChunkAt++;
        }
    }

    for (int i = 9; i >= 0; --i) {
        if (smallerThanStart[i] != R_BIG) {
            int position = startNextChunkAt;
            my_processing[position] = smallerThanStart[i];
            distance[startNextChunkAt] = abs(my_processing[position-1] - my_processing[position]);
            startNextChunkAt++;
        }
    }

    total = distance[2]+distance[3]+distance[4]+distance[5]+distance[6]+distance[7]+distance[8]+distance[9];


    printf("C_SCAN: Start:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d %d:%d Total:%d\n",
           my_processing[1],
           my_processing[2], distance[2],
           my_processing[3], distance[3],
           my_processing[4], distance[4],
           my_processing[5], distance[5],
           my_processing[6], distance[6],
           my_processing[7], distance[7],
           my_processing[8], distance[8],
           my_processing[9], distance[9],
           total);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 10) {
        fprintf(stderr, "Usage: ./disksked START T1 T2 T3 T4 T5 T6 T7 T8\n");
        exit(1);
    }

    FCFS(argc, argv);
    SSTF(argc, argv);
    SCAN(argc, argv);
    C_SCAN(argc, argv);

    return 0;
}