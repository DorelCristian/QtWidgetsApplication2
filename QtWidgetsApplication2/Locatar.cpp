#include "Locatar.h"
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

string locatars::get_apartament()const
{
	return apartament;
}
string locatars::get_nume() const
{
	return nume;
}
int locatars::get_suprafata() const
{
	return suprafata;
}
string locatars::get_tip_apartament() const
{
	return tip_apartament;
}
void locatars::set_apartament(string app)
{
	apartament = app;
}
void locatars::set_nume(string num)
{
	nume = num;
}
void locatars::set_suprafata(int supr)
{
	suprafata = supr;
}
void locatars::set_tip_apartament(string tip_apart)
{
	tip_apartament = tip_apart;
}
void test_locatar()
{
	locatars l{ "1","Ion",100,"A" };
	assert(l.get_apartament() == "1");
	assert(l.get_nume() == "Ion");
	assert(l.get_suprafata() == 100);
	assert(l.get_tip_apartament() == "A");
	l.set_apartament("2");
	l.set_nume("Vasile");
	l.set_suprafata(200);
	l.set_tip_apartament("B");
	assert(l.get_apartament() == "2");
	assert(l.get_nume() == "Vasile");
	assert(l.get_suprafata() == 200);
	assert(l.get_tip_apartament() == "B");

}