#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

void login();
void registeration();
void forgot();
int main()
{
    cout << "\t\t\t_______________________________________________________\t\t\n";
    cout << "\t\t\t                 WELCOME To Login Page                 \t\t\n";
    cout << "\t\t\t_____________________     MENU     ____________________\t\t\n";
    cout << "\t\t\t                                                       \t\t\n";
    cout << "\t |      For Login Press 1              |" << endl;
    cout << "\t |      For Registration Press 2       |" << endl;
    cout << "\t |      For Forgot password Press 3    |" << endl;
    cout << "\t |      For Exit Press 4               |" << endl;
    cout
        << "\t\nPlease Enter your Choise: ";
    ;
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registeration();
        break;
    case 3:
        forgot();
        break;
    default:
        break;
    }

    return 0;
}
void login()
{
    system("cls");
    int count;
    string susername, spassword, pass, user;
    cout << "Enter Your UserName: ";
    cin >> user;
    cout << "Enter Your Password: ";
    cin >> pass;
    system("cls");
    ifstream f1;
    f1.open("New folder/temp.txt");
    while (f1 >> susername >> spassword)
    {
        if (susername == user && spassword == pass)
        {
            cout << user << "\nlog in Succsefully " << endl;
            main();
        }
        else if (susername != user || spassword != pass)
        {
            cout << endl;
            if (susername == user && spassword == pass)
            {
                cout << user << "\nlog in Succsefully " << endl;
                main();
                cout << endl;
            }
        }
    }

    f1.close();
};
void registeration()
{
    system("cls");
    string username, password;
    cout << "Enter The Username you Want to register with::\n ";
    cin >> username;
    cout << "Enter The Password you Want to register with:\n ";
    cin >> password;
    ofstream f1;
    f1.open("New folder/temp.txt", ios::app);
    f1 << username << " " << password << endl;
    system("cls");
    cout << "REGISTARTION SUCCSEFULL" << endl;
    main();
};
void forgot()
{
    system("cls");
    string susername, spassword, pass, user;
    cout << "Enter Your Name Which you Rembmer to reset your Password: \n";

    cin >> user;
    int count = 0;
    ifstream f1;
    f1.open("temp.txt");

    while (f1 >> susername >> spassword)
    {
        if (user == susername)
        {
            count = 1;
        }
    }
    f1.close();
    if (count == 1)
    {
        cout << "We Found your Account And Your Password is: " << spassword;
    }
    else
    {
        cout << "Sorry We didnt Find your Account :( ";
        main();
    }
};