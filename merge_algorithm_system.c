/*
    Author: George Crossan

    Algorithms Assignment Question 5


    --- implemented algorithm from previous questions in C
    
    There are four different types of module which students can attend:-
    1.	DT265A – part-time Higher Diploma
    2.	DT265C – part-time Master’s Qualifier
    3.	DT265B – full-time Master’s Qualifier
    4.	DT8900 – full-time International Master’s Qualifier

    Admission numbers are as follows:
    •	DT265A – 13 students
    •	DT265C – 9 students
    •	DT265B – 14 students
    •	DT8900 – 6 students


*/

#include <stdio.h>
#include <string.h>

#define NAMELEN 21 // maximum characters allowed for surnames
#define MODULENAME 6 // maximum characters allowed for course names
#define SIZE_A 13 // Students in DT265A
#define SIZE_C 9 // Students in DT265C
#define SIZE_B 14 // Students in DT265B
#define SIZE_D 6 // Students in DT8900

struct student_rec {
    char surname[NAMELEN]; // students surname
    int type; //  module type: 1 for full time 0 for part time
    char module[MODULENAME]; // name of module
    
    // For Use Of Linked List
    struct Node* next; 
};

//function signatures

// give data to and display data from data type from question 1
void giveData(struct student_rec[], char*[], int); // (students[], *names[], size)
void printNames(struct student_rec[], int); // (array[], size)
// sorting and merging arrays from question 2
void insertionSort(struct student_rec[], int); // (array[], size)
int binarySearch(struct student_rec[], int, int, char[]); // (array[], low, high, item)
void mergeArrays(struct student_rec[], struct student_rec[], int, int, struct student_rec[]); // (arrayA[], arrayB, sizeA, sizeB, mergedArrays)
// searching for student by surname from question 4
int searchForName(struct student_rec[], int, int, char[]); // (array[], low, high, item)


int main() {

    // QUESTION 1

    // Createing Linked Lists

    // head = (struct Student_rec*)malloc(sizeof(struct Student_rec));
    // second = (struct Student_rec*)malloc(sizeof(struct Student_rec));
    // third = (struct Student_rec*)malloc(sizeof(struct Student_rec));
  
    // head->data = 1; // assign data in first node
    // head->next = second; // Link first node with second
  
    // second->data = 2; // assign data to second node
    // second->next = third;
  
    // third->data = 3; // assign data to third node
    // third->next = NULL;

    struct student_rec DT265A[SIZE_A], DT265C[SIZE_C], DT265B[SIZE_B], DT8900[SIZE_D]; // creating structure arrays - 4 arrays, 1 for each module
   
   // entering module name to first structure of each array
    strcpy(DT265A[0].module, "DT265A");
    strcpy(DT265C[0].module, "DT265C");
    strcpy(DT265B[0].module, "DT265B");
    strcpy(DT8900[0].module, "DT8900");

    // entering module type to first structure of each array
    DT265A[0].type = 0;
    DT265C[0].type = 0;
    DT265B[0].type = 1;
    DT8900[0].type = 1;

    // adding surnames to 4 seperate arrays - 1 array for each module
    char *namesA[SIZE_A] = {"Witterel", "Hoscut", "Nichols", "Perrott",
                        "Davies", "Peters", "Miner", "Evans",
                        "Wallace", "Smith", "Gibbs", "Sefton", "O'Farrell"};
    char *namesC[SIZE_C] = {"Wolff", "Walker", "McKay", "Dalton",
                        "Spratt", "Pasqua", "Jackson", "Brennan", "Moss"};
    char *namesB[SIZE_B] = {"Crossan", "Coyne", "Ortega", "Orourke",
                        "Kelly", "Collins", "Ryan", "Roy", "Delaney",
                        "Lampey", "Bloggs", "Pines", "Gilmore", "Nook"};
    char *namesD[SIZE_D] = {"Galligan", "Andersen", "James", "Milroy",
                        "Lanke", "Hershtik"};

    // entering data to each module
    giveData(DT265A, namesA, SIZE_A);
    giveData(DT265C, namesC, SIZE_C);
    giveData(DT265B, namesB, SIZE_B);
    giveData(DT8900, namesD, SIZE_D);

    // Print names in unsorted arrays of each module
    printf("Unsorted Arrays:");
    printf("\nDT265A:\n");
    printNames(DT265A, SIZE_A);
    printf("\nDT265C:\n");
    printNames(DT265C, SIZE_C);
    printf("\nDT265B:\n");
    printNames(DT265B, SIZE_B);
    printf("\nDT8900:\n");
    printNames(DT8900, SIZE_D);

    // QUESTION 2

    // using insertion sort to sort each structure array by surname
    insertionSort(DT265A, SIZE_A);
    insertionSort(DT265C, SIZE_C);
    insertionSort(DT265B, SIZE_B);
    insertionSort(DT8900, SIZE_D);

    // Print names in sorted arrays of each module
    printf("\n\nSorted Arrays:");
    printf("\nDT265A:\n");
    printNames(DT265A, SIZE_A);
    printf("\nDT265C:\n");
    printNames(DT265C, SIZE_C);
    printf("\nDT265B:\n");
    printNames(DT265B, SIZE_B);
    printf("\nDT8900:\n");
    printNames(DT8900, SIZE_D);


    int temp1 = SIZE_A + SIZE_C; // get size of first temporary array
    struct student_rec mergedOne[temp1]; // initialise first temporary array
    mergeArrays(DT265A, DT265C, SIZE_A, SIZE_C, mergedOne); // merge first 2 modules into one temporary array

    int temp2 = SIZE_B + SIZE_D; // get size of second temporary array
    struct student_rec mergedTwo[temp2]; // initialise second temporary array
    mergeArrays(DT265B, DT8900, SIZE_B, SIZE_D, mergedTwo); //merge second 2 modules into another temporary array

    int arraySIZE = temp1 + temp2; // get size of main array
    struct student_rec allStudents[arraySIZE]; // initialise main temporary array
    mergeArrays(mergedOne, mergedTwo, temp1, temp2, allStudents); //merge these temporary arrays into one main array

    // display names of all students in main list
    printf("\n\nMain List sorted by surname:\n");
    printNames(allStudents, arraySIZE);

    // QUESTION 3

    // search for full-time students in main list and display them
    printf("\n\nAll full time Student:\n");
    for(int i = 0; i < arraySIZE; i++){

        if(allStudents[i].type == 1){

            printf("%s ", allStudents[i].surname);
        }//end if
    }//end for

    // QUESTION 4    

    // user input for name they are searching for
    char x[NAMELEN]; 
    printf("\n\nWhat student would you like to search for?\n");
    fgets(x, NAMELEN - 1, stdin);
    x[strlen(x) - 1] = '\0'; // adding null character in place of new line character for strcmp()

    int result = searchForName(allStudents, 0, arraySIZE - 1, x);

    if(result == -1){
        printf("Name does not exist\n");
    }//end if
    else{
        printf("Student surname: %s\n", allStudents[result].surname);
        printf("module: %s\n", allStudents[result].module);
        if(allStudents[result].type == 0){
            printf("module Type: Part-Time");
        }
        else{
            printf("module Type: Full-Time");
        }
    }//end else

    return 0;
}// end main



