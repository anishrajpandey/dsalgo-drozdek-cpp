#include <iostream>
#include <string>
using namespace std;

struct StudentNode
{
    int id;
    string name;
    StudentNode *next;
    StudentNode(int _id, string _name)
    {
        id = _id;
        name = _name;
        next = nullptr;
    }
};

class StudentLinkedList
{
private:
    StudentNode *head;

public:
    StudentLinkedList();
    void insertAtBeginning(int id, string name);
    void insertAtEnd(int id, string name);
    void insertAtPosition(int pos, int id, string name);
    void deleteByID(int id);
    StudentNode *searchByID(int id);
    void traverse();
    void reverse();
    bool isEmpty();
    void display();
};

StudentLinkedList::StudentLinkedList()
{
    head = nullptr;
}
void StudentLinkedList::display()
{
    StudentNode *p = head;
    while (p != nullptr)
    {
        cout << p->id << " " << p->name << endl;
        p = p->next;
    }
}

bool StudentLinkedList::isEmpty()
{
    return head == nullptr;
}

void StudentLinkedList::insertAtBeginning(int id, string name)
{

    StudentNode *student = new StudentNode(id, name);
    if (isEmpty())
    {
        head = student;
        student->next = nullptr;
    }
    else
    {
        student->next = head;
        head = student;
    }
}

void StudentLinkedList::insertAtEnd(int id, string name)
{
    StudentNode *newNode = new StudentNode(id, name);
    if (!isEmpty())
    {
        StudentNode *p = head;

        while (p->next != nullptr)
        {
            p = p->next;
        }

        p->next = newNode;
    }
    else
    {
        head = newNode;
    }
}
void StudentLinkedList::insertAtPosition(int pos, int id, string name)
{
    StudentNode *newNode = new StudentNode(id, name);
    StudentNode *p = head;
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int index = 1; index <= pos && p != nullptr; index++)
    {
        if (index == pos)
        {
            newNode->next = p->next;
            p->next = newNode;
        }
        p = p->next;
    }
}

void StudentLinkedList::deleteByID(int id)

{
    StudentNode *p = head;
    StudentNode *n = nullptr;
    if (isEmpty())
        return;
    if (id == head->id)
    { // for first element found

        head = head->next;

        return;
    }

    while (p != nullptr)
    {

        if (p->id == id)
        {
            n->next = p->next;
        }
        n = p;
        p = p->next;
    }
}

StudentNode *StudentLinkedList::searchByID(int id)
{
    StudentNode *p = head;
    if (p != nullptr)
    {
        if (p->id == id)
            return p;
        p = p->next;
    }
}
int main()
{
    StudentLinkedList Students;

    Students.insertAtEnd(3, "Manita");
    Students.insertAtEnd(23, "Manita");
    Students.insertAtEnd(4, "Manita");
    Students.insertAtEnd(5, "Manitaqqqqq");
    Students.insertAtEnd(35, "Manita");

    Students.deleteByID(35);
    StudentNode *node = Students.searchByID(5);
    cout << (*node).name << "found";

    Students.display();
}