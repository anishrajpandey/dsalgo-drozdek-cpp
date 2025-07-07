#include "TabManager.h"
#include <string>

Browser::Browser()
{
    head = nullptr;
}
Tab::Tab(string title, string url)
{
    title = title;
    url = url;
}
void Browser::openTab(string title, string url)
{
    // Tab* newTab=new Tab()
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
}
void Browser::showCurrentTab()
{
}
bool Browser::isEmpty()
{
}