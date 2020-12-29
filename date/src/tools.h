#ifndef _FECHA_TOOLS_
#define _FECHA_TOOLS_

#include <vector>
#include <string>

void InputHandler(int argc, char *argv[]);
void NextDays(int N, int day, int month, int year, std::string file_name);
std::vector<int> ParseString(std::string date);

#endif