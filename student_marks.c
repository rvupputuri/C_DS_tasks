#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STUDENT_NAME_SIZE 30

typedef int RollNo;

typedef enum Subjects {
    Telugu, // 0
    Hindi, // 1
    English, // 2
    Maths,  // 3
    Science, // 4
    SocialStudies // 5  
} Subject;

typedef struct Student {
    char name[STUDENT_NAME_SIZE]; // 30 Bytes
    RollNo roll_no; // 4 Bytes
    float total_marks; // 4 B
    float marks[6]; // marks[0] == marks[Telugu]
} Student;

typedef struct Class {
    int strength;
    Student *students;
} Class;

typedef enum {
    RollNumber,
    Name
} SearchType;

typedef union {
    RollNo roll_no;
    char name[STUDENT_NAME_SIZE];
} StudentSearchParam; // 20 B

typedef struct {
    SearchType type;
    StudentSearchParam element;
} StudentSearch;

void student_print_ptr(Student *student){
    if(student == NULL)
        return;

    printf("Student {\n"
           "name: %s\n"
           "roll_no: %d\n"
           "total_marks: %f\n"
           "marks: %f, %f, %f, %f, %f, %f"
           "} at %p\n", student->name, student->roll_no, student->total_marks,
           student->marks[0], student->marks[1], student->marks[2], student->marks[3], student->marks[4], student->marks[5],
           student);
}

void student_print(Student entry){
    printf("Student {\n"
           "name: %s\n"
           "roll_no: %d\n"
           "total_marks: %f\n"
           "marks: %f, %f, %f, %f, %f, %f"
           "} at %p\n", entry.name, entry.roll_no, entry.total_marks,
           entry.marks[0], entry.marks[1], entry.marks[2], entry.marks[3], entry.marks[4], entry.marks[5],
           &entry);
}

Student student_new_empty(){
    Student entry = { "", 0, 0, {0}};
    return entry;
}

float student_get_mark(Student entry, Subject subject){
    return entry.marks[subject];
}

bool student_calculate_total(Student *student){
    if(student == NULL)
        return false;

    student->total_marks = 0;
    for(int i=0; i<6; i++){
        student->total_marks += student->marks[i];
    }
    return true;
}

Student* student_find_by_rollno(Student *students, RollNo roll_no, int len){
    if(students == NULL || len == 0)
        return NULL;

    for(int i=0; i<len; i++){
        if(students[i].roll_no == roll_no)
            return &students[i];
    }

    return NULL;
}

Student* student_find_by_name(char *name, Student *students, int len){
    if(students == NULL || len == 0 || name == NULL)
        return NULL;

    for(int i=0; i<len; i++){
        if(strcmp(students[i].name, name)==0)
            return &students[i];
    }

    return NULL;
}

Student* student_find(Student *students, int len, StudentSearch search){
    Student *student = NULL;

    switch (search.type)
    {
    case RollNumber:
        student = student_find_by_rollno( students, search.element.roll_no, len);
        break;
    
    case Name:
        student = student_find_by_name(search.element.name, students, len);
        break;
    }

    return student;
}

int main(){
    Subject subject = Telugu; // 0
    if(subject == 0){
        printf("yes\n");
    }

    Student raj = { .name= "Raj", .total_marks=567, .roll_no= 909, .marks = { 67, 34, 56, 67, 78, 89} };
    // struct Student someone;
    // someone.roll_no = 178;
    // strcpy(someone.name, "someone");
    // scanf("%s\n", &someone.name);
    Student students[3] = {
        /*  name            roll_no     total_marks    marks*/
        raj,
        {   "prem",         78,         567,           { 34, 45, 56, 78, 89, 67} },
        {   "sandya",       90,         789,           { 12, 23, 34, 45, 56, 67} }
    };

    for(int i=0; i<3;i++){
        student_calculate_total(&students[i]);
        // students[i].roll_no = i+1;
        // students[i].name[0] = 'A';
        printf("%d. ", i+1);
        printf("%s\n", students[i].name);
        printf("%p\n", &students[i]);
        student_print_ptr(&students[i]);
        printf("%d. ", students[i].roll_no);
        printf("%s\n", students[i].name);
        printf("%p\n", &students[i]);
    }
    Student empty = student_new_empty();
    student_print_ptr(&empty);


    Student raj_dup = raj;

    raj.marks[Telugu];
    float telugu_marks_raj = student_get_mark(raj, Telugu);

    Student *sandya = student_find_by_rollno(students, 90, 3);
    printf("\nstudent with roll_number=90 is\n");
    student_print_ptr(sandya);
    printf("\nstudent's memory address is %p\n", sandya);

    StudentSearch search_for = { Name, { .name = "Raj" } };

    Student *rajptr = student_find(students, 3, search_for);

    student_print_ptr(rajptr);

    StudentSearch search_for2 = { RollNumber, { .roll_no = 90 } };

    Student *sandyaptr = student_find(students, 3, search_for2);

    student_print_ptr(sandyaptr);

    // Student *ptr = student_find(students, 3, { RollNumber, { .roll_no = 90 } });

    return 0;
}
