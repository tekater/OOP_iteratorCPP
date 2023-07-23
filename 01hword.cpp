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
typedef multimap<string, int> WCMAP;


void show(WCMAP m1) {
    WCMAP::iterator iter;

    for (iter = m1.begin(); iter != m1.end(); iter++) {
        cout << iter->first << " - " << iter->second << endl;
    }
    cout << endl;

}

int main()
{
    setlocale(0, "");
    srand(time(nullptr));
    WCMAP wc;
    FILE* f;
    //string s = "Sun of the sleepless! Melancholy star!\nWhose tearful beam glows tremulously far\nThat show’st the darkness thou canst not dispel";
    //string copy = "";

    f = fopen("C:\\Games\\games.txt", "r");

    /*{
        WCMAP::iterator iter;
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            if (j == 0) {
                copy = " ";
                copy[j] = s[i];
            }
            copy[j] += s[i];
            if (copy[j] == ' ') {
                wc.insert(pair<string, int>(copy, 0));
                j = 0;
            }
        }
    }*/

    string word;
    for (int i = 0; i < 10; i++) {
        int num = 1;
        fscanf(f, "%s\n", &word);
        // добавить класс-проверку, если это слово встречалось, вернуть счётчик в num со значением +1
        // если нет, то оставить 1.
        wc.insert(pair<string, int>(word, num));
    }

    /*{

        WCMAP::iterator iter;
        for (int i = 0; i < 10; i++) {
            for (iter = wc.begin(); iter != wc.end(); iter++) {
                fscanf(f, "%s ", &word);
                if (iter->second >= 1) {
                    wc.insert(pair<string, int>(word, iter->second += 1));
                }
                else {
                    wc.insert(pair<string, int>(word, 0));
                }

            }
        }

    }*/

    show(wc);

    //FILE* D;
    //D = fopen("C:\\Games\\d.txt", "w");
    //добавить запись в файл
}
