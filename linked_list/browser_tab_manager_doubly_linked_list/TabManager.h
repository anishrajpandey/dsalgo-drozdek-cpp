#include <string>
using namespace std;

struct Tab
{
    string url;
    string title;
    Tab *prev;
    Tab *next;
    Tab(string url, string title);
};

class Browser
{
private:
    Tab *head;
    Tab *current;

public:
    Browser();
    void openTab(string title, string url);
    void closeCurrentTab();
    void moveNext();
    void movePrev();
    void showAllTabs();
    void showCurrentTab();
    bool isEmpty();
};