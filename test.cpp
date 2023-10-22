#include<iostream>
#include<string>
#include "StudentList.h"
using namespace std;

int main()
{
    studentList roster;
    studentList roster2;

    student Abel("Abel", 20490457, 2.33);
    student Oscar("Oscar", 20484349, 2.12);
    student Adrian("Adrian", 20413303, 2.86);


    roster.insert(Abel);
    roster.insert(Oscar);
    roster.insert(Adrian);

    roster.printList();
    cout << endl;
    
    student Cristian("Cristian", 19198542, 1.98);
    student Debbie("Debbie", 78531421, 4.0);
    student Amber("Amber", 88551133, 2.99);

    roster2.insert(Cristian);
    roster2.insert(Debbie);
    roster2.insert(Amber);

    roster2.printList();
    cout << endl;

    student retrievedStudent = roster.retrieveStudent(20484349);
    cout << "Name: " << retrievedStudent.name << ", ID: " << retrievedStudent.id << ", GPA: " << retrievedStudent.gpa << endl;
    cout << endl;

    roster.updateGPA(20490457, 4.0);
    roster.updateGPA(20484349, 3.87);
    roster.updateGPA(20413303, 3.90);
    roster.printList();
    cout << endl;

    studentList honorList = roster.honorRoll(3.5);
    honorList.printList();
    cout << endl;

    //merge list 2 into list 1
    roster.mergeList(roster2);
    cout << "list 1 after merging with list 2: " << endl;
    roster.printList();
    cout << endl;
    cout << "list 2 after merging into list 1: " << endl;
    roster2.printList();

    return 0;

}