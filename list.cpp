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

using namespace std;

typedef list<int> L;


void ShowLists(L l1, L l2) {

    L::iterator iter;
    cout << "L1:\n";
    for (iter = l1.begin(); iter != l1.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl << "L2:\n";
    for (iter = l2.begin(); iter != l2.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;

}

int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    L l1;
    L l2;

    for (int i = 0; i < 5; i++) {
        l1.push_back(i);
        l2.push_front(i);
    }

    ShowLists(l1, l2);
    {
        L::iterator iter;
        iter = l1.begin();
        l1.push_back(*iter);
        l1.erase(l1.begin());
    }
    
    cout << endl;
    ShowLists(l1, l2);
}
