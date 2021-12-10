#include <iostream>
#include <string>
#include "classes.hpp"

using namespace std;

int main() {
    cout << "До того как мы начнём, хотим уточнить у вас, хотите ли вы увидеть сообщения о срабатывании конструкторов? (Y/N): ";
    char choose;
    cin >> choose;
    cout << "Хорошо.\n";

    if (choose == 'Y')
        cout << endl;

    HighSchool *hs[5];
    SecondaryVocational *sv[5];

    hs[0] = new HighSchool("SibSUTIS", 10015, 4, 19, choose);
    hs[1] = new HighSchool("NSTU", 14880, 17, 77, choose);
    hs[2] = new HighSchool("NSU", choose);
    hs[3] = new HighSchool("SSUWT", 6500, 6, 12, choose);
    hs[4] = new HighSchool("NSUADA", choose);

    try {
        if (!hs)
            throw 'e';
    }
    catch (char n) {
        cout << "Ошибка выделения памяти.";
        return 1;
    }

    hs[2]->set_num_of_students(8177);
    hs[2]->set_num_of_faculties(10);
    hs[2]->set_num_of_departments(83);
    hs[4]->set_num_of_students(4267);
    hs[4]->set_num_of_faculties(2);
    hs[4]->set_num_of_departments(5);


    sv[0] = new SecondaryVocational("NCTI", 850, 3, 5, choose); //КТИ СибГУТИ
    sv[1] = new SecondaryVocational("CiNSU", 576, 2, 2, choose); //ВКИ НГУ
    sv[2] = new SecondaryVocational("NMC", 720, 7, 9, choose); //Новосибирский медицинский колледж
    sv[3] = new SecondaryVocational("NABL", 600, 7, 7, choose); //Новосибирский авиастроительный лицей
    sv[4] = new SecondaryVocational("NKE", 950, 10, 12, choose); //НКЭиВТ

    try {
        if (!sv)
            throw 'e';
    }
    catch (char n) {
        cout << "Ошибка выделения памяти.";
        return 1;
    }

    
    cout << "\nДобро пожаловать в приложение 'Актуальная информация по ВУЗам и Колледжам города Новосибирск'!!!" << endl;
    cout << "Информацию о каких учебных заведениях вы хотите узнать - ВУЗ или Колледж? (1/0): ";
    short type_of_school_choose;
    short flag;
    cin >> type_of_school_choose;
    cout << endl;

    while (true) {
        if (type_of_school_choose == 0) {
            cout << "Доступные Колледжи: ";
            for (int i = 0; i < 5; i++) {
                if (i == 4)
                    cout << sv[i]->get_school_name() << ".";
                else
                    cout << sv[i]->get_school_name() << ", ";
            }
            cout << endl;

            cout << "Информацию о каком колледже вы хотите узнать? (Просьба вводить правильное название): "; 
            string wish;
            cin >> wish;
            cout << endl;
            
            for (int i = 0; i < 5; i++) {
                if (wish == sv[i]->get_school_name()) {
                    cout << "Название колледжа: " << sv[i]->get_school_name() << endl;
                    cout << "Количество студентов колледжа: " << sv[i]->get_num_of_students() << endl;
                    cout << "Количество направлений: " << sv[i]->get_num_of_faculties() << endl;
                    cout << "Количество квалификаций: " << sv[i]->get_num_of_departments() << endl;
                    cout << endl;
                    break;
                }
            }

            cout << "Хотите дальше изучать колледжи или переключимся на ВУЗы? Или вовсе хотите закрыть приложение? (1/2/3): ";
            cin >> flag;
            cout << endl;

            if (flag == 1) 
                continue;
            else if (flag == 2)
                type_of_school_choose = 1;
            else if (flag == 3)
                break;
        }
        else if (type_of_school_choose == 1) {
            cout << "Доступные ВУЗы: ";
            for (int i = 0; i < 5; i++) {
                if (i == 4)
                    cout << hs[i]->get_school_name() << ".";
                else
                    cout << hs[i]->get_school_name() << ", ";
            }
            cout << endl;

            cout << "Информацию о каком ВУЗе вы хотите узнать? (Просьба вводить правильное название): ";
            string wish;
            cin >> wish;
            cout << endl;
            
            for (int i = 0; i < 5; i++) {
                if (wish == hs[i]->get_school_name()) {
                    cout << "Название ВУЗа: " << hs[i]->get_school_name() << endl;
                    cout << "Количество студентов ВУЗа: " << hs[i]->get_num_of_students() << endl;
                    cout << "Количество факультетов: " << hs[i]->get_num_of_faculties() << endl;
                    cout << "Количество кафедр: " << hs[i]->get_num_of_departments() << endl;
                    cout << endl;
                    break;
                }
            }

            cout << "Хотите дальше изучать ВУЗы или переключимся на Колледжи? Или вовсе хотите закрыть приложение? (1/2/3): ";
            cin >> flag;
            cout << endl;

            if (flag == 1) 
                continue;
            else if (flag == 2)
                type_of_school_choose = 0;
            else if (flag == 3)
                break;
        } 
        else {
            while (type_of_school_choose != 1 && type_of_school_choose != 0) {
                cout << "Неверный символ. Повторите попытку: ";
                cin >> type_of_school_choose;
            }
            cout << endl;
        }
    }

    for (int i = 0; i < 5; i++)
        delete hs[i];

    for (int i = 0; i < 5; i++)
        delete sv[i];

    cout << "\nСпасибо, что использовали моё приложение! Всего доброго!\n";

    return 0;
}