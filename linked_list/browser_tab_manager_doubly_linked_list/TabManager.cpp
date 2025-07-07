#include "TabManager.h"
#include <string>
#include <iostream>

Browser::Browser()
{
    head = nullptr;
}
Tab::Tab(string url, string title)
{
    this->title = title;
    this->url = url;
}
void Browser::openTab(string title, string url)
{
    Tab *newTab = new Tab(url, title);
    if (isEmpty())
        head = newTab;
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
}
void Browser::moveNext()
{
}
void Browser::movePrev()
{
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
    cout << "Displaying Current Tab" << endl;
    cout << current->title << "  " << current->url << endl;
}
bool Browser::isEmpty()
{
    return head == nullptr;
}
