#include <bits/stdc++.h>
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

using namespace std;

class bca_fcdata
{
public:
    void setfacultydata(string, string, string, string); //---> to set a faculty's data and make a new entry
    void displayfacultydata();                           //---> to display the list of facultys and their data
    void fcid_display(string);                           //---> to display a specific faculty's data
};

class mca_fcdata
{
public:
    void setfacultydata(string, string, string, string); //---> to set a faculty's data and make a new entry
    void displayfacultydata();                           //---> to display the list of facultys and their data
    void fcid_display(string);                           //---> to display a specific faculty's data
};

void bca_fcdata::setfacultydata(string name, string id, string course, string email)
{
    ofstream f("Storage/bca_faculty.txt", ios::app);
    if (!f)
        cout << RED << "Error entering the data!\n" << RESET;
    else
    {
        f << setw(4) << id << " | " << setw(18) << name << " | " << setw(6) << course << " | " << setw(24) << email << endl;
        cout << GREEN << "Data entered sucessfully!\n";
    }
    f.close();
}

void bca_fcdata::displayfacultydata()
{
    string line;
    ifstream fi("Storage/bca_faculty.txt");
    cout << BLUE << "List of Faculty :\n\n";
    if (!fi)
        cout << RED << "Error fetching details!\n" << RESET;
    else
    {
        while (getline(fi, line))
        {
            cout << YELLOW << line << endl;
        }
        cout << endl;
    }
}

void bca_fcdata::fcid_display(string id)
{
    string line;
    fstream f("Storage/bca_faculty.txt");

    if (!f)
    {
        cout << RED << "Error fetching details!\n" << RESET;
    }
    else
    {
        while (getline(f, line))
        {
            if (line.find(id) != string::npos)
            {
                cout << YELLOW << "\n  ID |               NAME | COURSE |            EMAIL ADDRESS\n"
                     << line << "\n\n";
                break;
            }
        }
        if (line.find(id) == string::npos)
        {
            cout << RED << "\nNo such record found!\n\n" << RESET;
        }
    }

    f.close();
}

void mca_fcdata::setfacultydata(string name, string id, string course, string email)
{
    ofstream f("Storage/mca_faculty.txt", ios::app);
    if (!f)
        cout << RED << "Error entering the data!\n" << RESET;
    else
    {
        f << setw(4) << id << " | " << setw(18) << name << " | " << setw(6) << course << " | " << setw(24) << email << endl;
        cout << GREEN << "Data entered sucessfully!\n";
    }
    f.close();
}

void mca_fcdata::displayfacultydata()
{
    string line;
    ifstream fi("Storage/mca_faculty.txt");
    cout << BLUE << "List of Faculty :\n\n";
    if (!fi)
        cout << RED << "Error fetching details!\n" << RESET;
    else
    {
        while (getline(fi, line))
        {
            cout << YELLOW << line << endl;
        }
        cout << endl;
    }
}

void mca_fcdata::fcid_display(string id)
{
    string line;
    fstream f("Storage/mca_faculty.txt");

    if (!f)
    {
        cout << RED << "Error fetching details!\n" << RESET;
    }
    else
    {
        while (getline(f, line))
        {
            if (line.find(id) != string::npos)
            {
                cout << YELLOW << "\n  ID |               NAME | COURSE |            EMAIL ADDRESS\n"
                     << line << "\n\n";
                break;
            }
        }
        if (line.find(id) == string::npos)
        {
            cout << RED << "\nNo such record found!\n\n" << RESET;
        }
    }

    f.close();
}