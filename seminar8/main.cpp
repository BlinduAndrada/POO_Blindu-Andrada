#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include<cctype>

using namespace std;

//implementeaza un operator de comparare pentru perechile de tipul<string, int>
class Compare {
public:
	bool operator()(const pair<string, int>& a, const pair<string, int>& b)const {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second < b.second;
	}
};

//verifica daca un caracter este separator
bool esteExceptie(char c, string s) {

	for (auto ch : s) {
		if (c == ch)
			return 1;
	}
	return 0;

}

int main()
{
	string Sir;
	ifstream File("input.txt");

	if (!File) {
		printf("eroare la deschiderea fisierului input.txt");
		return 0;
	}
//citim prima linie din fisier
	if (!getline(File, Sir)) {
		printf("eroare la citirea din fisier");
		return 0;
}

	map< string, int>Map;
	printf("sirul de caractere citit este: %s\n", Sir.c_str());

	
	string Punctuatii = ".,?! ";
	vector<string>Words;
	transform(Sir.begin(), Sir.end(), Sir.begin(), ::tolower);

//parcurgen sirul si extragem cuvintele(separate prin separatoarele din stringul Punctuatie

	int l = 0;
	for (auto i = 0; i < Sir.length(); i++) {
		auto c = Sir.at(i);
		if (esteExceptie(c, Punctuatii)) {
			auto Subsir = Sir.substr(l, i - l);
			l = i + 1;//l se actualizeaza la pozitia noului cuvant
			if (Subsir.length() > 0)
				Words.push_back(Subsir);
		}
	}
	//cream alt vector pentru Words din care eliminam duplicatele si numaram aparitia 
	vector<string>UniqueWords;
	for (auto str : Words) {
		if (Map[str] == 0) 
			UniqueWords.push_back(str);
		Map[str]++;

		
	}
	//transformam Map ul intr-un vector de perechi (cuvant, nr apartitii)
	vector<pair<string, int>>Frecventa;
	for (auto cuv : UniqueWords) {
		Frecventa.push_back(make_pair(cuv, Map[cuv]));

	}
	//sortam vectorul dupa numarul de aparitii si apoi le punem intr-o coada de prioritai

	priority_queue < pair<string, int>, vector<pair<string, int>>, Compare>Ordonare;
	for (auto Pereche : Frecventa) {
		Ordonare.push(Pereche);

	}
	//parcurgem coada de prioritati si afisam cuvintele in ordinea descrescatoare a numarului de aparitii
	while (!Ordonare.empty()) {
		pair<string, int>Top = Ordonare.top();
		cout << "\"" << Top.first << "\"" << " -> " << Top.second << '\n';
		Ordonare.pop();
	}
	return 0;
}

  
