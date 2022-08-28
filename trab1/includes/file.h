#ifndef __FILE_H
#define __FILE_H

#include "list.h"

void writeFileFromList(List *list, char filename[]);
void readFileAndInsertIntoList(List *list, char filename[]);

#endif