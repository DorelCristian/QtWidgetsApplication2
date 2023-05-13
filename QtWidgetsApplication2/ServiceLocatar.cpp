#include "ServiceLocatar.h"
#include <iostream>
#include <string.h>
#include <assert.h>
#include "Vector.h"


void test_add()
{
	RepoLocatar r;
	Service s{ r };

	s.addLocatar("1", "Ion", 100, "A");
	assert(s.getAll().size() == 1);
	try
	{
		s.addLocatar("1", "Ion", 100, "A");
	}
	catch (RepoException& e)
	{
		assert(e.get_msg() == "Locatarul deja exista");
	}
	s.deleteLocatar("1");
	assert(s.getAll().size() == 0);
	s.addLocatar("1", "Ion", 100, "A");
	s.updateLocatar("1", "Ion", 120, "A");
	assert(s.getAll()[0].get_suprafata() == 120);
	try
	{
		s.updateLocatar("9", "Ion", 120, "A");
	}
	catch (RepoException& e)
	{
		assert(e.get_msg() == "Locatarul nu exista");
	}

}
void test_filtare()
{
	RepoLocatar r;
	Service s{ r };
	s.addLocatar("1", "Ion1", 100, "A");
	s.addLocatar("2", "Ion2", 120, "A");
	s.addLocatar("3", "Ion3", 100, "B");

	vector<locatars> rez = s.filtrareDupaSuprafata(100);
	//VectorDin<locatars> rez = s.filtrareDupaSuprafata(100);
	assert(rez.size() == 2);
	assert(rez[0].get_suprafata() == 100);
	assert(rez[1].get_suprafata() == 100);
	assert(rez[0].get_apartament() == "1");
	assert(rez[1].get_apartament() == "3");

	//s.addLocatar("4", "Vasile", 100, "A");
	vector<locatars> rez2 = s.filtrareDupaNume("Ion");
	//VectorDin<locatars> rez2 = s.filtrareDupaNume("Ion");
	assert(rez2.size() == 3);
	assert(rez2[0].get_nume() == "Ion1");
	assert(rez2[1].get_nume() == "Ion2");
	assert(rez2[2].get_nume() == "Ion3");
	assert(rez2[0].get_apartament() == "1");
	assert(rez2[1].get_apartament() == "2");
	assert(rez2[2].get_apartament() == "3");

	s.addLocatar("4", "Vasile", 100, "A");
	vector<locatars> rez3 = s.filtrareDupaTip("A");
	//VectorDin<locatars> rez3 = s.filtrareDupaTip("A");
	assert(rez3.size() == 3);
	assert(rez3[0].get_apartament() == "1");
	assert(rez3[1].get_apartament() == "2");
	assert(rez3[2].get_apartament() == "4");


}

void test_sortare()
{
	RepoLocatar r;
	Service s{ r };
	s.addLocatar("1", "Ionut", 100, "A");
	s.addLocatar("2", "Ion", 120, "B");
	s.addLocatar("3", "Alin", 101, "D");
	s.addLocatar("4", "Vasilec", 102, "C");
	s.addLocatar("5", "Vasile", 103, "E");
	//VectorDin<locatars> rez = s.sortareDupaNume();
	vector<locatars> rez = s.sortareDupaNume();
	assert(rez.size() == 5);
	assert(rez[0].get_apartament() == "3");
	assert(rez[1].get_apartament() == "2");
	assert(rez[2].get_apartament() == "1");
	assert(rez[3].get_apartament() == "5");
	assert(rez[4].get_apartament() == "4");

	//VectorDin<locatars> rez2 = s.sortareDupaSuprafata();
	vector<locatars> rez2 = s.sortareDupaSuprafata();

	assert(rez2.size() == 5);
	assert(rez2[0].get_apartament() == "1");
	assert(rez2[1].get_apartament() == "3");
	assert(rez2[2].get_apartament() == "4");
	assert(rez2[3].get_apartament() == "5");
	assert(rez2[4].get_apartament() == "2");

	//VectorDin<locatars> rez3 = s.sortareDupaTip();
	vector<locatars> rez3 = s.sortareDupaTip();

	assert(rez3.size() == 5);
	assert(rez3[0].get_apartament() == "1");
	assert(rez3[1].get_apartament() == "2");
	assert(rez3[2].get_apartament() == "4");
	assert(rez3[3].get_apartament() == "3");
	assert(rez3[4].get_apartament() == "5");


}
void test_all_service()
{
	test_sortare();
	//test_filtare();
	test_add();
}