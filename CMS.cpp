#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// including user defined header files
#include "student.h"
#include "faculty.h"

// including colors library to use windows terminal supported colors in output stream
#include "colors.hpp"

// Defining colors
#define red colors::bright_red
#define green colors::bright_green
#define blue colors::bright_cyan
#define bold colors::bold
#define bold colors::bold

using std::cin;
using std::cout;
using std::endl;
using std::string;

// functions to get the user input to make an entry
void getStudentInput(string &name, string &id, string &course, string &email);
void getFacultyInput(string &name, string &id, string &course, string &email);

int main()
{

    // Passwords for different roles
    const string hodPassword = "hod123";
    const string coordinatorPassword = "coordinator456";
    const string facultyPassword = "faculty789";

    // object declaration of classes in "student.h" and "faculty.h"
    bca_fcdata fc;
    bca_stdata st;
    mca_fcdata fc1;
    mca_stdata st1;

    // variables to take input from the uesr
    string name, id, course, email, st_id, fc_id;

    cout << green << bold << "\n==========================================\n"
                    << "Welcome to College Management System (CMS)\n"
                    << "==========================================\n\n" << reset;

    // asking user their role in the college
    int user;
    cout << blue << "Who are you?\n\n";
    cout << "(1) Head of Department (HoD)\n";
    cout << "(2) Coordinator\n";
    cout << "(3) Faculty\n";
    cout << red << "(4) Exit\n" << reset;
    cin >> user;

    // if user chooses 4, return 0 (exit the program)
    if (user == 4)
    {
        cout << red << "Exiting the system. Goodbye!\n" << reset;
        return 0;
    }

    // pointer to the passwords of different roles
    const string *correctPassword;
    
    // limitations given for low authority roles
    bool canEnterFacultyData = true;
    bool canEnterStudentData = true;

    // setting password and limitations
    switch (user)
    {
    case 1:
        correctPassword = &hodPassword;
        break;
    case 2:
        correctPassword = &coordinatorPassword;
        canEnterFacultyData = false;
        break;
    case 3:
        correctPassword = &facultyPassword;
        canEnterStudentData = false;
        canEnterFacultyData = false;
        break;
    default:
        cout << red << "Enter a valid choice!\n"
             << reset;
        exit(0);
    }

    string pass;
    int tries = 0;

    // External do-while loop
    do
    {
        // password check logic starts here
        tries++;
        if (tries == 1)
        {
            cout<< blue << "Enter the password to authenticate yourself:\n" << reset;
            cin >> pass;
        }
        else if (tries > 1)
        {
            cout << endl << blue << "Try again:\n" << reset;
            cin >> pass;

            // exiting the program when the try limit is exceeded
            if (tries == 5)
            {
                cout << red << "You have exceeded the trial limit, the application is locked for this session!\n" << reset;
                return 0;
            }
        }

        if (pass == *correctPassword)
        {
            int ch;

            do
            {
                // selecting the department/section
                cout << blue << "\nSelect the department:\n\n";
                cout << "(1) BCA\n";
                cout << "(2) MCA\n";
                cout << red << "(3) Exit\n" << reset;
                cin >> ch;

                if (ch == 1 || ch == 2)
                {
                    char department_choice;
                    do
                    {
                        // list of actions
                        cout << blue << "\nSelect the action to perform:\n\n";
                        cout << "(1) Show all student data\n";
                        cout << "(2) Show all faculty data\n";
                        if (canEnterStudentData)
                            cout << "(3) Enter student data\n";
                        if (canEnterFacultyData)
                            cout << "(4) Enter faculty data\n";
                        cout << "(5) Display data of a specific identity of student\n";
                        cout << "(6) Display data of a specific identity of faculty\n";
                        cout << red << "(7) Exit this section\n" << reset;
                        cin >> department_choice;
                        

                        // ----------------------------THE CORE OF THE PROGRAM----------------------------


                        // calling the respective functions upon the choice made
                        switch (department_choice)
                        {
                        case '1':
                            // call func from st(BCA) object if the user chose bca else call func from st2(MCA)
                            (ch == 1 ? st.displaystudentdata() : st1.displaystudentdata());
                            break;

                        case '2':
                            // call func from fc(BCA) object if the user chose bca else call func from fc2(MCA)
                            (ch == 1 ? fc.displayfacultydata() : fc1.displayfacultydata());
                            break;

                        case '3':
                            if (canEnterStudentData)
                            {
                                getStudentInput(name, id, course, email);
                                // add the data to BCA if user chose BCA else MCA
                                (ch == 1 ? st.setstudentdata(name, id, course, email) : st1.setstudentdata(name, id, course, email));
                            }
                            else
                                // show warning message if user is a faculty
                                cout << red << "\nYou are not allowed to enter student data!\n" << reset;
                            break;

                        case '4':
                            if (canEnterFacultyData)
                            {
                                getFacultyInput(name, id, course, email);
                                // add the data to BCA if user chose BCA else MCA
                                (ch == 1 ? fc.setfacultydata(name, id, course, email) : fc1.setfacultydata(name, id, course, email));
                            }
                            else
                                // show warning message if user is either a faculty or a coordinator
                                cout << red << "\nYou are not allowed to enter faculty data!\n" << reset;
                            break;

                        case '5':
                            cout << blue << "\nEnter any detail of the student (ID, Name, Email address):\n";
                            cin >> st_id;
                            (ch == 1 ? st.stid_display(st_id) : st1.stid_display(st_id));
                            break;

                        case '6':
                            cout << blue << "\nEnter any detail of the faculty (ID, Name, Email address):\n";
                            cin >> fc_id;
                            (ch == 1 ? fc.fcid_display(fc_id) : fc1.fcid_display(fc_id));
                            break;

                        case '7':
                            cout << red << "\nExiting this section!\n" << reset;
                            break;

                        default:
                            cout << red << "\nPlease enter a valid choice!\n" << reset;
                            break;
                        }
                    } while (department_choice != '7');
                }
                else if(ch == 3)
                {
                    cout << red << "\nExiting the system. Goodbye!\n" << reset;
                }
                else
                {
                    cout << red << "\nPlease enter a valid choice!\n" << reset;
                }
            } while (ch != 3); // loop runs until the user doesn't select exit (3)
        }
        else
        {
            cout << red << "\nIncorrect password!\n" << reset;
        }
    } while (pass != *correctPassword);

    return 0;
}

// definition of input functions
void getStudentInput(string &name, string &id, string &course, string &email)
{
    cout << blue << "\nEnter the student full name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the student ID: ";
    cin >> id;
    cout << "Enter the student Course: ";
    cin >> course;
    cout << "Enter the student Email Address: ";
    cin.ignore();
    getline(cin, email);
}

void getFacultyInput(string &name, string &id, string &course, string &email)
{
    cout << green << "\nEnter the faculty full name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the faculty ID: ";
    cin >> id;
    cout << "Enter the faculty Department: ";
    cin >> course;
    cout << "Enter the faculty Email Address: ";
    cin.ignore();
    getline(cin, email);
}