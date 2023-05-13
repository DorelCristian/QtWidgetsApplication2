#include "Vector.h"
#include <iostream>
#include <string.h>
#include "Locatar.h"
#include "RepoLocatar.h"
#include "ServiceLocatar.h"
//#include "UI.h"
#include <assert.h>
using namespace std;

void test_vector()
{
	//RepoLocatar repo;
	//Vector<locatars> v;
	VectorDin<locatars> v;

	locatars l1{ "1","Ion",100,"A" };
	locatars l2{ "2","Vasile",200,"B" };
	v.push_back(l1);
	v.push_back(l2);

	assert(v.size() == 2);
	assert(v[0].get_apartament() == "1");
	assert(v[1].get_apartament() == "2");
	assert(v[0].get_nume() == "Ion");
	assert(v[1].get_nume() == "Vasile");
	assert(v[0].get_suprafata() == 100);
	assert(v[1].get_suprafata() == 200);
	assert(v[0].get_tip_apartament() == "A");
	assert(v[1].get_tip_apartament() == "B");

	v.erase(0);
	assert(v.size() == 1);
	assert(v[0].get_apartament() == "2");
	assert(v[0].get_nume() == "Vasile");
	assert(v[0].get_suprafata() == 200);
	assert(v[0].get_tip_apartament() == "B");

	for (int i = 1; i <= 100; i++)
	{
		locatars l1{ "1","Ion",100,"A" };
		v.push_back(l1);
	}

	//	v.pop_back();

}