#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <map>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
bool Comparare(pair<string, int>& stanga, pair<string, int>& dreapta)//pair efectiv e o pereche de 2 tipuri de date
{
	if (stanga.second != dreapta.second)
		return stanga.second < dreapta.second;
	else
		return stanga.first.compare(dreapta.first) > 0;
}

int main()
{
	FILE* f = fopen("C:\\Users\\Mihai\\source\\repos\\Laboratorul 8\\Laboratorul 8\\Text.txt", "r");//citire dintr-un fisier
	if (f == nullptr)
	{
		printf("Eroare\n");
		exit(1);
	}
	string sir;
	char subsir[4096];
	while (!feof(f))
	{
		auto text = fread(subsir, 1, sizeof(subsir), f);//auto detecteaza tipul de date in functie de initializarea sa
		sir.append(subsir, text);
    }
	fclose(f);
	for (int i = 0; i < sir.size(); i++)
		sir[i] = tolower(sir[i]);
	map<string, int>m;//initializare mapa
	int poz = 0;
	int start = 0;
	int pozitie = sir.find_first_of(" ,?!.", poz);
	string cuvant;
	while (pozitie != string::npos)//npos max size-ul
	{
		cuvant = sir.substr(start, pozitie - start);//generaza un subsir de la parametrul 1 la parametrul 2
		m[cuvant]++;
		poz = pozitie + 1;
		start = sir.find_first_not_of(" ,?!.", poz);
		poz = start;
		pozitie = sir.find_first_of(" ,?!.", poz);
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&Comparare)> queue(Comparare);
	map<string, int>::iterator it = m.begin();
	while (it != m.end())
	{
		pair<string, int>p;
		p.first = it->first;
		p.second = it->second;
		queue.push(p);
		it++;
	}
	while (queue.empty())
	{
		cout << queue.top().first << " =>" << queue.top().second << "\n";
		queue.pop();
	}
}