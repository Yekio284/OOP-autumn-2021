#include <iostream>
#include <string>

using namespace std;

class EducationalInstitution {
    public:
        virtual void set_school_name(string name)=0;
        virtual void set_num_of_students(int students)=0;
        virtual void set_num_of_faculties(int faculties)=0;
        virtual void set_num_of_departments(int departments)=0;
        virtual string get_school_name()=0;
        virtual int get_num_of_students()=0;
        virtual int get_num_of_faculties()=0;
        virtual int get_num_of_departments()=0;
};

class HighSchool : public EducationalInstitution {
    private:
        string university_name;
        int num_of_students, num_of_faculties, num_of_departments;
    public:
        HighSchool(string name, int students, int faculties, int departments, char choose='N') : university_name(name), num_of_students(students), num_of_faculties(faculties), 
            num_of_departments(departments) {
                if (choose == 'Y')
                    cout << "Constructor HighScool with 5 parametrs.\n";
        }
        HighSchool(string name, char choose='N') : university_name(name) {
            if (choose == 'Y')
                    cout << "Constructor HighSchool with 2 parametrs.\n";
        }
        void set_school_name(string name) {
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
        string get_school_name() {
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
        ~HighSchool() {
            cout << "Destructor HighSchool.\n";
        }
};

class SecondaryVocational : public EducationalInstitution {
    private:
        string college_name;
        int num_of_students, num_of_faculties, num_of_departments;
    public:
        SecondaryVocational(string name, int students, int faculties, int departments, char choose='N') : college_name(name), num_of_students(students), num_of_faculties(faculties), 
            num_of_departments(departments) {
                if (choose == 'Y')
                    cout << "Constructor SecondaryVocational with 5 parametrs.\n";
        }
        SecondaryVocational(string name, char choose='N') : college_name(name) {
            if (choose == 'Y')
                cout << "Constructor SecondaryVocational with 2 parametrs.\n";
        }
        void set_school_name(string name) {
            college_name = name;
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
        string get_school_name() {
            return college_name;
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
        ~SecondaryVocational() {
            cout << "Destructor SecondaryVocational.\n";
        }
};
