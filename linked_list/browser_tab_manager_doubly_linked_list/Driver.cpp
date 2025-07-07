#include <iostream>
#include "TabManager.h"
using namespace std;
int main()
{
    Browser br = Browser();
    br.openTab("Facebook", "facebook.com");
    br.showAllTabs();
}