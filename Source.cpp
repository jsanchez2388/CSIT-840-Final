#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class Student 
{
protected:
	string ID;
	string name;
	int units;
	double gpa;
public:
	Student();
	Student(const Student&);
	~Student();
	virtual Student& operator=(const Student&);
	virtual bool operator!=(const Student&) const;
	virtual void read();
	virtual const void print() const;
};

class Student_worker :public Student
{
private:
	int weekly_hours;
	double hourly_wage;
public:
	Student_worker();
	Student_worker(const Student_worker&);
	~Student_worker();
	Student_worker& operator=(const Student_worker&);
	bool operator!=(const Student_worker&) const;
	void read();
	const void print() const;
};

int main()
{
	Student *students[100];
	Student *temp;
	char student;
	char studentWorker;
	int instance = 0;
	do
	{
		cout << "Enter a student?: ";
		cin >> student;
		student = toupper(student);
		if (student != 'Y')
			break;
		cout << "Is this a student worker? (y/n): ";
		cin >> studentWorker;
		studentWorker = toupper(studentWorker);
		if (studentWorker != 'Y')
		{
			temp = new Student;
		}
		else
		{
			temp = new Student_worker;
		}
		temp->read();
		
		students[instance] = temp;
		instance++;
	} while (instance < 100);

	if (instance == 100)
		cout << "You've entered the maximum number of students allowed\n";
	
	if (instance < 1)
		cout << "\nNo students were entered\n";
	else
	{
		cout << "\nYou created the following students:\n";

		for (int idx = 0; idx < instance; idx++)
			students[idx]->print();

		for (int idx = 0; idx < instance; idx++)
			delete students[idx];
	}
	_getch();
	return 0; 
}

Student::Student()
{
	ID = "";
	name = "";
	units = 0;
	gpa = 0.0;
}

Student::Student(const Student &s)
{
	ID = s.ID;
	name = s.name;
	units = s.units;
	gpa = s.gpa;
}

Student::~Student()
{
}

Student & Student::operator=(const Student &s)
{
	if (s != *this)
	{
		ID = s.ID;
		name = s.name;
		units = s.units;
		gpa = s.gpa;
	}
	return *this;
}

bool Student::operator!=(const Student &s) const
{
	if (ID != s.ID && name != s.name && units != s.units && gpa != s.gpa)
		return true;
	else
		return false;
}

void Student::read()
{
	string fName;
	string lName;
	int nSpaces = 0;
	cout << "Enter ID, name, units and GPA:\n";
	cin >> ID;
	cin >> fName;
	cin >> lName;
	cin >> units;
	cin >> gpa;

	name += fName + " " + lName;
}

const void Student::print() const
{
	cout << name << ", ID:" << ID << " units:" << units << ", GPA:" << gpa << endl;
}

Student_worker::Student_worker()
{
	Student::Student();
	weekly_hours = 0;
	hourly_wage = 0.0;
}

Student_worker::Student_worker(const Student_worker &sw)
{
	ID = sw.ID;
	name = sw.name;
	units = sw.units;
	gpa = sw.gpa;
	weekly_hours = sw.weekly_hours;
	hourly_wage = sw.hourly_wage;
}

Student_worker::~Student_worker()
{
}

Student_worker & Student_worker::operator=(const Student_worker &sw)
{
	if (sw != *this)
	{
		ID = sw.ID;
		name = sw.name;
		units = sw.units;
		gpa = sw.gpa;
		weekly_hours = sw.weekly_hours;
		hourly_wage = sw.hourly_wage;
	}
	return *this;
}

bool Student_worker::operator!=(const Student_worker &s) const
{
	if (Student::operator!=(s) && weekly_hours != s.weekly_hours && hourly_wage != s.hourly_wage)
	{
		return true;
	}
	else
		return false;
}

void Student_worker::read()
{
	Student::read();
	cout << "Enter weekly hours: ";
	cin >> weekly_hours;
	cout << "Enter hourly wage: ";
	cin >> hourly_wage;
}

const void Student_worker::print() const
{
	Student::print();
	cout << "Weekly Hour: " << weekly_hours << ", hourly wages:" << hourly_wage << endl;
}
