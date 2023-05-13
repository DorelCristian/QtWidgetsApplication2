#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "Locatar.h"
#include "RepoLocatar.h"
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include "UndoAction.h"
#include "UndoAddAction.h"
//#include "Vector.h"
class Service
{
private:
	RepoLocatar repo;
	vector<UndoAction*> undoActions;
public:
	Service(RepoLocatar rep) :repo{ rep } {

	}
	void addLocatar(string apartament, string nume, int suprafata, string tip_apartament) {
		locatars l{ apartament, nume, suprafata, tip_apartament };
		repo.store(l);
		undoActions.push_back(new UndoAddAction{ repo,l });
	}
	void deleteLocatar(string apartament)
	{
		repo.delete_locatar(apartament);
	}
	void updateLocatar(string apartament, string nume, int suprafata, string tip_apartament)
	{
		repo.update_locatar(apartament, nume, suprafata, tip_apartament);
	}
	/*/void showAll()
	{
		vector<locatars> locatari = repo.getAll();
		for (const auto& locatar : locatari)
		{
			cout << locatar.get_apartament() << " " << locatar.get_nume() << " " << locatar.get_suprafata() << " " << locatar.get_tip_apartament() << endl;
		}
	}*/




	/*VectorDin<locatars> filtrareDupaNume(string nume)
	{
		VectorDin<locatars> locatarii = repo.getAll();
		for (int i = 0; i < locatarii.size(); i++)
		{
			if (locatarii[i].get_nume() != nume)
			{
				locatarii.erase(i);
			}
		}


		//int i = 0;
		//for (const auto& locatar : locatarii)
		//{
		//	if (locatar.get_nume() != nume)
		//	{
		//		locatarii.erase(i);
		//	}
		//	i++;
		//}
		return locatarii;       //Versiune template
	}*/
	vector<locatars> filtrareDupaNume(string nume)
	{
		vector<locatars> locatarii = repo.getAll();
		auto copy_if = [](vector<locatars> locatarii, string nume) {
			vector<locatars> locatarii_nume;
			for (const auto& locatar : locatarii)
			{
				if (locatar.get_nume() == nume)
				{
					locatarii_nume.push_back(locatar);
				}
			}
			return locatarii_nume;
		};
		return copy_if(locatarii, nume);

	}








	/*VectorDin<locatars>filtrareDupaSuprafata(int suprafata)
	{
		VectorDin<locatars> locatarii = repo.getAll();
		/*for (auto it = locatarii.begin(); it != locatarii.end(); )
		{
			if (it->get_suprafata() > suprafata)
			{
				it = locatarii.erase(it);
			}
			else
			{
				++it;
			}
		}*
		/*int i = 0;
		for (const auto& locatar : locatarii)
		{
			if (locatar.get_suprafata() != suprafata)
			{
				locatarii.erase(i);
			}
			i++;
		}*
		for (int i = 0; i < locatarii.size(); i++)
		{
			if (locatarii[i].get_suprafata() != suprafata)
			{
				locatarii.erase(i);
			}
		}
		return locatarii;
	}*/
	vector <locatars>filtrareDupaSuprafata(int suprafata)
	{
		vector<locatars> locatarii = repo.getAll();
		auto copy_if = [](vector<locatars> locatarii, int suprafata) {
			vector<locatars> locatarii_suprafata;
			for (const auto& locatar : locatarii)
			{
				if (locatar.get_suprafata() == suprafata)
				{
					locatarii_suprafata.push_back(locatar);
				}
			}
			return locatarii_suprafata;
		};
		return copy_if(locatarii, suprafata);
	}

	//find locatar by apartament
	locatars findLocatar(string apartament)
	{
		vector<locatars> locatarii = repo.getAll();
		for (auto locatar : locatarii)
		{
			if (locatar.get_apartament() == apartament)
			{
				return locatar;
			}
		}
		return locatars{ "", "", 0, "" };
	}











	/*VectorDin <locatars>filtrareDupaTip(string tip)
	{
		VectorDin<locatars> locatarii = repo.getAll();
		/*for (auto it = locatarii.begin(); it != locatarii.end(); )
		{
			if (it->get_tip_apartament() != tip)
			{
				it = locatarii.erase(it);
			}
			else
			{
				++it;
			}
		}*
		/*int i = 0;
		for (const auto& locatar : locatarii)
		{
			if (locatar.get_tip_apartament() != tip)
			{
				locatarii.erase(i);
			}
			i++;
		}*
		for (int i = 0; i < locatarii.size(); i++)
		{
			if (locatarii[i].get_tip_apartament() != tip)
			{
				locatarii.erase(i);
			}
		}
		return locatarii;
	}*/

