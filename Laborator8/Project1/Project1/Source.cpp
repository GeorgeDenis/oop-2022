#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <map>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

bool Comparare(pair<string, int>& stanga, pair<string, int>& dreapta) {
    if (stanga.second != dreapta.second)
        return stanga.second < dreapta.second;
    else {
        return stanga.first.compare(dreapta.first) > 0;
    }
}
int main() {
    FILE* f = fopen("H:\\PROGRAMAREORIENTATEOBIECT\\Fork\\oop-2022\\Laborator8\\Project1\\Project1\\Text.txt", "r");
    if (f == nullptr) {
        printf("Eroare!!\n");
        exit(1);
    }
    string sir;
    char subsir[4096];
    while (!feof(f)) {
        auto text = fread(subsir, 1, sizeof(subsir), f);
        sir.append(subsir, text);
    }
    fclose(f);
    for (int i = 0; i < sir.size(); i++)
        sir[i] = tolower(sir[i]);

    map<string, int> m;
    int poz = 0;
    int start = 0;
    int pozitie = sir.find_first_of(" ,?!.", poz);
    string cuvant;
    while (pozitie != string::npos) {
        cuvant = sir.substr(start, pozitie - start);
        m[cuvant]++;
        poz = pozitie + 1;
        start = sir.find_first_not_of(" ,?!.", poz);
        poz   = start;
        pozitie = sir.find_first_of(" ,?!.", poz);
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&Comparare)> queue(Comparare);
    map<string, int>::iterator it = m.begin();
    while (it != m.end()) {
        pair<string, int> p;
        p.first = it->first;
        p.second = it->second;
        queue.push(p);
        it++;
    }
    while (!queue.empty()) {
        cout << queue.top().first << " => " << queue.top().second << "\n";
        queue.pop();
    }


    return 0;
}