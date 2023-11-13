#include "colors.hpp"

#define red colors::bright_red
#define blue colors::bright_cyan
#define yellow colors::bright_yellow
#define green colors::bright_green
#define reset colors::reset

using namespace std;

class bca_stdata
{
public:
    void setstudentdata(string, string, string, string); //---> to set a student's data and make a new entry
    void displaystudentdata();                           //---> to display the list of students and their data
    void stid_display(string);                           //---> to display a specific student's data
};

class mca_stdata
{
public:
    void setstudentdata(string, string, string, string); //---> to set a student's data and make a new entry
    void displaystudentdata();                           //---> to display the list of students and their data
    void stid_display(string);                           //---> to display a specific student's data
};

void bca_stdata::setstudentdata(string name, string id, string course, string email)
{
    ofstream fo("Storage/bca_student.txt", ios::app);
    if (!fo)
        cout << red << "Error entering the data!\n" << reset;
    else
    {
        // using setw() from iomanip header file to align the text in storage files
        fo << setw(4) << id << " | " << setw(18) << name << " | " << setw(6) << course << " | " << setw(24) << email << endl;
        cout << green << "\nData entered sucessfully!!!\n\n" << reset;
    }
    fo.close();
}

void bca_stdata::displaystudentdata()
{
    string line;
    ifstream fi("Storage/bca_student.txt");
    cout << blue << "List of Students :\n\n";
    if (!fi)
        cout << red << "Error fetching details!\n" << reset;
    else
    {
        // printing the whole text file
        while (getline(fi, line))
        {
            cout << yellow << line << endl;
        }
        cout << endl;
    }
}

void bca_stdata::stid_display(string id)
{
    string line;
    fstream f("Storage/bca_student.txt");

    if (!f)
    {
        cout << red << "Error fetching details!\n" << reset;
    }
    else
    {
        while (getline(f, line)) // reads/traverses every line of the text file
        {
            if (line.find(id) != string::npos) // searches & if finds the id in the line in iteration
            {
                cout << yellow << "\n  ID |               NAME | COURSE |            EMAIL ADDRESS\n" << line << "\n\n";
                break;
            }
        }
        if (line.find(id) == string::npos) // if find function returns (string::npos)
        {
            cout << red << "\nNo such record found!\n\n" << reset;
        }
    }

    f.close();
}

// concepts same as bca member functions are used here

void mca_stdata::setstudentdata(string name, string id, string course, string email)
{
    ofstream fo("Storage/mca_student.txt", ios::app);
    if (!fo)
        cout << red << "Error entering the data!\n" << reset;
    else
    {
        fo << setw(4) << id << " | " << setw(18) << name << " | " << setw(6) << course << " | " << setw(24) << email << endl;
        cout << green << "\nData entered sucessfully!!!\n\n" << reset;
    }
    fo.close();
}

void mca_stdata::displaystudentdata()
{
    string line;
    ifstream fi("Storage/mca_student.txt");
    cout << blue << "List of Students :\n\n";
    if (!fi)
        cout << red << "Error fetching details!\n" << reset;
    else
    {
        while (getline(fi, line))
        {
            cout << yellow << line << endl;
        }
        cout << endl;
    }
}

void mca_stdata::stid_display(string id)
{
    string line;
    fstream f("Storage/mca_student.txt");

    if (!f)
    {
        cout << red << "Error fetching details!\n" << reset;
    }
    else
    {
        while (getline(f, line))
        {
            if (line.find(id) != string::npos)
            {
                cout << yellow << "\n  ID |               NAME | COURSE |            EMAIL ADDRESS\n"
                     << line << "\n\n";
                break;
            }
        }
        if (line.find(id) == string::npos)
        {
            cout << red << "\nNo such record found!\n\n" << reset;
        }
    }

    f.close();
}