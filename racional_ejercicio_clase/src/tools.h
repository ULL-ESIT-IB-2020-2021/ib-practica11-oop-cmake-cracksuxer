#ifndef _RAC_TOOLS_
#define _RAC_TOOLS_

#include <map>
#include <string>
#include <vector>
#include "racional.h"

void InputHandler(int argc, char *argv[]);
int GetTotalLines();
void RacMapObjs(std::vector<std::string> num_denom, std::map<std::string, Racional*> &undefined_rac_objects, int &number);
std::map<std::string, Racional*> ParseRacionalesText();
void Output_operats(std::string file_name, std::map<std::string, Racional*> rac_file_objs);

#endif