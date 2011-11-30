#ifndef IO_H
#define IO_H
#include <vector>
#include "screening.h"

void loadScreenings(std::vector<Screening> *vec);
void saveScreenings(std::vector<Screening> *vec);

#endif