#pragma once

#include "RepoLocatar.h"
#include "Locatar.h"

class UndoAction
{
protected:
	RepoLocatar& repo;
	locatars locatar;
public:
	UndoAction(RepoLocatar& r, locatars& l) : repo{ r }, locatar{ l } {}
	virtual void doUndo() = 0;
	//virtual ~UndoAction() {}


};