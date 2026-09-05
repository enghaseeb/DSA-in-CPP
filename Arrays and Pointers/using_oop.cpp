#include<iostream>
using namespace::std;

class Employee {
protected: 
    string name;
    string address;

public:
    Employee(string empName, string empAddress) {
        name = empName;
        address = empAddress;
    }


    void display() {
        cout << "Name: " << name << " | Address: " << address << endl;
    }
};

class Salaried_Emp : public Employee {
private:
    double monthlySalary;

public:
    Salaried_Emp(string empName, string empAddress, double salary) 
        : Employee(empName, empAddress) {
        monthlySalary = salary;
    }

    void calculate_salary() {
        cout << "Salary of salaried employee (" << name << "): $" << monthlySalary << endl;
    }
};

class Hourly_Emp : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    Hourly_Emp(string empName, string empAddress, double rate, int hours) 
        : Employee(empName, empAddress) {
        hourlyRate = rate;
        hoursWorked = hours;
    }

    void calculate_salary() {
        double salary = hourlyRate * hoursWorked;
        cout << "Salary of hourly paid employee (" << name << "): $" << salary << endl;
    }
};

int main(){
	Employee e1("Haseeb", "Takht Bhai");
    Employee e2("Yahya", "Takht Bhai");
    Employee e3("Sami", "Katlang");
    
    e1.display();
    e2.display();
    e3.display();
    cout << endl;

    // Creating derived class objects
    Salaried_Emp em1("Alice", "Street 1", 3500.0);
    em1.calculate_salary();

    Hourly_Emp em2("Bob", "Street 2", 25.0, 40);
    em2.calculate_salary();

    return 0;
}
