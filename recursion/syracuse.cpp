// Write a recursive method to print a Syracuse sequence that begins with a number n0 and each element ni of the sequence is ni-1 /2 if ni-1 is even and 3ni-1 + 1 otherwise. The sequence ends with 1.
#include <iostream>
using namespace std;
void syracuse(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return;
    }
    cout << n << " ";
    if (n % 2 == 0)
        syracuse(n / 2);
    else
        syracuse(3 * n + 1);

        return;
}
int main()
{
    syracuse(223);
}