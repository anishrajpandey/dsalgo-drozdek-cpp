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
    StudentNode *p = head->next;
    StudentNode *n = head;
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
            delete p;
            return;
        }
        n = p;
        p = p->next;
    }
}

StudentNode *StudentLinkedList::searchByID(int id)
{
    StudentNode *p = head;
    while (p != nullptr)
    {
        if (p->id == id)
            return p;
        p = p->next;
    }
    return nullptr;
}

void StudentLinkedList::reverse()
{
    StudentNode *p = head, *n = nullptr, *temp = nullptr;
    while (p != nullptr)
    {
        temp = p->next;
        p->next = n;
        n = p;
        p = temp;
    }
    head = n;
}
int main()
{
    StudentLinkedList Students;

    Students.insertAtEnd(1, "a");
    Students.insertAtEnd(2, "b");
    Students.insertAtEnd(3, "c");
    Students.insertAtEnd(4, "d");
    Students.insertAtEnd(5, "e");
    Students.display();
    cout << endl
         << endl
         << endl;
    // Students.deleteByID(35);
    // StudentNode *node = Students.searchByID(3);
    // cout << node->name;
    Students.reverse();

    Students.display();
}