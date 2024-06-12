#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Todo
{
public:
    int sno;
    string title, status;
    void add(int x);
    void display(int y);
    void mark(int z);
    void del(int w);
} a[1000];

void Todo ::add(int count)
{
    string s;
    a[count].sno = count + 1;
    cout << "Enter the title: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, s);
    a[count].title = s;
    a[count].status = "Pending"; // Set default status
    cout << endl;
    return;
}

void Todo::display(int count)
{
    cout << "\033[1m Todo List \033[0m \t \t ";

    // Get the current time
    time_t t = time(nullptr);
    // Convert it to local time
    tm *now = localtime(&t);

    // Print the date in DD-MM-YYYY format
    cout << "Date- " << "\033[36m" << now->tm_mday << '/' << (now->tm_mon + 1) << '/' << (now->tm_year + 1900) << "\033[0m" << endl;

    cout << "----------------------------------------------" << endl;
    cout << "\033[32mS.No.\tTitle\t\t\tStatus\033[0m" << endl; // Adjusted formatting for the title column
    for (int i = 0; i < count; i++) // Fixed loop to iterate up to 'count'
    {
        cout << a[i].sno << "\t";

        // Print the title, splitting it into multiple lines if it's too long
        string title = a[i].title;
        const int maxTitleLength = 20; // Maximum length of the title before splitting
        int startPos = 0;
        while (startPos < title.length())
        {
            cout << title.substr(startPos, maxTitleLength) << endl;
            startPos += maxTitleLength;

            // Print tabs for alignment with the S.No.
            if (startPos < title.length())
                cout << "\t";
        }

        // Print the status aligned under the "Status" column
        cout << "\t\t\t\t" << a[i].status << endl;
    }
    cout << "----------------------------------------------" << endl;
    cout << endl;
}

void Todo ::mark(int cnt)
{
    cout << "Enter 1 to search by Serial Number" << endl;
    cout << "Enter 2 to search by Title" << endl;
    int c;
    cout << "Enter the Option: ";
    cin >> c;
    if (c == 1)
    {
        int num;
        cout << "Enter the serial number: ";
        cin >> num;
        for (int i = 0; i < cnt; i++)
        {
            if (a[i].sno == num)
            {
                a[i].status = "Done";
                cout<<"\033[32m Task is done ! \033[0m"<<"\n"<<endl;
                return; // Exit loop after marking task as done
            }
        }
        cout << "\033[31m"<<"Task Not Found!\033[0m"<<"\n"<< endl; // Move outside loop
    }
    else if (c == 2)
    {
        string t;
        cout << "Enter the exact title: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, t);
        for (int i = 0; i < cnt; i++)
        {
            if (a[i].title == t)
            {
                a[i].status = "Done";
                cout<<"\033[32m Task is done ! \033[0m"<<"\n"<<endl;
                return; // Exit loop after marking task as done
            }
        }
        cout << "\033[31mTask Not Found!\033[0m"<<"\n"<<endl; // Move outside loop
    }
    else
    {
        cout << "\033[31m Wrong Option!\033[0m" <<"\n"<< endl;
    }
}

void Todo ::del(int ct)
{
    for (int i = 0; i < ct; i++)
    {
        a[i].sno = 0; // Set sno to 0 to indicate task is deleted
        a[i].title = "";
        a[i].status = "";
    }
    cout << "All tasks deleted." << endl;
    cout << endl;
}

int main()
{
    int choice, count = 0;
    cout<<"Welcome To Our To-Do List Application\n "<<endl;
    cout << "\033[1mPress 1 for Adding a task.\033[0m" << endl;
    cout << "\033[1mPress 2 for Viewing all the tasks\033[0m" << endl;
    cout << "\033[1mPress 3 for marking any task as done\033[0m" << endl;
    cout << "\033[1mPress 4 for deleting all the tasks\033[0m" << endl;
    cout << "\033[1mPress 5 for EXIT\033[0m" << endl;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            a[count].add(count);
            count++;
        }
        else if (choice == 2)
        {
            a[count].display(count);
        }
        else if (choice == 3)
        {
            a[count].mark(count);
        }
        else if (choice == 4)
        {
            a[count].del(count);
            count = 0;
        }
        else if (choice == 5)
        {
            exit(0);
        }
        else
        {
            cout << "\033[31mInvalid choice, Try Again!\033[0m \n" << endl;
        }
    }
    return 0;
}