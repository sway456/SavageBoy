#include <iostream>

using namespace std;

class Course
{
public:
    Course(const string& courseName, int capacity);

    Course(const Course& other);

    ~Course();

    string getCourseName() const;

    void addStudent(const string& name);

    void dropStudent(const string& name);

    string* getStudents() const;

    int getNumberOfStudents() const;

private:
    string courseName;
    string* students;
    int numberOfStudents;
    int capacity;
};

Course::Course(const string& courseName, int capacity)
{
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity];
}

Course::Course(const Course& other)
{
    numberOfStudents = other.numberOfStudents;
    courseName = other.courseName;
    capacity = other.capacity;
    students = new string[capacity];
    for (int i = 0; i < numberOfStudents; ++i)
    {
        students[i] = other.students[i];
    }
}

Course::~Course()
{
    delete[] students;
}

string Course::getCourseName() const
{
    return courseName;
}

// Add student to the course
void Course::addStudent(const string& name)
{
    students[numberOfStudents] = name;
    numberOfStudents++;
}

void Course::dropStudent(const string& name)
{
    int position = -1;
    for (int i = 0; i < numberOfStudents; ++i)
    {
        if (students[i] == name)
        {
            position = i;
            break;
        }
    }

    if (position != -1)
    {
        for (int i = position; i < numberOfStudents - 1; ++i)
        {
            students[i] = students[i + 1];
        }
        numberOfStudents--;
    }
}

string* Course::getStudents() const
{
    return students;
}

int Course::getNumberOfStudents() const
{
    return numberOfStudents;
}

int main() {
    Course course1("Data Structures", 10);
    Course course2("Database Systems", 15);

    course1.addStudent("Ali");
    course1.addStudent("Ahmed");
    course1.addStudent("Imran");

    course2.addStudent("Rizwan");
    course2.addStudent("Akeel");

    cout << "Number of students in course1: " << course1.getNumberOfStudents() << "\n";

    string* students = course1.getStudents();
    for (int i = 0; i < course1.getNumberOfStudents(); i++)
        cout << students[i] << ", ";
    cout << endl;

    Course course3(course1);

    course3.dropStudent("Ali");

    cout << "Number of students in course 3 after dropping Ali: " << course3.getNumberOfStudents() << "\n";

    students = course3.getStudents();
    for (int i = 0; i < course3.getNumberOfStudents(); i++)
        cout << students[i] << ", ";
    cout << "\n";

    return 0;
}
