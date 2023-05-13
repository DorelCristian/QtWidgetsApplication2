
#include "UI_gui.h"
#include <iostream>
#include <string.h>
#include <vector>
#include "RepoLista.h"
using namespace std;

void UI::startUI() {

	while (true)
	{
		cout << "1. Adauga locatar" << endl;
		cout << "2. Afiseaza locatari" << endl;
		cout << "3. Sterge locatar" << endl;
		cout << "4. Modifica locatar" << endl;
		cout << "5. Filtrare dupa nume" << endl;
		cout << "6. Filtrare dupa suprafata" << endl;
		cout << "7. Filtrare dupa tip" << endl;
		cout << "8. Sortare dupa nume" << endl;
		cout << "9. Sortare dupa suprafata" << endl;
		cout << "10. Sortare dupa tip" << endl;
		cout << "11. Undo" << endl;
		cout << "12. Exit" << endl;
		cout << "13. Goleste lista. Sterge toate apartamentele din lista" << endl;
		cout << "14. Adauga in lista. Adauga un apartament dupa nrApartament" << endl;
		cout << "15. Genereaza lista. Utilizatorul introduce numar total de apartamente, lista se populeaza aleator cu apartamente" << endl;
		cout << "16. Afiseaza lista" << endl;
		cout << "17. Export in fisier" << endl;
		cout << "Introduceti optiunea: ";
		int opt;
		cin >> opt;
		if (opt == 1)
		{
			string apartament, nume, tip_apartament;
			int suprafata;
			cout << "Introduceti apartamentul: ";
			cin >> apartament;
			cout << "Introduceti numele: ";
			cin >> nume;
			cout << "Introduceti suprafata: ";

			cin >> suprafata;

			cout << "Introduceti tipul apartamentului: ";
			cin >> tip_apartament;
			try
			{
				service.addLocatar(apartament, nume, suprafata, tip_apartament);
			}
			catch (RepoException& ex)
			{
				cout << ex.get_msg() << endl;
			}
		}
		else if (opt == 2)
		{
			//VectorDin<locatars> locatari = service.getAll();
			vector<locatars> locatari = service.getAll();
			cout << "Apartament\t\tNume\t\tSuprafata\t\tTip apartament\n";
			for (const auto& locatar : locatari)
			{
				cout << locatar.get_apartament() << "\t\t" << locatar.get_nume() << "\t\t" << locatar.get_suprafata() << "\t\t" << locatar.get_tip_apartament() << endl;
			}
		}
		else if (opt == 3)
		{
			string apartament;
			cout << "Introduceti apartamentul:";
			cin >> apartament;
			try
			{
				service.deleteLocatar(apartament);
			}
			catch (RepoException& ex)
			{
				cout << ex.get_msg() << endl;
			}
		}
		else if (opt == 4)
		{
			string apartament;
			cout << "Introduceti apartamentul:";
			cin >> apartament;
			string nume, tip_apartament;
			int suprafata;
			cout << "Introduceti numele: ";
			cin >> nume;
			cout << "Introduceti suprafata: ";
			cin >> suprafata;
			cout << "Introduceti tipul apartamentului: ";
			cin >> tip_apartament;
			try
			{
				service.updateLocatar(apartament, nume, suprafata, tip_apartament);
				;
			}
			catch (RepoException& ex)
			{
				cout << ex.get_msg() << endl;
			}
		}
		else if (opt == 5)
		{
			cout << "Introduceti numele proprietarului";
			string nume;
			cin >> nume;
			//VectorDin<locatars> locatari = service.filtrareDupaNume(nume);
			vector<locatars> locatari = service.filtrareDupaNume(nume);
			for (const auto& locatar : locatari)
			{
				cout << locatar.get_apartament() << " " << locatar.get_nume() << " " << locatar.get_suprafata() << " " << locatar.get_tip_apartament() << endl;
			}
		}
		else if (opt == 6)
		{
			cout << "Introduceti suprafata: ";
			int suprafata;
			cin >> suprafata;
			//VectorDin<locatars> locatari = service.filtrareDupaSuprafata(suprafata);
			vector<locatars> locatari = service.filtrareDupaSuprafata(suprafata);
			for (const auto& locatar : locatari)
			{
				cout << locatar.get_apartament() << " " << locatar.get_nume() << " " << locatar.get_suprafata() << " " << locatar.get_tip_apartament() << endl;
			}
		}
		else if (opt == 7)
		{
			cout << "Introduceti tipul apartamentului:";
			string tip_apartament;
			cin >> tip_apartament;
			//VectorDin<locatars> locatari = service.filtrareDupaTip(tip_apartament);
			vector<locatars> locatari = service.filtrareDupaTip(tip_apartament);
			for (const auto& locatar : locatari)
			{
				cout << locatar.get_apartament() << " " << locatar.get_nume() << " " << locatar.get_suprafata() << " " << locatar.get_tip_apartament() << endl;
			}
		}
		else if (opt == 8)
		{
			//VectorDin<locatars> locatari = service.sortareDupaNume();
			vector<locatars> locatari = service.sortareDupaNume();
			for (const auto& locatar : locatari)
			{
				cout << locatar.get_apartament() << " " << locatar.get_nume() << " " << locatar.get_suprafata() << " " << locatar.get_tip_apartament() << endl;
			}
		}
		else if (opt == 9)
		{
			//VectorDin<locatars> locatari = service.sortareDupaSuprafata();
			vector<locatars> locatari = service.sortareDupaSuprafata();
			for (const auto& locatar : locatari)
			{
				cout << locatar.get_apartament() << " " << locatar.get_nume() << " " << locatar.get_suprafata() << " " << locatar.get_tip_apartament() << endl;
			}
		}
		else if (opt == 10)
		{
			//VectorDin<locatars> locatari = service.sortareDupaTip();
			vector<locatars> locatari = service.sortareDupaTip();
			for (const auto& locatar : locatari)
			{
				cout << locatar.get_apartament() << " " << locatar.get_nume() << " " << locatar.get_suprafata() << " " << locatar.get_tip_apartament() << endl;
			}
		}
		else if (opt == 11)
		{
			;
			//service.undo();
			cout << "1. UNDO Adauga ";
			cout << "2. UNDO Sterge ";
			cout << "3. UNDO Modifica ";
			int optiune;
			cin >> optiune;
			if (optiune == 1)
			{
				service.undoAdauga();
			}
			else if (optiune == 2)
			{
				//service.undoSterge();
			}
			else if (optiune == 3)
			{
				//service.undoModifica();
			}

		}
		else if (opt == 12)
		{
			break;
		}
		else if (opt == 13)
		{
			//sterge apartamente din lista
			repolista.clearList();
		}
		else if (opt == 14)
		{
			//adauga in lista adaugã un apartament dupã nrApartament
			locatars l;
			vector < locatars> locatari = service.getAll();
			cout << "Introduceti numarul apartamentului: ";
			string Apartament;
			cin >> Apartament;
			for (const auto& locatar : locatari)
			{
				if (locatar.get_apartament() == Apartament)
				{
					l = locatar;
				}
			}
			repolista.addList(l);
		}
		else if (opt == 15)
		{
			//• Genereazã lista: utilizatorul introduce numãrul total de apartamente, lista se populeazã aleator cu apartamente
			cout << "Introduceti numar apartamente ";
			int NR;
			cin >> NR;
			vector < locatars> locatari = service.getAll();
			repolista.fillList(NR, locatari);


		}
		else if (opt == 16)
		{
			repolista.printList();
		}
		else if (opt == 17)
		{
			cout << "1.Export to CSV\n";
			cout << "2.Export to HTML\n";
			int optiune;
			cin >> optiune;
			cout << "Introduceti titlu fisier";
			string  titlu;
			cin >> titlu;
			if (optiune == 1)
			{
				;
				//repolista.exportCSV();
			}
			else if (optiune == 2)
			{
				;
				//repolista.exportHTML();
			}
		}
	}
}