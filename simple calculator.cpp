#include <iostream>
using namespace std;

void func()
{
    int d = 1;
    float a, b;
    char s, c;
    while (d == 1)
    {
        cout << "Choose the Arithmetic Operation:\n";
        cout << "\033[1m\u2022 Addition (+)\n\u2022 Subtraction (-)\n\u2022 Multiplication (*)\n\u2022 Division (/)\033[0m\n"; // \033[1m is used for bold text, \u2022 is used for bullet point.
        cout << "Enter Your Choice: ";
        cin >> s;

        if (s == '+')
        {
            cout << "Enter The First Number: ";
            cin >> a;
            cout << "Enter the Second Number: ";
            cin >> b;
            cout << "\033[32mThe Answer is: " << a + b << "\033[0m";
        }
        else if (s == '-')
        {
            cout << "Enter The First Number: ";
            cin >> a;
            cout << "Enter the Second Number: ";
            cin >> b;
            cout << "\033[32mThe Answer is: " << a - b << "\033[0m";
        }
        else if (s == '*')
        {
            cout << "Enter The First Number: ";
            cin >> a;
            cout << "Enter the Second Number: ";
            cin >> b;
            cout << "\033[32mThe Answer is: " << a * b << "\033[0m";
        }
        else if (s == '/')
        {
            cout << "Enter The First Number: ";
            cin >> a;
            cout << "Enter the Second Number: ";
            cin >> b;
            if (b != 0)
                cout << "\033[32mThe Answer is: " << a / b << "\033[0m";
            else
                cout << "\033[31mWarning! Division by zero is not allowed.\033[0m";
        }
        else
        {
            cout << "\033[31mWrong Choice!\033[0m";
        }

        cout << "\n\nWant to continue (y/n)? ";
        cin >> c;

        if (c != 'y' && c != 'Y')
        {
            cout << "\nSeems like you want to exit.\n\033[32mThank you!\033[0m\n";
            d = 0;
        }
    }
    return;
}

int main()
{
    cout << "** Welcome To Our Calculator Program **\n" << endl;
    cout << "General Instructions:\n";
    cout << "\033[1m \u2022 While choosing the arithmetic operation just write its symbol\n"; // \033[1m is used for bold text.
    cout << " \u2022 This calculator involves simple arithmetic operations like Addition, Subtraction, Multiplication, and Division\n";
    cout << " \u2022 After every single operation, a question pops up to continue with the use or not.\n";
    cout << " \u2022 The two inputs must be float or else it will print a junk value.\n";
    cout << " \u2022 In the above question enter y or Y to continue or else all will terminate the code.\033[0m\n" << endl;
    func();
    return 0;
}