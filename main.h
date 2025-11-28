#ifndef MAIN_H
#define MAIN_H

typedef struct {
    int id;
    char* name;
    char* firstname;
    int average;
} Student;

void print();
void input(); 
void create();
void delete();

void fillStudentsArray();
void displayStudentsList();
void searchStudentById();
void deleteStudentById();
void displayClassAverage();

#endif