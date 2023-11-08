#include <bits/stdc++.h>

// including user defined header files
#include "student.h"
#include "faculty.h"

// Defining colors
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

using std::cin, std::cout, std::endl, std::string;

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

    cout << BLUE << "\n==========================================\n";
    cout << "Welcome to College Management System (CMS)\n";
    cout << "==========================================\n\n" << RESET;

    int user;
    cout << "Who are you?\n";
    cout << "(1) Head of Department (HoD)\n";
    cout << "(2) Coordinator\n";
    cout << "(3) Faculty\n";
    cout << "(4) Exit\n";
    cin >> user;

    if (user == 4)
    {
        cout << RED << "Exiting the system. Goodbye!\n" << RESET;
        return 0;
    }

    const string *correctPassword;   // pointer to the passwords of different roles
    
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
        cout << RED << "Enter a valid choice!\n"
             << RESET;
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
            cout << "Enter your password to access the software:\n";
            cin >> pass;
        }
        else if (tries > 1)
        {
            cout << endl << BLUE << "Try again:\n" << RESET;
            cin >> pass;
        }

        if (tries == 5)
        {
            // exiting the program when the try limit is exceeded
            cout << RED << "You have exceeded 5 tries, the application is locked for this session!\n" << RESET;
            break;
        }

        if (pass == *correctPassword)
        {
            int ch;

            do
            {
                // selecting the department/section
                cout << BLUE << "\nSelect the department:\n";
                cout << "(1) BCA\n";
                cout << "(2) MCA\n";
                cout << RED << "(3) Exit\n" << RESET;
                cin >> ch;

                if (ch == 1 || ch == 2)
                {
                    char department_choice;
                    do
                    {
                        // list of actions
                        cout << BLUE << "Select the action to perform:\n";
                        cout << "(1) Show all student data\n";
                        cout << "(2) Show all faculty data\n";
                        if (canEnterStudentData)
                            cout << "(3) Enter student data\n";
                        if (canEnterFacultyData)
                            cout << "(4) Enter faculty data\n";
                        cout << "(5) Display data of a specific identity of student\n";
                        cout << "(6) Display data of a specific identity of faculty\n";
                        cout << RED << "(7) Exit this section\n" << RESET;
                        cin >> department_choice;
                        
                        // ----------------------------THE CORE OF THE PROGRAM----------------------------
                        // calling the respective functions upon the choice made
                        switch (department_choice)
                        {
                        case '1':
                            (ch == 1 ? st.displaystudentdata() : st1.displaystudentdata());
                            break;

                        case '2':
                            (ch == 1 ? fc.displayfacultydata() : fc1.displayfacultydata());
                            break;

                        case '3':
                            if (canEnterStudentData)
                            {
                                getStudentInput(name, id, course, email);
                                (ch == 1 ? st.setstudentdata(name, id, course, email) : st1.setstudentdata(name, id, course, email));
                            }
                            else
                                cout << RED << "You are not allowed to enter student data!\n" << RESET;
                            break;

                        case '4':
                            if (canEnterFacultyData)
                            {
                                getFacultyInput(name, id, course, email);
                                (ch == 1 ? fc.setfacultydata(name, id, course, email) : fc1.setfacultydata(name, id, course, email));
                            }
                            else
                                cout << RED << "You are not allowed to enter faculty data!\n" << RESET;
                            break;

                        case '5':
                            cout << BLUE << "Enter any detail of the student (ID, Name, Email address):\n";
                            cin >> st_id;
                            (ch == 1 ? st.stid_display(st_id) : st1.stid_display(st_id));
                            break;

                        case '6':
                            cout << BLUE << "Enter any detail of the faculty (ID, Name, Email address):\n";
                            cin >> fc_id;
                            (ch == 1 ? fc.fcid_display(fc_id) : fc1.fcid_display(fc_id));
                            break;

                        case '7':
                            cout << RED << "Exiting this section!\n" << RESET;
                            break;

                        default:
                            cout << RED << "Please enter a valid choice!\n" << RESET;
                            break;
                        }
                    } while (department_choice != '7');
                }
                else if(ch == 3)
                {
                    cout << RED << "Exiting the system. Goodbye!\n" << RESET;
                }
                else
                {
                    cout << RED << "Please enter a valid choice!\n" << RESET;
                }
            } while (ch != 3);
        }
        else
        {
            cout << RED << "Incorrect password!\n" << RESET;
        }
    } while (pass != *correctPassword);

    return 0;
}

// definition of input functions
void getStudentInput(string &name, string &id, string &course, string &email)
{
    cout << BLUE << "Enter the student full name: ";
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
    cout << GREEN << "Enter the faculty full name: ";
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