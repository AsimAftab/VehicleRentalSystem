#include <iostream>
#include <cstdlib>
#include<fstream>
#include <cstdio>
#include <string>
#include<cstring>
//#include "../include/color.hpp"
#include <ctime>

//Included libraries
int loginAttempt = 0;
using namespace std;

void admin_menu();

void menu();

void authentication();
//Do not remove right now
/*int countUser();

int countUser() {
    int numOfCust = 0;
    ifstream ifs("authentication.txt");
    string word;
    while (getline(ifs, word)) {
        if (!word.empty())
            numOfCust++;
    }
    return numOfCust;
}*/
//Main menu to Admin Menu Authentication
void authentication() {
    string check;
    string username, pass;

    while (loginAttempt <=2) {
        cout << endl << "Please enter your username: " << endl;
        cin >> username;
/*        cout << username << endl;*/
        cout << endl << "Please enter your user password: ";
        cin >> pass;
        /*     cout << pass << endl;*/
        fstream read("authentication.txt", ios::in);
        if (!read) {
            cout << "Failed to read";
        }
        read >> check;
        /*cout << check;*/ //Debugging whether file is being read or not
        bool is_usernameFound = check.find(username) != string::npos;
        bool is_passwordFound = check.find(pass) != string::npos;

        if (is_usernameFound && is_passwordFound) {
            cout << endl << "\n\t   \t\t\t\t\t\t\t\t\t\t ----------------------------" << endl;
            cout << endl << "\n\t   \t\t\t\t\t\t\t\t\t  Logged in Successfully! \U0001F680 \U0001F680 \U0001F680 " << endl;
            admin_menu();
        } else {
            cout << endl << "\n\t   \t\t\t\t\t\t\t ----------------------------" << endl;
            cout << endl << "\n\t   \t\t\t\t\t\t\t\t\t  Log in detail Incorrect! \U0001F625 \U0001F625 \U0001F625" << endl;
            loginAttempt++;


        }
        if (loginAttempt == 3) {
            cout << endl<<"Too many login attempts! The program will now terminate." << endl;


        } else {
            authentication();

        }


    }

}


void admin_menu() {

    int choice;
    cout << ("\n1.New Admin \n2.Add vehicles \n3.Delete Vehicles \n4.Display \n5.Main Menu\n");
    cout << ("\nEnter your choice:");
    cin >> choice;
    if (choice == 2) {
        /*dd_vehicle();*/
    } else if (choice == 5) {
        menu();
    }

}

void menu() {
    int choice;
    // cout<<endl;
    cout << endl << "\n\t   \t\t\t\t\t\t\t ----------------------------" << endl;
    cout << endl << "\n\t   \t\t\t\t\t\t\t\t\t   Main Menu   " << endl;
    time_t now = time(nullptr);
    string dt = ctime(&now);
    cout << "\n\t   \t\t\t\t\t\t\t\t   Current Date:/time: " << dt << endl;
    cout << endl << "\n\t   \t\t\t\t\t\t\t ----------------------------" << endl;
    cout << "\n\t   \t\t\t\t\t\t\t\t     1.  ADMIN   " << endl;
    cout << "\n\t   \t\t\t\t\t\t\t\t     2.  USER   " << endl;
    cout << "\n\t   \t\t\t\t\t\t\t\t     3.  EXIT   " << endl;

    cout << "\n\t   \t\t\t\t\t\t\t\t   ENTER YOUR CHOICE :    ";
    cin >> choice;
    if (choice == 1) {
        authentication();
    } else if (choice == 2) {
        //menu();
    } else if (choice == 3) {
        exit(0);
    }
}

/*
void art();
void gotoxy(int,int);

typedef struct COORD{
    short X;
    short Y;
}COORD,*PCOORD;
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsole
}
void art()
{
    gotoxy(0,20);


}
*/

int main() {
    menu();
    return 0;
}
