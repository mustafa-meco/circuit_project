#include "operate.h"
#include"../ApplicationManager.h"
Actionoperate::Actionoperate(ApplicationManager* pApp) :Action(pApp)
{

}
Actionoperate::~Actionoperate(void) {

}

void Actionoperate::Execute()
{
	pManager->operation();
}

void Actionoperate::Undo()
{

 }
void Actionoperate::Redo()
{

}