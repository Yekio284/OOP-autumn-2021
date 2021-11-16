#include <iostream>
#include <string>
#include "classes.hpp"

using namespace std;

int main() {
    // Test of constructors:
    
    /* FirstUniversity first_university; 
    SecondUniversity second_university; */

    /* FirstUniversity first_university("SibSUTIS");
    SecondUniversity second_university("NSTU");
    cout << "Name of University: " << first_university.get_university_name() << "\n";
    cout << "Name of University: " << second_university.get_university_name() << "\n"; */

    /* FirstUniversity first_university("SibSUTIS", 10015);
    SecondUniversity second_university("NSTU", 14880);
    cout << "Name of University: " << first_university.get_university_name() << "\n";
    cout << "Number of students in " << first_university.get_university_name() << ": " << first_university.get_num_of_students() << "\n";
    cout << "Name of University: " << second_university.get_university_name() << "\n";
    cout << "Number of students in " << second_university.get_university_name() << ": " << second_university.get_num_of_students() << "\n"; */

    /* FirstUniversity first_university("SibSUTIS", 10015, 4);
    SecondUniversity second_university("NSTU", 14880, 17);
    cout << "Name of University: " << first_university.get_university_name() << "\n";
    cout << "Number of students in " << first_university.get_university_name() << ": " << first_university.get_num_of_students() << "\n";
    cout << "Number of faculties in " << first_university.get_university_name() << ": " << first_university.get_num_of_faculties() << "\n";
    cout << "Name of University: " << second_university.get_university_name() << "\n";
    cout << "Number of students in " << second_university.get_university_name() << ": " << second_university.get_num_of_students() << "\n"; 
    cout << "Number of faculties in " << second_university.get_university_name() << ": " << second_university.get_num_of_faculties() << "\n"; */

    /* FirstUniversity first_university("SibSUTIS", 10015, 4, 19);
    SecondUniversity second_university("NSTU", 14880, 17, 77);
    cout << "\nName of University: " << first_university.get_university_name() << "\n";
    cout << "Number of students in " << first_university.get_university_name() << ": " << first_university.get_num_of_students() << "\n";
    cout << "Number of faculties in " << first_university.get_university_name() << ": " << first_university.get_num_of_faculties() << "\n";
    cout << "Number of departments in " << first_university.get_university_name() << ": " << first_university.get_num_of_departments() << "\n";
    cout << "\nName of University: " << second_university.get_university_name() << "\n";
    cout << "Number of students in " << second_university.get_university_name() << ": " << second_university.get_num_of_students() << "\n"; 
    cout << "Number of faculties in " << second_university.get_university_name() << ": " << second_university.get_num_of_faculties() << "\n";
    cout << "Number of departments in " << second_university.get_university_name() << ": " << second_university.get_num_of_departments() << "\n\n"; */

    // 1st test:
    /*cout << "FIRST TEST:\n";
    FirstUniversity first_university("SibSUTIS", 10015, 4, 19);
    SecondUniversity second_university("NSTU", 14880, 17, 77);
    cout << "\nName of University: " << first_university.get_university_name() << "\n";
    cout << "Number of students in " << first_university.get_university_name() << ": " << first_university.get_num_of_students() << "\n";
    cout << "Number of faculties in " << first_university.get_university_name() << ": " << first_university.get_num_of_faculties() << "\n";
    cout << "Number of departments in " << first_university.get_university_name() << ": " << first_university.get_num_of_departments() << "\n";
    cout << "\nName of University: " << second_university.get_university_name() << "\n";
    cout << "Number of students in " << second_university.get_university_name() << ": " << second_university.get_num_of_students() << "\n"; 
    cout << "Number of faculties in " << second_university.get_university_name() << ": " << second_university.get_num_of_faculties() << "\n";
    cout << "Number of departments in " << second_university.get_university_name() << ": " << second_university.get_num_of_departments() << "\n\n"; 
    */
    // 2nd test:
    cout << "SECOND TEST:\n";
    FirstUniversity first_university("NSU", 8177);
    SecondUniversity second_university("MSU", 38150);

    cout << "\nName of University: " << first_university.get_university_name() << "\n";
    cout << "Number of students in " << first_university.get_university_name() << ": " << first_university.get_num_of_students() << "\n";
    first_university.set_num_of_faculties(10);
    cout << "Number of faculties in " << first_university.get_university_name() << ": " << first_university.get_num_of_faculties() << "\n";
    first_university.set_num_of_departments(83);
    cout << "Number of departments in " << first_university.get_university_name() << ": " << first_university.get_num_of_departments() << "\n";
    
    cout << "\nName of University: " << second_university.get_university_name() << "\n";
    cout << "Number of students in " << second_university.get_university_name() << ": " << second_university.get_num_of_students() << "\n"; 
    second_university.set_num_of_faculties(43);
    cout << "Number of faculties in " << second_university.get_university_name() << ": " << second_university.get_num_of_faculties() << "\n";
    second_university.set_num_of_departments(300);
    cout << "Number of departments in " << second_university.get_university_name() << ": " << second_university.get_num_of_departments() << "\n\n";

    return 0;
}