void giveData(struct student_rec students[], char *names[], int size){

    int i;
    for(i = 0; i < size; i++){
        strcpy(students[i].surname, names[i]); // adding name from names array to each structure in students array
        strcpy(students[i].module, students[0].module); // copy module name to each structure in array
        students[i].type = students[0].type; // copy module type to each structure in array
    }//end for
}//end giveData

void printNames(struct student_rec students[], int size){

    int i;
     for(i = 0; i < size; i++){
        printf("%s ", students[i].surname); // print each name in array
    }//end for
}//end printNames

void insertionSort(struct student_rec array[], int size){

    int i, j, location;
    struct student_rec key;

    for(i = 1; i < size; i++){
        key = array[i];
        j = i - 1;

        location = binarySearch(array, 0, j, key.surname); // binary search added to improve insertion sort algorithm

        while(j >= location){
            array[j + 1] = array[j];
            j--;
        }//end while
        array[j + 1] = key;
    }//end for
}//end insertionSort

int binarySearch(struct student_rec array[], int low, int high, char item[]){

    int mid;
    mid = (high + low) / 2;

    if(low > high){
        return low; // if item is not in array return value for low
    }// end if
    else{
        if(strcmp(array[mid].surname, item) == 0){
            return mid;
        }//end if
        else if(strcmp(array[mid].surname, item) > 0){
            return binarySearch(array, low, mid - 1, item);
        }//end else if
        else{
            return binarySearch(array, mid + 1, high, item);
        }//end else
    }//end else
}

void mergeArrays(struct student_rec arrayA[], struct student_rec arrayB[], int sizeA, int sizeB, struct student_rec mergedList[]){
    
    int i = 0;
    int a = 0;
    int b = 0;

    while (a < sizeA && b < sizeB) {
        if (strcmp(arrayA[a].surname, arrayB[b].surname) <= 0){
            mergedList[i] = arrayA[a];
            a++; // move up position in left array
        }//end if
        else {
            mergedList[i] = arrayB[b];
            b++; // move up position in right array
        }//end else
        i++; // move up one position in complete array
    }//end while

    // add remaining elemets in either left or right side
    while (a < sizeA) {
        mergedList[i] = arrayA[a];
        a++;
        i++;
    }//end while
    while (b < sizeB) {
        mergedList[i] = arrayB[b];
        b++;
        i++;
    }//end while
}//end mergeArrays

int searchForName(struct student_rec array[], int low, int high, char item[]){ 

    int mid;
    mid = (high + low) / 2;

    if(low > high){
        return -1; // return -1 if name is not in list
    }// end if
    else{
        if(strcmp(array[mid].surname, item) == 0){
            return mid;
        }//end if
        else if(strcmp(array[mid].surname, item) > 0){
            return searchForName(array, low, mid - 1, item);
        }//end else if
        else{
            return searchForName(array, mid + 1, high, item);
        }//end else
    }//end else
}//end searchForName