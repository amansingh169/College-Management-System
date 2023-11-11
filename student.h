#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

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
        cout << RED << "Error entering the data!\n" << RESET;
    else
    {
        // using setw() from iomanip header file to align the text in storage files
        fo << setw(4) << id << " | " << setw(18) << name << " | " << setw(6) << course << " | " << setw(24) << email << endl;
        cout << GREEN << "\nData entered sucessfully!!!\n\n" << RESET;
    }
    fo.close();
}

void bca_stdata::displaystudentdata()
{
    string line;
    ifstream fi("Storage/bca_student.txt");
    cout << BLUE << "List of Students :\n\n";
    if (!fi)
        cout << RED << "Error fetching details!\n" << RESET;
    else
    {
        // printing the whole text file
        while (getline(fi, line))
        {
            cout << YELLOW << line << endl;
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
        cout << RED << "Error fetching details!\n" << RESET;
    }
    else
    {
        while (getline(f, line)) // reads/traverses every line of the text file
        {
            if (line.find(id) != string::npos) // searches & if finds the id in the line in iteration
            {
                cout << YELLOW << "\n  ID |               NAME | COURSE |            EMAIL ADDRESS\n" << line << "\n\n";
                break;
            }
        }
        if (line.find(id) == string::npos) // if find function returns (string::npos)
        {
            cout << RED << "\nNo such record found!\n\n" << RESET;
        }
    }

    f.close();
}

// concepts same as bca member functions are used here

void mca_stdata::setstudentdata(string name, string id, string course, string email)
{
    ofstream fo("Storage/mca_student.txt", ios::app);
    if (!fo)
        cout << RED << "Error entering the data!\n" << RESET;
    else
    {
        fo << setw(4) << id << " | " << setw(18) << name << " | " << setw(6) << course << " | " << setw(24) << email << endl;
        cout << GREEN << "\nData entered sucessfully!!!\n\n" << RESET;
    }
    fo.close();
}

void mca_stdata::displaystudentdata()
{
    string line;
    ifstream fi("Storage/mca_student.txt");
    cout << BLUE << "List of Students :\n\n";
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

void mca_stdata::stid_display(string id)
{
    string line;
    fstream f("Storage/mca_student.txt");

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