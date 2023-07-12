#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> // ifstream + ofstream
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>
#include <vector>

using namespace std;

class Student {
    string name;
    int c;
public:
    Student(string n, int cc) : name{ n }, c{ cc } {}
    Student():Student("Eva",10) {}
    string getName() {
        return name;
    }

    friend ostream& operator<<(ostream& out, const Student& s1);
};

ostream& operator<<(ostream& out, const Student& s1) {
    out << "Name: " << s1.name << "\nClass: " << s1.c << endl;
    return out;
}

void inputV(vector<Student>& v,string n = "None", int c = 0) {
    v.push_back(Student(n, c));
}
void outV(vector <Student> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}
void FilterV(vector<Student>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j].getName() > v[j + 1].getName()) {
                swap(v[j], v[j + 1]);
                sum++;
            }
        }
        if (sum == 0) {
            break;
        }
    }
}

int main()
{
    setlocale(0, "");
    srand(time(nullptr));
    // 1 explicit vector(const Allocator &a = Allocator());
    // 
    // 2 explicit vector(size_type num,const T & val = T(),
    //    const Allocator & a = Allocator());
    //
    // 3 vector(const vector <T, Allocator> & ob);
    //
    // 4 template < class InIter > vector(InIter start,
    //    InIter end, const Allocator & a = Allocator());
    // 
    // template <class InIter>
    // void assign(InIter start, InIter end);
    // 
    // reference at(size_type i);
    // const_reference at(size_type i) const;
    // reference operator[](size_type i) const;
    // const reference operator[](size_type i) const;
    //
    // void push_back(const T &val);
    // void pop_back();
    // 
    // void clear();
    // bool empty() const;
    //
    // iterator erase(iterator i);
    // iterator erase(iterator start,iterator end);
    //
    // 1 iterator insert(iterator i, const T &val = T());
    // 2 void insert(iterator i,size_type num,const T &val);
    // 3 template <class InIter>
    //     void insert(iterator i, InIter start, InIter end);
    //
    // reference front();
    // const_reference front() const;
    // reference back();
    // const_iterator back() const;
    //
    // iterator begin();
    // const_iterator begin() const;
    // iterator end();
    // const_iterator end() const;
    //
    // reverse_iterator rbegin();
    // const_reverse_iterator rbegin() const;
    // iterator end();
    // const_iterator end() const;
    //
    // void swap(vector<T,Allocator> &ob);

    vector<int> v;

    cout << v.max_size() / sizeof(int) << endl << endl;
    cout << v.capacity() << endl;
    cout << v.size() << endl << endl;

    for (int i = 0; i < 14; i++) {
        v.push_back(i);
    }
    cout << v.capacity() << endl;
    cout << v.size() << endl << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.resize(10, 0);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;

    vector<int>::iterator b;
    for (b = v.begin(); b != v.end(); b++) {
        cout << *(b) << " ";
    }
    cout << endl;

    vector<int>::reverse_iterator rb;
    for (rb = v.rbegin(); rb != v.rend(); rb++) {
        cout << *(rb) << " ";
    }
    cout << endl << endl;

    b = v.end();
    v.insert(b - 4, 3, 5);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;

    vector<int> v2(v.begin() + 3, v.end() - 5);
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl << endl;

    /*vector<int> sq;
    cout << "SQ:\n";
    for (int i = 0; i < 10; i++) {
        sq.push_back(i * i);
        cout << sq[i] << " ";
    }
    cout << endl << endl;*/
    vector<int> sq(10,0);
    cout << "SQ:\n";
    for (int i = 0; i < 10; i++) {
        sq[i] = i * i;
        cout << sq[i] << " ";
    }
    cout << endl << endl;

    /*{
        vector<vector<int>> arrv(10);

        vector<int> one(10, 0);
        vector<int> two(10, 0);
        vector<int> three(10, 0);
        vector<int> four(10, 0);
        vector<int> five(10, 0);
        vector<int> six(10, 0);
        vector<int> seven(10, 0);
        vector<int> eight(10, 0);
        vector<int> nine(10, 0);
        vector<int> ten(10, 0);

        for (int i = 0; i < 10; i++) {
            one[i] = 1 * i+1;
        }
        for (int i = 0; i < 10; i++) {
            two[i] = 2 * i + 1;
        }
        for (int i = 0; i < 10; i++) {
            three[i] = 3 * i + 1;
        }
        for (int i = 0; i < 10; i++) {
            four[i] = 4 * i + 1;
        }
        for (int i = 0; i < 10; i++) {
            five[i] = 5 * i + 1;
        }
        for (int i = 0; i < 10; i++) {
            six[i] = 6 * i + 1;
        }
        for (int i = 0; i < 10; i++) {
            seven[i] = 7 * i + 1;
        }
        for (int i = 0; i < 10; i++) {
            eight[i] = 8* i + 1;
        }
        for (int i = 0; i < 10; i++) {
            nine[i] = 9 * i + 1;
        }
        for (int i = 0; i < 10; i++) {
            ten[i] = 10 * i + 1;
        }

        arrv.push_back(one);
        arrv.push_back(two);
        arrv.push_back(three);
        arrv.push_back(four);
        arrv.push_back(five);
        arrv.push_back(six);
        arrv.push_back(seven);
        arrv.push_back(eight);
        arrv.push_back(nine);
        arrv.push_back(ten);
     
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << arrv[i][j] << " ";
            }
            cout << endl;
        }
    }*/

    vector<Student> stud;
    
    inputV(stud, "Max", 6);
    inputV(stud, "Misha", 8);
    inputV(stud, "Dima", 5);
    inputV(stud, "Artem", 10);
    inputV(stud, "Sasha", 7);

    outV(stud);

    FilterV(stud);
    cout << "------\n";
    outV(stud);
}