	vector <locatars>filtrareDupaTip(string tip)
	{
		vector<locatars> locatarii = repo.getAll();
		auto copy_if = [](vector<locatars> locatarii, string tip) {
			vector<locatars> locatarii_tip;
			for (const auto& locatar : locatarii)
			{
				if (locatar.get_tip_apartament() == tip)
				{
					locatarii_tip.push_back(locatar);
				}
			}
			return locatarii_tip;
		};
		//vector<locatars> locatarii_tip;
		//copy_if(locatarii.begin(), locatarii.end(), locatarii_tip.begin(), );
		//copy_if(locatarii.begin(), locatarii.end(), locatarii_tip.begin(), [tip](locatars s) {return s.get_tip_apartament() == tip; });

		return copy_if(locatarii, tip);
	}











	/*VectorDin <locatars>sortareDupaNume()
	{
		VectorDin<locatars> locatarii = repo.getAll();
		for (int i = 0; i < locatarii.size() - 1; i++)
		{
			for (int j = i + 1; j < locatarii.size(); j++)
			{
				if (locatarii[i].get_nume() > locatarii[j].get_nume())
				{
					swap(locatarii[i], locatarii[j]);
				}
			}
		}
		return locatarii;
	}*/
	vector <locatars>sortareDupaNume()
	{
		vector<locatars> locatarii = repo.getAll();
		auto sort = [](vector<locatars> locatarii) {
			vector<locatars> locatarii_nume;
			for (int i = 0; i < locatarii.size() - 1; i++)
			{
				for (int j = i + 1; j < locatarii.size(); j++)
				{
					if (locatarii[i].get_nume() > locatarii[j].get_nume())
					{
						swap(locatarii[i], locatarii[j]);
					}
				}
			}
			return locatarii;
		};
		return sort(locatarii);
	}










	/*VectorDin<locatars> sortareDupaSuprafata()
	{
		VectorDin<locatars> locatarii = repo.getAll();
		for (int i = 0; i < locatarii.size() - 1; i++)
		{
			for (int j = i + 1; j < locatarii.size(); j++)
			{
				if (locatarii[i].get_suprafata() > locatarii[j].get_suprafata())
				{
					swap(locatarii[i], locatarii[j]);
				}
			}
		}
		return locatarii;
	}*/
	vector<locatars> sortareDupaSuprafata()
	{
		vector<locatars> locatarii = repo.getAll();
		auto sort = [](vector<locatars> locatarii) {
			vector<locatars> locatarii_suprafata;
			for (int i = 0; i < locatarii.size() - 1; i++)
			{
				for (int j = i + 1; j < locatarii.size(); j++)
				{
					if (locatarii[i].get_suprafata() > locatarii[j].get_suprafata())
					{
						swap(locatarii[i], locatarii[j]);
					}
				}
			}
			return locatarii;
		};
		return sort(locatarii);
	}










	/*VectorDin <locatars> sortareDupaTip()
	{
		VectorDin<locatars> locatarii = repo.getAll();
		for (int i = 0; i < locatarii.size() - 1; i++)
		{
			for (int j = i + 1; j < locatarii.size(); j++)
			{
				if (locatarii[i].get_tip_apartament() > locatarii[j].get_tip_apartament())
				{
					swap(locatarii[i], locatarii[j]);
				}
			}
		}
		return locatarii;
	}*/
	vector<locatars> sortareDupaTip()
	{
		vector<locatars> locatarii = repo.getAll();
		auto sort = [](vector<locatars> locatarii) {
			vector<locatars> locatarii_tip;
			for (int i = 0; i < locatarii.size() - 1; i++)
			{
				for (int j = i + 1; j < locatarii.size(); j++)
				{
					if (locatarii[i].get_tip_apartament() > locatarii[j].get_tip_apartament())
					{
						swap(locatarii[i], locatarii[j]);
					}
				}
			}
			return locatarii;
		};
		return sort(locatarii);
	}


	void undoAdauga()
	{
		if (undoActions.empty())
		{
			;
			cout << "Nu mai exista operatii de undo!";
		}
		else {
			cout << "we have been here";
			UndoAction* actiune = undoActions.back();
			actiune->doUndo();
			/*undoActions.pop_back();
			delete actiune;*/
		}
	}


	void undoSterge()
	{
		if (undoActions.empty())
		{
			;
			cout << "Nu mai exista operatii de undo!";
		}
		else {
			UndoAction* actiune = undoActions.back();
			actiune->doUndo();
			undoActions.pop_back();
			delete actiune;
		}
	}

	void undoModifica()
	{
		if (undoActions.empty())
		{
			;
			cout << "Nu mai exista operatii de undo!";
		}
		else {
			UndoAction* actiune = undoActions.back();
			actiune->doUndo();
			undoActions.pop_back();
			delete actiune;
		}
	}

	vector<locatars>getListaAll()
	{
		//return 0;
	}


	/*VectorDin<locatars> getAll()
	{
		return repo.getAll();
	}*/
	vector<locatars> getAll()
	{
		return repo.getAll();
	}
};
void test_add_service();
void test_all_service();