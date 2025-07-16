#include <iostream>
#include <string>
#include <stack>
using namespace std;
void reverseStack(stack<int> originalStack){
    if(originalStack.size()==0) return; 

    int popped = originalStack.top();
    originalStack.pop();
    reverseStack(originalStack);



}