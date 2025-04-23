#include <iostream>
#include <map>
#include <string>
using namespace std;

class student {
private:
    int roll, age, mark;
    string name;

public:
    student() : roll(0), name(""), age(0), mark(0) {}  // Default constructor

    student(int roll, std::string name, int age, int mark) {
        this->roll = roll;
        this->name = name;
        this->age = age;
        this->mark = mark;
    }

    void datadisplay() const {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Mark: " << mark << endl;
    }
};

int main() {
    map<int, student> studentdata;
    int choice;
    char value;
   
    cout<<endl<<endl << "-----||WELCOME TO STUDENT MANAGEMENT SYSTEM||------" << endl << endl << endl;

    do {
        cout << "1.ENTER DETAILS" << endl << endl;
        cout << "2.SEARCH DETAILS" << endl << endl;
        cout << "3.UPDATE DETAILS" << endl << endl;
        cout << "4.DELETE DETAILS" << endl << endl;
        cout << "5.EXIT" << endl << endl;
        cout << "PLEASE ENTER YOUR CHOICE: ";
        cin >> choice;
         cout<<endl;
        if (choice == 1) {
         cout<<" ----ENTER YOUR DETAILS----"<<endl<<endl;
            int roll, age, mark;
            string name;
            cout << "Enter roll: ";
            cin >> roll;
            cin.ignore();  // Ignore the newline character left by std::cin
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter mark: ";
            cin >> mark;

            student stu(roll, name, age, mark);
            studentdata[roll] = stu;
            cout << "STUDENT DETAILS ENTERED SUCCESSFULLY" << endl << endl;
        }
        else if (choice == 2) {
         cout<<" ----THE DETAILS ARE----"<<endl;
            for (const auto& it : studentdata) {
                it.second.datadisplay();
            }
        }
        else if (choice == 3) {
            int roll;
            cout << "Enter the roll of the student: ";
            cin >> roll;
            cin.ignore();  // Ignore the newline character left by std::cin

            if (studentdata.find(roll) != studentdata.end()) {
                int new_roll, age, mark;
                std::string name;
                cout << "Enter new roll: ";
                cin >> new_roll;
                cin.ignore();  // Ignore the newline character left by std::cin
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new age: ";
                cin >> age;
                cout << "Enter new mark: ";
                cin >> mark;

                studentdata[roll] = student(new_roll, name, age, mark);
                cout << "STUDENT DETAILS UPDATED SUCCESSFULLY" << endl << endl;
            }
            else {
                cout << "Student with roll " << roll << " is not present";
            }
        }
        else if (choice == 4) {
            int roll;
            cout << "Enter the roll: ";
            cin >> roll;
            if (studentdata.find(roll) != studentdata.end()) {
                studentdata.erase(roll);
                cout << "STUDENT DETAILS DELETED SUCCESSFULLY" << endl << endl;
            }
            else {
                cout << "Student with roll " << roll << " is not present";
            }
        }
        else if (choice == 5) {
            cout << " SYSTEM EXIT" << endl;
            cout << "------GOODBYE--------";
            break;
        }
        else {
            cout << "Invalid Choice: ";
        }
        cout << "DO YOU LOOK FOR MORE OPERATION:(Y/N) ";
        cin >> value;
        cout<<endl<<endl;

    } while (value == 'y'||value == 'Y');
    if(choice!=5){
          cout << " SYSTEM EXIT" << endl;
            cout << "------GOODBYE--------"<<endl<<endl;

    }
     
    return 0;
}