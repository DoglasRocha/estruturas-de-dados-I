#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "list.h"

void SysEvaluateOption(List *list, int option);
void SysInsertPersonFromFile(List *list, char name[], char rg[]);

#endif