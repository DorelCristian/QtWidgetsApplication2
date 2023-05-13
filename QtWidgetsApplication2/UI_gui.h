#pragma once
#include "ServiceLocatar.h"
#include "RepoLista.h"
class UI
{
	Service service;
	Lista repolista;
public:
	UI(Service serv) :service{ serv } {

	}
	void startUI();

private:

};