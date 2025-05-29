#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    string name;
    int roll;
    float mark;

    student() : name(""), roll(0), mark(0.0f) {}

    student(string n, int r, float m)
    {
        name = n;
        roll = r;
        mark = m;
    }
};

vector<student> students;

void lodFail()
{
    ifstream file("students.txt", ios::in);
    if (!file)
    {
        cerr << "Error opening file." << endl;
        return;
    }
    student s;
    while (file >> s.name >> s.roll >> s.mark)
    {
        students.push_back(s);
    }
    file.close();
}

void saveToFile()
{
    ofstream file("students.txt", ios::out);
    if (!file)
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (const auto &s : students)
    {
        file << s.name << " " << s.roll << " " << s.mark << endl;
    }
    file.close();
}

void addStudent()
{
    string name;
    int roll;
    float mark;

    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Mark: ";
    cin >> mark;
    students.push_back(student(name, roll, mark));
    saveToFile();
    system("clear");
    cout << "Student Added Successfully!" << endl;
}

void updateStudent()
{
    int roll;
    cout << "Enter Roll Number to Update Student: ";
    cin >> roll;

    bool found = false;
    for (auto &s : students)
    {
        if (s.roll == roll && found == false)
        {
            found == true;

            cout << "1 - Update Name" << endl
                 << "2 - Update Mark" << endl;
            int choice;
            cout << "Enter Your Choice: ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter New Name: ";
                cin >> s.name;
                cout << "Update New Name Successfully!" << endl;
            }
            else if (choice == 2)
            {
                cout << "Enter New Mark: ";
                cin >> s.mark;
                cout << "Update New Mark Successfully!" << endl;
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
        }
    }
}

void displayStudents()
{
    system("clear");
    if (students.empty())
    {
        cout << "No students found." << endl;
        return;
    }
    for (auto &s : students)
    {
        cout << "Name: " << s.name << ", Roll Number: " << s.roll << ", Mark: " << s.mark << endl;
    }
    cout << endl
         << endl;
}

void searchStudent()
{
    int roll;
    cout << "Enter Roll Number to Search Student: ";
    cin >> roll;
    bool f = false;
    for (auto &s : students)
    {
        if (f == true)
        {
            break;
        }
        if (s.roll == roll)
        {
            system("clear");
            f = true;
            cout << "Name : " << s.name << " , Roll Number: " << s.roll << " , Mark: " << s.mark << endl
                 << endl
                 << endl;
        }
        else
        {
            cout << "Student with Roll Number " << roll << " not found." << endl;
        }
    }
}

void deleteStudent()
{
    int roll;
    cout << "Enter Roll Number to Delete Student: ";
    cin >> roll;
    auto it = remove_if(students.begin(), students.end(), [roll](const student &s)
                        { return s.roll == roll; });
    if (it != students.end())
    {
        students.erase(it, students.end());
        saveToFile();
        cout << "Student with Roll Number " << roll << " deleted successfully." << endl;
    }
    else
    {
        cout << "Student with Roll Number " << roll << " not found." << endl;
    }
}

void menu()
{
    while (true)
    {
        cout << "1 - Add Student" << endl
             << "2 - Display Students" << endl
             << "3 - Search Student" << endl
             << "4 - Delete Student" << endl
             << "5 - Update Student" << endl
             << "6 - Exit" << endl;
        int choice;
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addStudent();
        }
        else if (choice == 2)
        {
            displayStudents();
        }
        else if (choice == 3)
        {
            searchStudent();
        }
        else if (choice == 4)
        {
            deleteStudent();
            saveToFile();
        }
        else if (choice == 5)
        {
            updateStudent();
            saveToFile();
        }
        else if (choice == 6)
        {
            cout << "Exiting the program." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

int main()
{
    lodFail();
    menu();

    return 0;
}