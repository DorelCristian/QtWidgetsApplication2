#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class locatars
{
public:
	locatars() : apartament(""), nume(""), suprafata(0), tip_apartament("") {}
	locatars(string apartament, string nume, int suprafata, string tip_apartament) :apartament{ apartament }, nume{ nume }, suprafata{ suprafata }, tip_apartament{ tip_apartament } {

	}

	//~locatar();
	string get_apartament() const;
	string get_nume() const;
	int get_suprafata() const;
	string get_tip_apartament()const;
	void set_apartament(string apartament);
	void set_nume(string nume);
	void set_suprafata(int suprafata);
	void set_tip_apartament(string tip_apartament);


private:
	string apartament;
	string nume;
	int suprafata;
	string tip_apartament;
};
void test_locatar();