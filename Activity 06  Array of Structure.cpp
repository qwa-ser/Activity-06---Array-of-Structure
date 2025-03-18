#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    float gpa;
};

int addStudent(Student students[], int count) {
    if (count >= MAX_STUDENTS) {
        return -1; 
    }

    cout << "Enter Student ID: ";
    cin >> students[count].id;

    
    for (int i = 0; i < count; i++) {
        if (students[i].id == students[count].id) {
            return -2; 
        }
    }

    cout << "Enter First Name: ";
    cin >> students[count].firstName;
    cout << "Enter Last Name: ";
    cin >> students[count].lastName;
    cout << "Enter Course: ";
    cin >> students[count].course;
    cout << "Enter GPA: ";
    cin >> students[count].gpa;

    return count + 1;  
}

int findStudent(Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) return i;
    }
    return -1;  
}

int editStudent(Student students[], int count, int id) {
    int index = findStudent(students, count, id);
    if (index == -1) {
        return -1;  
    }

    cout << "Enter New First Name: ";
    cin >> students[index].firstName;
    cout << "Enter New Last Name: ";
    cin >> students[index].lastName;
    cout << "Enter New Course: ";
    cin >> students[index].course;
    cout << "Enter New GPA: ";
    cin >> students[index].gpa;

    return 1;  
}

int deleteStudent(Student students[], int count, int id) {
    int index = findStudent(students, count, id);
    if (index == -1) {
        return -1; 
    }

    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    return count - 1;  
}

int displayStudents(Student students[], int count, int option) {
    if (count == 0) {
        return -1;  
    }

    
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((option == 1 && students[i].lastName > students[j].lastName) ||
                (option == 2 && students[i].gpa > students[j].gpa)) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    return 1;  // Successfully displayed
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0, choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "[1] Add Student\n[2] Edit Student\n[3] Delete Student\n[4] View Students\n[5] Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 1) {
            int result = addStudent(students, count);
            if (result == -1) cout << "Database is full!\n";
            else if (result == -2) cout << "Duplicate ID found!\n";
            else {
                count = result;
                cout << "Student added successfully!\n";
            }
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter Student ID to edit: ";
            cin >> id;
            int result = editStudent(students, count, id);
            if (result == -1) cout << "Student ID not found!\n";
            else cout << "Student record updated!\n";
        } 
        else if (choice == 3) {
            int id;
            cout << "Enter Student ID to delete: ";
            cin >> id;
            int result = deleteStudent(students, count, id);
            if (result == -1) cout << "Student ID not found!\n";
            else {
                count = result;
                cout << "Student deleted successfully!\n";
            }
        } 
        else if (choice == 4) {
            cout << "View students by:\n";
            cout << "[1] Alphabetically\n";
            cout << "[2] GPA (ascending)\n";
            cout << "Enter choice: ";
            cin >> choice;
            
            int result = displayStudents(students, count, choice);
            if (result == -1) cout << "No student records available.\n";
            else {
                for (int i = 0; i < count; i++) {
                    cout << "ID: " << students[i].id 
                         << " | Name: " << students[i].firstName << " " << students[i].lastName 
                         << " | Course: " << students[i].course 
                         << " | GPA: " << students[i].gpa << endl;
                }
            }
        } 
        else if (choice == 5) {
            cout << "Exiting program...\n";
            return 0;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }
}
