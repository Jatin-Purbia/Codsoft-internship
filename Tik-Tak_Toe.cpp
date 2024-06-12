#include<iostream>
#include<cstdlib> // For system("clear")
using namespace std;

class Tik
{
public:
    char a[3][3];

    void playx();
    void playo();
    void display();
    int win();
} Tok;

void Tik :: playx()
{
    int x,y;
    cout << "\nPlayer X's turn: ";
    cin >> x >> y;
    if (Tok.a[x-1][y-1]==' ')
    {
        Tok.a[x-1][y-1]='X';
    }
    else
    {
        cout << "Invalid choice, please try again." << endl;
        Tok.playx();
    }
}

void Tik :: playo()
{
    int x,y;
    cout << "\nPlayer O's turn: ";
    cin >> x >> y;
    if (Tok.a[x-1][y-1]==' ')
    {
        Tok.a[x-1][y-1]='O';
    }
    else
    {
        cout << "Invalid choice, please try again." << endl;
        Tok.playo();
    }
}

int Tik :: win()
{
    // checking one diagonal condition
    int d=0,e=0;
    for(int j=0; j<3; j++)
    {
        if(a[j][j]=='X')
            d++;
        else if(a[j][j]=='O')
            e++;
    }
    if(d==3)
    {
        cout << "Player X wins!";
        return 1;
    }
    else if(e==3)
    {
        cout << "Player O wins!";
        return 0;
    }

    // checking other diagonal
    d=0;
    e=0;
    for(int i=0,j=2; i<3 && j>=0 ; i++,j--)
    {
        if(a[i][j]=='X')
            d++;
        else if(a[i][j]=='O')
            e++;
    }
    if(d==3)
    {
        cout << "Player X wins!";
        return 1;
    }
    else if(e==3)
    {
        cout << "Player O wins!";
        return 0;
    }

    // checking horizontal conditions
    for(int i=0; i<3; i++)
    {
        int h=0,g=0;
        for(int j=0; j<3; j++)
        {
            if(a[i][j]=='X')
                h++;
            else if(a[i][j]=='O')
                g++;
        }
        if(h==3)
        {
            cout << "Player X wins!";
            return 1;
        }
        else if(g==3)
        {
            cout << "Player O wins!";
            return 0;
        }
    }

    // checking vertical conditions
    for(int i=0; i<3; i++)
    {
        int h=0,g=0;
        for(int j=0; j<3; j++)
        {
            if(a[j][i]=='X')
                h++;
            else if(a[j][i]=='O')
                g++;
        }
        if(h==3)
        {
            cout << "Player X wins!";
            return 1;
        }
        else if(g==3)
        {
            cout << "Player O wins!";
            return 0;
        }
    }

    // Check for draw
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a[i][j] == ' ')
                return -1; // Game still ongoing
        }
    }
    cout << "It's a draw!";
    return 2;
}

void Tik :: display()
{
    cout << "\n   1 2 3" << endl; // Column labels
    cout << "  -------" << endl; // Upper border
    for(int i=0; i<3; i++)
    {
        cout << i+1 << " |"; // Row labels
        for(int j=0; j<3; j++)
        {
            if(a[i][j] == 'X')
                cout << "\033[1;31mX\033[0m"; // Red X
            else if(a[i][j] == 'O')
                cout << "\033[1;34mO\033[0m"; // Blue O
            else
                cout<< " "; // Empty cell
            cout << " ";
            if(j < 2)
                cout << "|"; // Vertical separator
        }
        cout<<"\n";
        if(i < 2)
            cout << "  -------" << endl; // Horizontal separator
    }
}

int main()
{
    cout << "Welcome to Tic-Tac-Toe!\n";

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            Tok.a[i][j]=' ';
        }
    }
    Tok.display();

    while(1)
    {
        Tok.playx();
        system("clear"); // Clear the screen
        Tok.display();
        int c=Tok.win();
        if (c==1 or c==0 or c == 2)
        {
            break;
        }

        Tok.playo();
        system("clear"); // Clear the screen
        Tok.display();
        c=Tok.win();
        if (c==1 or c==0 or c == 2)
        {
            break;
        }
    }
    
    cout << "\n\nWant to play again (y/n) ?";
    char again;
    cin >> again;
    if (again=='y' or again=='Y')
    {
        main();
    }
    else
    {
        cout << "Thanks for playing!" << endl;
    }
}