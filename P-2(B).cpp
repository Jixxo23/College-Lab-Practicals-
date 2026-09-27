#include <iostream>
using namespace std;

void callByValue(int x)
{
    x = x + 10;
    cout << "Value inside Call By Value function: " << x << endl;
}

void callByReference(int &x)
{
    x = x + 10;
    cout << "Value inside Call By Reference function: " << x << endl;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Original Value: " << num << endl;

    callByValue(num);

    cout << "Value after Call By Value: " << num << endl;

    callByReference(num);

    cout << "Value after Call By Reference: " << num << endl;

    return 0;
}