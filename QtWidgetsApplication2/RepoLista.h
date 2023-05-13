#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Locatar.h"
#include "RepoLocatar.h"
#include <random>
#include <algorithm>
#include <chrono>
#include "ServiceLocatar.h"

using std::vector;
using std::shuffle;

class Lista : public locatars
{
	//Service service;
	vector<locatars> ListaApp;
public:
	//Lista();
	void addList(locatars l)
	{
		ListaApp.push_back(l);
	}
	void clearList()
	{
		ListaApp.clear();
	}
	vector<locatars> getListaAll()
	{
		return ListaApp;
	}
	void printList()
	{
		for (int i = 0; i < ListaApp.size(); i++)
		{
			cout << ListaApp[i].get_apartament() << " " << ListaApp[i].get_nume() << " " << ListaApp[i].get_suprafata() << " " << ListaApp[i].get_tip_apartament() << endl;
		}
	}
	void fillList(int nr, vector<locatars> locatari)
	{
		/*this->clearList();
		vector<int> v;
		for (int i = 0; i < locatari.size(); i++)
		{
			v.push_back(i);
		}
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		shuffle(v.begin(), v.end(), std::default_random_engine(seed));
		for (int i = 0; i < nr; i++)
		{
			this->addList(locatari[v[i]]);
		}*/
	}
	/*void fillList(int nr)
	{
		;
		this->clearList();
		vector<locatars> locatari = service.getAll();
		for (int i = 0; i < nr; i++)
		{
			this->addList(locatari[i]);
		}
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		shuffle(ListaApp.begin(), ListaApp.end(), std::default_random_engine(seed));

	}*/
	//~Lista();
};
