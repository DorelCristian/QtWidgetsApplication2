#include "RepoLocatar.h"
#include <assert.h>
/*void test_repo()
{

	RepoLocatar r;


	locatars l1{ "1","Ionescu",120,"garsoniera"};
	locatars l2{ "2","Popescu",100,"garsoniera"};
	r.store(l1);
	r.store(l2);
	auto locatari = r.getAll();
	assert(locatari.size() == 2);
	try
	{
		r.store(l1);
		//assert("true");
	}
	catch (RepoException & e)
	{
		assert(e.get_msg() == "Locatarul deja exista");
	}
	r.delete_locatar("1");
	locatari = r.getAll();
	assert(locatari.size() == 1);
	try
	{
		r.delete_locatar("9");
		//assert("true");
	}
	catch (RepoException& e)
	{
		assert(e.get_msg() == "Locatarul nu exista");
	}
	//r.update_locatar("2", "Popescu", 120, "garsoniera");
	 locatari = r.getAll();
	/**assert(locatari[0].get_suprafata() == 120);
	assert(locatari[0].get_nume() == "Popescu");
	assert(locatari[0].get_tip_apartament() == "garsoniera");*


}*/

void test_update()
{
	RepoLocatar r;
	locatars l1{ "1","Ionescu",120,"garsoniera" };
	locatars l2{ "2","Popescu",100,"garsoniera" };
	r.store(l1);
	r.store(l2);
	r.update_locatar("2", "Popescu", 120, "garsoniera");
	auto locatari = r.getAll();
	assert(locatari[1].get_suprafata() == 120);
	assert(locatari[1].get_nume() == "Popescu");
	assert(locatari[1].get_tip_apartament() == "garsoniera");
	try
	{
		r.update_locatar("9", "Popescu", 120, "garsoniera");
	}
	catch (RepoException& e)
	{
		assert(e.get_msg() == "Locatarul nu exista");
	}
}