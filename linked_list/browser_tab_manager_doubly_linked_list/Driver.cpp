#include <iostream>
#include "TabManager.h"
using namespace std;
int main()
{
    Browser br = Browser();
    br.openTab("Facebook", "facebook.com");
    br.openTab("YouTube", "youtube.com");
    br.openTab("Twitter", "twitter.com");
    br.openTab("Reddit", "reddit.com");
    br.openTab("LinkedIn", "linkedin.com");
    br.openTab("GitHub", "github.com");
    br.openTab("Google", "google.com");
    br.openTab("Stack Overflow", "stackoverflow.com");
    br.openTab("Netflix", "netflix.com");
    br.openTab("Medium", "medium.com");

    br.showAllTabs();
}