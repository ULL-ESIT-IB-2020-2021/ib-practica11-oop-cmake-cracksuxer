#ifndef _RAC_TOOLS_
#define _RAC_TOOLS_

#include <map>
#include <string>
#include <vector>
#include "racional_func.h"

void InputHandler(int argc, char *argv[]);
int GetTotalLines();
void Rac_map_objs(std::vector<std::string> num_denom, std::map<std::string, Racional*> &undefined_rac_objects, int &number);
std::map<std::string, Racional*> ParseRacionalesText();
void Output_operats(std::string file_name, std::map<std::string, Racional*> rac_file_objs);

#endif