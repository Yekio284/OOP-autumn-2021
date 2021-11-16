#include <iostream>
#include <string>

using namespace std;

class University {
    public:
        virtual void set_university_name(string name)=0;
        virtual void set_num_of_students(int students)=0;
        virtual void set_num_of_faculties(int faculties)=0;
        virtual void set_num_of_departments(int departments)=0;
        virtual string get_university_name()=0;
        virtual int get_num_of_students()=0;
        virtual int get_num_of_faculties()=0;
        virtual int get_num_of_departments()=0;
};

class FirstUniversity : public University {
    private:
        string university_name;
        int num_of_students, num_of_faculties, num_of_departments;
    public:
        FirstUniversity(string name, int students, int faculties, int departments) : university_name(name), num_of_students(students), num_of_faculties(faculties), 
            num_of_departments(departments) {
                cout << "Constructor FirstUniversity with 4 parametrs.\n";
        }
        FirstUniversity(string name, int students, int faculties) :  university_name(name), num_of_students(students), num_of_faculties(faculties) {
            cout << "Constructor FirstUniversity with 3 parametrs.\n";
        }
        FirstUniversity(string name, int students) : university_name(name), num_of_students(students) {
            cout << "Constructor FirstUniversity with 2 parametrs.\n";
        }
        FirstUniversity(string name) : university_name(name) {
            cout << "Constructor FirstUniversity with 1 parametr.\n";
        }
        FirstUniversity(void){
            cout << "Constructor FirstUniversity without parametrs.\n";
        }
        void set_university_name(string name) {
            university_name = name;
        }
        void set_num_of_students(int students) {
            num_of_students = students;
        }
        void set_num_of_faculties(int faculties) {
            num_of_faculties = faculties;
        }
        void set_num_of_departments(int departments) {
            num_of_departments = departments;
        }
        string get_university_name() {
            return university_name;
        }
        int get_num_of_students() {
            return num_of_students;
        }
        int get_num_of_faculties() {
            return num_of_faculties;
        }
        int get_num_of_departments() {
            return num_of_departments;
        }
        ~FirstUniversity() {
            cout << "Destructor FirstUniversity.\n";
        }
};

class SecondUniversity : public University {
    private:
        string university_name;
        int num_of_students, num_of_faculties, num_of_departments;
    public:
        SecondUniversity(string name, int students, int faculties, int departments) : university_name(name), num_of_students(students), num_of_faculties(faculties), 
            num_of_departments(departments) {
                cout << "Constructor SecondUniversity with 4 parametrs.\n";
        }
        SecondUniversity(string name, int students, int faculties) :  university_name(name), num_of_students(students), num_of_faculties(faculties) {
            cout << "Constructor SecondUniversity with 3 parametrs.\n";
        }
        SecondUniversity(string name, int students) : university_name(name), num_of_students(students) {
            cout << "Constructor SecondUniversity with 2 parametrs.\n";
        }
        SecondUniversity(string name) : university_name(name) {
            cout << "Constructor SecondUniversity with 1 parametr.\n";
        }
        SecondUniversity(void){
            cout << "Constructor SecondUniversity without parametrs.\n";
        }
        void set_university_name(string name) {
            university_name = name;
        }
        void set_num_of_students(int students) {
            num_of_students = students;
        }
        void set_num_of_faculties(int faculties) {
            num_of_faculties = faculties;
        }
        void set_num_of_departments(int departments) {
            num_of_departments = departments;
        }
        string get_university_name() {
            return university_name;
        }
        int get_num_of_students() {
            return num_of_students;
        }
        int get_num_of_faculties() {
            return num_of_faculties;
        }
        int get_num_of_departments() {
            return num_of_departments;
        }
        ~SecondUniversity() {
            cout << "Destructor SecondUniversity.\n";
        }
};