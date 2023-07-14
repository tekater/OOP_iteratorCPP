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
#include <list>
#include <map> // map + multimap

using namespace std;

typedef map<string, int> MAP;
typedef multimap<string, int> MMAP;
typedef map<char, int> WCMAP;

void show(MAP m1) {
    MAP::iterator iter;

    for (iter = m1.begin(); iter != m1.end(); iter++) {
        cout << iter->first << " - " << iter->second << endl;
    }
    cout << endl;

}
void show(MMAP m1) {
    MMAP::iterator iter;

    for (iter = m1.begin(); iter != m1.end(); iter++) {
        cout << iter->first << " - " << iter->second << endl;
    }
    cout << endl;

}

void show(WCMAP m1) {
    WCMAP::iterator iter;

    for (iter = m1.begin(); iter != m1.end(); iter++) {
        if (iter->second == 0) {

        }
        else {
            cout << iter->first << " - " << iter->second << endl;
        }
    }
    cout << endl;

}

//void show(WCMAP m1) {
//    WCMAP::iterator iter;
//
//    for (iter = m1.begin(); iter != m1.end(); iter++) {
//
//        cout << iter->first << " - " << iter->second << endl;
//    
//    }
//    cout << endl;
//
//}

int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    //1 explicit map(const Comp &cmpfn = Comp()),
    // Allocator& a = Allocator());
    //2 map(map<Key,T,Comp,Allocator>&ob);
    //3 template <class InIter> map (InIter start,
    // InIter end, const Comp &cmpfn = Comp(),
    // const Allocator &a = Allocator());

    map<string, int> mymap;

    //size_type count(const key_type &k) const;
    //
    // iterator find(const key_type &k);
    // const_iterator find(const key_type &k) const;
    //
    // size_type erase(const key_type &k);
    //
    // pair<iterator,iterator> equal_range(const key_type &k);
    // pair<const_iterator,const_iterator>
    //   equal_range(const key_type &k) const;
    //
    // pair<iterator,bool> insert(const value_type &val);
    //
    // iterator lower_bound(const key_type &k); первый >=k
    // const_iterator lower_bound(const key_type &k) const;
    //
    // iterator upper_bound(const key_type &k); первый > k
    // const_iterator upper_bound(const key_type &k) const;

    //MAP map;
    //MMAP multimap;
    //cout << "Map:\n";
    //map.insert(pair<string, int>("Petrov", 5));
    //map.insert(pair<string, int>("Ivanov", 4));
    //
    //map["Sidorov"] = 3;
    //map["Ivanov"] = 3;

    //show(map);
    //map.insert(pair<string, int>("Ivanov", 5));
    //show(map);

    //
    ////pair<map<string,int>::iterator, bool>
    //pair<MAP::iterator, bool> check = map.insert(make_pair("Petrov", 4));
    //if (check.second == false) {
    //    cout << "Error!\n";
    //}

    WCMAP wc;
    WCMAP wc2;
    string s = "some text";

    for (int i = 0; i < 26; i++) {
        wc.insert(pair<char, int>('a' + i, 0));
    }

    {
        WCMAP::iterator iter;
        for (int i = 0; i < s.size(); i++) {
            for (iter = wc.begin(); iter != wc.end(); iter++) {
                if (iter->first == s[i]) {
                    iter->second++;
                }
            }
        }
        
    }

    show(wc);






   /* cout << "\nMultiMap:\n";
    multimap.insert(pair<string, int>("Petrov", 5));
    multimap.insert(pair<string, int>("Ivanov", 3));
    multimap.insert(pair<string, int>("Nikolaev", 4));
    multimap.insert(pair<string, int>("Petrov", 2));
    multimap.insert(pair<string, int>("Petrov", 5));
    multimap.insert(pair<string, int>("Sidorov", 5));
    multimap.insert(pair<string, int>("Sidorov", 2));
    multimap.insert(pair<string, int>("Sidorov", 3));
    multimap.insert(pair<string, int>("Sidorov", 4));


    show(multimap);

    {
        MMAP::iterator iter;
        for (iter = multimap.lower_bound("Sidorov"); iter != multimap.upper_bound("Sidorov"); iter++) {
            cout << iter->first << " - " << iter->second << endl;
        }
    }*/

}
