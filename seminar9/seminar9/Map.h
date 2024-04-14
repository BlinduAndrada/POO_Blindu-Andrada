#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <cstdint>

using namespace std;

// Clasa 'Map' este o clasa template ce poate fi instantiata cu doua tipuri de date
// generice 'K' si 'V' pentru a implementa un map cu cheie de tip K si valoare de tip V.

template <typename K, typename V>
class Map {

	// Se defineste o structura interna numita 'Element' care contine
	// cheia, valoarea si indexul elementului.
	struct Element {

		K key;
		V value;
		int index;

	}*vector; // 'vector' reprezinta un vector dinamic de elemente de tipul Element

	// Pozitia curenta din map (de asemenea, si numarul de elemente din map)
	int index;

	// Dimensiunea maxima pentru map
	int size;

	void Resize() {

		if (size != 0) {

			Element* v = new Element[size * 2];
			memcpy(v, vector, sizeof(Element) * size);

			vector = v;
			size = size * 2;

			return;

		}

		vector = new Element[1];
		size = 1;
		index = 0;

	}
	// Functia 'Resize' este apelata atunci cand dimensiunea interna a map-ului este
	// insuficienta pentru a adauga un nou element. Scopul acestei functii este de a
	// realoca memorie pentru vectorul de elemente si a-l redimensiona la o dimensiune
	// dubla fata de dimensiunea curenta.

public:

	Map() {

		vector = new Element[1];
		size = 1;
		index = 0;

	}

	// Urmatoarele doua metode, 'begin' si 'end', sunt folosite pentru a itera prin
	// vector cu ajutorul unui range-based for loop ( o structura de control in limbajul
	// C++ care permite iterarea prin fiecare element dintr-un container (de exemplu, un
	// vector sau o lista) fara a fi necesara utilizarea unui iterator explicit, adica
	// ceva in genul: for(auto& ceva:altceva) )
	Element* begin() const
	{
		return &vector[0];
	}
	Element* end() const
	{
		return &vector[index];
	}


	// Suprascrierea operatorului [] este folosita pentru a obtine sau seta valori pentru
	// o cheie specifica. Functia cauta in vector daca cheia exista. Daca este gasita,
	// valoarea asociata este returnata. Daca nu este gasita, un nou element este adaugat
	// la finalul vectorului.
	V& operator [] (K key) {

		for (int i = 0; i < index; i++)
			if (key == vector[i].key)
				return vector[i].value;

		vector[this->index].index = this->index;
		vector[this->index].key = key;

		this->index++;

		if (this->index == size)
			Resize();

		return vector[this->index - 1].value;

	}

	// Metoda 'Set' este folosita pentru a seta o valoare noua pentru o cheie existenta.
	// Daca cheia nu exista in vector, se afiseaza un mesaj de eroare.
	void Set(K k, V v) {

		for (int i = 0; i < index; i++)
			if (vector[i].key == k) {

				vector[i].value = v;
				size++;

				return;

			}

		// Daca cheia nu exista, atunci:
		printf("Error at Set(). Key probably doesn't exist.\n");

		return;

	}

	// Metoda 'Get' este folosita pentru a obtine valoarea asociata unei chei. Daca cheia nu
	// exista, se returneaza 'false'.
	bool Get(const K& k, V& v) {

		for (int i = 0; i < index; i++)
			if (vector[i].key == k) {

				v = vector[i].value;

				return true;

			}

		return false;

	}

	// 'Count' este o metoda publica care returneaza numarul de elemente din 'Map'.
	int Count() const {

		return index;

	}

	// Metoda 'Clear' este utilizata pentru a sterge toate elementele din map si a-l goli complet.
	// Ea face acest lucru prin setarea variabilei 'size' la zero si variabilei 'index' la zero,
	// apoi elibereaza memoria alocata pentru vectorul 'vector'.
	void Clear() {

		size = 0;
		index = 0;

		delete[] vector;

	}

	// Metoda 'Delete' primeste o cheie k si incearca sa gaseasca elementul corespunzator din map.
	// Daca cheia este gasita, elementul este eliminat din map si metoda returneaza 'true'. In caz
	// contrar, 'false'.
	bool Delete(const K& k) {

		for (int i = 0; i < index; i++)
			if (vector[i].key == k) {

				for (int j = i; j < index - 1; j++)
					vector[j] = vector[j + 1];

				index--;

				return true;

			}

		return false;

	}

	// Metoda 'Includes' primeste o alta map 'map' si verifica daca toate elementele din 'map' se gasesc
	// si in map-ul curent. Daca este adevarat, atunci metoda returneaza 'true'. In caz contrar, 'false'.
	bool Includes(const Map<K, V>& map) {

		if (index < map.index)
			return false;

		bool exists;

		for (int i = 0; i < map.index; i++) {

			exists = false;

			for (int j = 0; j < index; j++)
				if (vector[j].key == map.vector[i].key) {

					exists = true;

					break;

				}

			if (exists == false)
				return false;

		}

		return true;

	}

};

#endif //MAP_H_INCLUDED
