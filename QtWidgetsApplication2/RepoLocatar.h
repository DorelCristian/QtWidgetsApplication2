#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Locatar.h"
//#include "Vector.h"
using namespace std;
class RepoException
{
	string msg;
public:
	RepoException(string m) :msg{ m } {}
	string get_msg() const { return msg; }

};

class RepoLocatar
{
private:
	vector<locatars> locatari;
	//VectorDin<locatars> locatari;
public:
	void store(const locatars& l)
	{
		for (const auto& locatar : locatari)
		{
			if (locatar.get_apartament() == l.get_apartament())
				throw RepoException("Locatarul deja exista");
		}
		locatari.push_back(l);
	}
	vector<locatars> getAll()
	{
		return locatari;
	}
	//VectorDin<locatars> getAll()
	//{
	//	return locatari;
	//}//Varianta template


	/*void delete_locatar(string apartament)
	{
		;
	}*/


	void delete_locatar(string apartament)
	{
		/*int i = 0;
		for (const auto& locatar : locatari)
		{
			if (locatar.get_apartament() == apartament)
			{
				//locatari.pop_back();
				//locatari.erase(remove(locatari.begin(), locatari.end(), locatar), locatari.end());
				//locatari.
				locatari.erase(i);
				return;
			}
			i++;
		}*/
		for (auto it = locatari.begin(); it != locatari.end(); ++it) {
			if (it->get_apartament() == apartament) {
				locatari.erase(it);
				break; // Only remove the first matching element
				return;
			}
		}
		//throw RepoException("Locatarul nu exista");
	}








	/*void update_locatar(string apartament, string nume, int suprafata, string tip_apartament)
	{
		;
	}*/

	void update_locatar(string apartament, string nume, int suprafata, string tip_apartament)
	{
		for (size_t i = 0; i < locatari.size(); i++)
		{
			if (locatari[i].get_apartament() == apartament)
			{
				locatari[i].set_nume(nume);
				locatari[i].set_suprafata(suprafata);
				locatari[i].set_tip_apartament(tip_apartament);
				return;
			}
		}
		//throw RepoException("Locatarul nu exista");
	}
};
void test_repo();
void test_update();