#include "TabManager.h"
#include <string>
#include <iostream>

Browser::Browser()
{
    head = nullptr;
    current = nullptr;
}
Tab::Tab(string url, string title)
{
    this->title = title;
    this->url = url;
}
Browser::~Browser()
{
    Tab *p = head;
    while (p != nullptr)
    {
        Tab *temp = p;
        p = p->next;
        delete temp;
    }
}
void Browser::openTab(string title, string url)
{
    Tab *newTab = new Tab(url, title);
    if (isEmpty())
    {
        head = newTab;
        current = newTab;
    }

    else
    {
        Tab *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = newTab;
        newTab->prev = p;
        current = newTab;
    }
}
void Browser::closeCurrentTab()
{
    if (isEmpty())
        return;
    Tab *temp = current;
    if (current == head) // current is the first tab
    {

        head = current = head->next;
        if (head != nullptr)
            head->prev = nullptr;
    }

    else if (current->next == nullptr) // current is the last tab
    {
        current->prev->next = nullptr;

        current = temp->prev;
        temp->prev = nullptr;
    }
    else
    { // current is somewhere in middle
        current = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete temp;
}
void Browser::moveNext()
{
    if (isEmpty() || current->next == nullptr)
        return;
    current = current->next;
}
void Browser::movePrev()
{
    if (isEmpty() || current->prev == nullptr)
        return;
    current = current->prev;
}
void Browser::showAllTabs()
{
    Tab *p = head;
    cout << "Displaying all tabs" << endl;
    while (p != nullptr)
    {
        cout << p->title << " " << p->url << endl;
        p = p->next;
    }
    cout << endl
         << endl;
}
void Browser::showCurrentTab()
{
    if (isEmpty() || current == nullptr)
    {
        cout << "No current tab.\n";
        return;
    }
    cout << "Displaying Current Tab" << endl;
    cout << current->title << "  " << current->url << endl;
}
bool Browser::isEmpty()
{
    return head == nullptr;
}
