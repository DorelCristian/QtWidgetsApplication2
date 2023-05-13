#include "UndoAction.h"
#include "Locatar.h"

class UndoAddAction : public UndoAction
{
public:
	UndoAddAction(RepoLocatar& r, locatars& l) : UndoAction{ r,l } {}
	void doUndo() override
	{

		repo.delete_locatar(locatar.get_apartament());
	}
};