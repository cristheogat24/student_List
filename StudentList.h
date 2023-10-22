#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
Implement the "studentList" data structure with a doubly linked list implementation.

You must implement all methods and they must work as described in the comments.  You must also achieve the stated run times, and know the big-Oh run times for each of your methods.
*/


class student
{
public:
	string name;
	unsigned int id;
	double gpa;

	student()
	{
		name = "ghost";
		id = 0;
		gpa = 0;
	}
	student(string _name, unsigned int _id, double _gpa)
	{
		id = _id;
		gpa = _gpa;
		name = _name;
	}
};

class studentList
{
private:
	//Implement a doubly linked list of students

	class node
	{
	public:
		student data;
		node* next;
		node* prev;

		node(student x)
		{
			data = x;
			next = NULL;
			prev = NULL;
		}
	};

	node* head;
	node* tail;

public:
	studentList()
	{
		head = nullptr;
		tail = nullptr;
	}

	//add a student to the list.
	//Must run in O(1) time.
	void insert(student s)
	{
		node* person = new node(s);
		if (head == NULL)
		{
			head = person;
			tail = person;
		}
		else
		{
			tail->next = person;
			person->prev = tail;
			tail = person;
		}
	}

	//find the student with the given id number and return it
	//What is the worst case run time of this?
	//What is the average case run time of this?
	student retrieveStudent(unsigned int idnumber)
	{
		node* current = head;
		while (current != NULL)
		{
			if (current->data.id == idnumber)
			{
				return current->data;
			}
			current = current->next;

		}
		//just in case theres a mistake when putting a student information wrong
		return student();
	}

	//Change the gpa of the student with given id number to newGPA
	//What is the run time?
	void updateGPA(unsigned int idnumber, double newGPA)
	{
		node* current = head;
		while (current != NULL)
		{
			if (current->data.id == idnumber)
			{
				current->data.gpa = newGPA;
				break;
			}
			current = current->next;
		}

	}

	//Add all students from otherlist to this list.
	//otherlist should be empty after this operation.
	//Must run in O(1) time.
	void mergeList(studentList& otherlist)
	{
		
		if (otherlist.head == NULL)
		{
			return;
		}

		if (head == NULL)
		{
			head = otherlist.head;
			tail = otherlist.tail;
		}
		else
		{
			tail->next = otherlist.head;
			otherlist.head->prev = tail;
			tail = otherlist.tail;
		}

		otherlist.head = NULL;
		otherlist.tail = NULL;
	}

	//create a list of students whose gpa is at least minGPA.
	//Return this list.  The original list should
	//not be modified (do not remove the students from the original list).
	//Run time?
	studentList honorRoll(double minGPA)
	{
		studentList honorlist;
		node* current = head;
		while (current != NULL)
		{
			if (current->data.gpa >= minGPA)
			{
				honorlist.insert(current->data);
			}
			current = current->next;
		}
		return honorlist;
	}

	//sort the list by the given field ("name", "id", or "gpa").
	//Run time? 
	void sort(string field)
	{
		if (field == "name")
		{
			node* curr, * index;
			student temp;
			if (head == NULL)
			{
				return;
			}
			for (curr = head; curr->next != NULL; curr = curr->next)
			{
				for (index = curr->next; index != NULL; index = index->next)
				{
					if (curr->data.name > index->data.name)
					{
						temp = curr->data;
						curr->data = index->data;
						index->data = temp;
					}
				}
			}
		}
		else if (field == "id")
		{
			node* curr, * index;
			student temp;
			if (head == NULL)
			{
				return;
			}
			for (curr = head; curr->next != NULL; curr = curr->next)
			{
				for (index = curr->next; index != NULL; index = index->next)
				{
					if (curr->data.id > index->data.id)
					{
						temp = curr->data;
						curr->data = index->data;
						index->data = temp;
					}
				}
			}
		}
		else if (field == "gpa")
		{
			node* curr, * index;
			student temp;
			if (head == NULL)
			{
				return;
			}
			for (curr = head; curr->next != NULL; curr = curr->next)
			{
				for (index = curr->next; index != NULL; index = index->next)
				{
					if (curr->data.gpa > index->data.gpa)
					{
						temp = curr->data;
						curr->data = index->data;
						index->data = temp;
					}
				}
			}
		}
	}

	//Print out each student in the list.  This is mainly for testing purposes.
	void printList()
	{
		node* list = head;
		while (list != NULL)
		{
			cout << list->data.name << " ";
			cout << list->data.id << " ";
			cout << list->data.gpa << endl;

			list = list->next;
		}
	}
};