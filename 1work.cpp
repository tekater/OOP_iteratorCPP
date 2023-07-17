#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <list>
#include <map>

using namespace std;



class Student {
    string name;
    int c;
public:
    Student(string n, int cc) : name{ n }, c{ cc } {}
    Student() :Student("Eva", 10) {}

    string getName() {
        return name;
    }

    friend ostream& operator<<(ostream& out, const Student& s1);
};

ostream& operator<<(ostream& out, const Student& s1) {
    out << "Name: " << s1.name << "\nClass: " << s1.c << endl;
    return out;
}

void inputV(vector<Student>& v, string n = "None", int c = 0) {
    v.push_back(Student(n, c));
}

void outV(vector <Student> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}





class Ex {
    string name;
    string opisanie;
public:
    Ex(string n, string o) :name{ n }, opisanie{ o } {}
    Ex() :Ex("None", "None") {}

    
    
    friend ostream& operator<<(ostream& out, const Ex& ex1);
};

ostream& operator<<(ostream& out, const Ex& ex1) {
    out << "Name: " << ex1.name << "\nOpisanie: " << ex1.opisanie << endl;
    return out;
}

typedef list<Ex> L;

void outL(L l1) {
    L::iterator iter;

    cout << "L1:\n";
    for (iter = l1.begin(); iter != l1.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

void inputL(L& l, string n = "None", string op = "None") {
    l.push_back(Ex(n, op));
}

typedef map<string, int> MAP;

class Tovar {
    MAP m;
    string name;
    int cost;
public:
    
    Tovar(string n, int c) :name{ n }, cost{ c } {
        
    }
    void inputM(MAP map, string n, int c) {
        map.insert(pair<string, int>(n, c));
    }
};



void show(MAP m1) {
    MAP::iterator iter;

    for (iter = m1.begin(); iter != m1.end(); iter++) {
        cout << iter->first << " - " << iter->second << endl;
    }
    cout << endl;

}



class Contact {
    string name;
    int phone;

};
//typedef multimap<Contact> MMAP;
typedef multimap<string,int> MMAP;

void showd(MMAP m1) {
    MMAP::iterator iter;

    for (iter = m1.begin(); iter != m1.end(); iter++) {
        cout << iter->first << " - " << iter->second << endl;
    }
    cout << endl;

}




class Book {
    string name;
    string autor;
    int year;
public:
    Book(string n,string a,int y): name{n},autor{a},year{y} {}
    Book() : Book("None", "None", 0) {}

    string getName() {
        return name;
    }
    string getAutor() {
        return autor;
    }
    int getYear() {
        return year;
    }
};

typedef multimap<string, Book> BMAP;

void show(BMAP m1) {
    BMAP::iterator iter;

    for (iter = m1.begin(); iter != m1.end(); iter++) {
        cout << iter->first << " - " << iter->second.getName() << endl;
    }
    cout << endl;

}

void found(BMAP m1, string word) {
    BMAP::iterator iter;
    for (iter = m1.begin(); iter != m1.end(); iter++) {
        if (iter->first == word) {
            cout << iter->first << " - " << iter->second.getAutor() <<" - " << iter->second.getYear() << endl;
        }
    }
    cout << endl;
}



class Zadacha {
    string name;
    string time;
public:
    Zadacha(string n, string t) :name{ n }, time{ t } {}
    Zadacha() : Zadacha("None", "00:00"){}

    void insert(multimap<string, Zadacha>& m1) {
        string day;
        cout << "Выберите день:\n[1] - Monday\n[2] - Tuesday\n";
        cout << "[3] - Wednesday\n[4] - Thursday\n";
        cout << "[5] - Friday\n[6] - Saturday\n";
        cout << "[7] - Sunday\n";
        int ch;
        cin >> ch;
        switch (ch) {
        case 1:
            day = "Monday";
            break;
        case 2:
            day = "Tuesday";
            break;
        case 3:
            day = "Wednesday";
            break;
        case 4:
            day = "Thursday";
            break;
        case 5:
            day = "Friday";
            break;
        case 6:
            day = "Saturday";
            break;
        case 7:
            day = "Sunday";
            break;
        default:
            day = "On week";
            break;
        }
        system("cls");
        cout << "Введите название задачи:\n";
        cin >> name;
        cout << "Введите время:\n";
        cin >> time;
        m1.insert(pair<string, Zadacha>(day, { name,time }));
    }

    string getName() {
        return name;
    }
    string getTime() {
        return time;
    }
};

typedef multimap<string, Zadacha> ZMMAP;

void found(ZMMAP m1, string word) {
    ZMMAP::iterator iter;
    for (iter = m1.begin(); iter != m1.end(); iter++) {
        if (iter->first == word) {
            cout << iter->first << " - " << iter->second.getName() << " - " << iter->second.getTime() << endl;
        }
    }
    cout << endl;
}

void rem(ZMMAP &m1, string word) {
    m1.erase(word);
}

void show(ZMMAP m1) {
    ZMMAP::iterator iter;
    for (iter = m1.begin(); iter != m1.end(); iter++) {
        cout << iter->first << " - " << iter->second.getName() << " - " << iter->second.getTime() << endl;
    }
    cout << endl;
}

int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    // Создать класс "Студент" со свойствами: имя и возраст. Храните объекты класса "Студент" в векторе.

    vector<Student> stud;

    inputV(stud, "Max", 6);
    inputV(stud, "Misha", 8);
    inputV(stud, "Dima", 5);
    inputV(stud, "Artem", 10);
    inputV(stud, "Sasha", 7);

    outV(stud);

    //Создать класс "Задача" со свойствами: название и описание. Храните объекты класса "Задача" в списке (list).

    L l1;
    inputL(l1, "Uborka", "pomoy pol");
    inputL(l1, "Gotovka", "Prigotovit kuricu");
    inputL(l1, "Math", "2+2");
    inputL(l1, "Magaz", "Kupit hleb");

    outL(l1);

    // Создать класс "Товар" со свойствами: название и цена. 
    // Используйте ассоциативный контейнер Map для хранения товаров, где ключом будет название товара, а значением - его цена.

    MAP map;
    cout << "Map:\n";
    map.insert(pair<string, int>("Pen", 20));
    map.insert(pair<string, int>("Apple", 2));
    show(map);



    // Создать класс "Контакт" со свойствами: имя и номер телефона.
    // Храните контакты в мультимапе, где ключом будет имя контакта, а значением - его номер телефона.
    // Это позволит хранить несколько контактов с одинаковым именем.

    MMAP multimap;
    cout << "MMAP:\n";
    multimap.insert(pair<string, int>("Petrov", 88005553));
    multimap.insert(pair<string, int>("Anton", 88225663));
    multimap.insert(pair<string, int>("Grigor", 88322551));
    multimap.insert(pair<string, int>("Vovan", 85552333));
    multimap.insert(pair<string, int>("Danil", 81002554));
    showd(multimap);



    // Создать map "Библиотека" со свойствами: название и список книг. 
    // Каждая книга представлена классом "Книга" с свойствами: название, автор и год издания. 
    // Используйте контейнер Map, где ключом будет название книги, а значением - объект класса "Книга". 
    // Реализуйте функциональность поиска книги по названию и автору.

    Book lister[3]{
        {"Зелёная миля","Steven King",2014},
        {"Унесенные ветром","Маргарет Митчелл",2020},
        {"Шерлок Холмс","Артур Конан",2019} 
    };
    BMAP booklist;
    cout << "Bibl:\n";
    booklist.insert(pair<string, Book>("Зелёная миля", lister[0]));
    booklist.insert(pair<string, Book>("Унесенные ветром", lister[1]));
    booklist.insert(pair<string, Book>("Шерлок Холмс", lister[2]));
    found(booklist, "Зелёная миля");

    // Создать программу "Расписание".
    // Каждая задача представлена классом "Задача" с свойствами: название и время. 
    // Используйте контейнер multimap, где ключом будет день недели, а значением - объект класса "Задача". 
    // Реализуйте функциональность добавления, удаления и вывода задач по дню недели. 

    Zadacha t;
    ZMMAP raspisanie;
    cout << "Raspisanie:\n";
    for (int i = 0; i < 3; i++) {
        t.insert(raspisanie);
    }

    show(raspisanie);

    found(raspisanie, "Sunday");

    cout << "Del:\n";
    rem(raspisanie, "Sunday");

    show(raspisanie);
    // я полчаса думал почему не получается, а я в rem не добавил &

}
