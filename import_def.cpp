/*
 * import_def.cpp
 *
 *  Created on: 2021/11/25
 *      Author: Nakahara Yoshihiro
 */

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>

#include "include/import_def.hpp"

void ppcc::ImportDef::LoadResvWord(
    std::vector<ppcc::ResvWord *> *vec_resv_word,
    std::string def_file_name)
{
  std::string file_name = def_file_name;
  std::ifstream ifs;
  std::string line;

  ifs.open(file_name.c_str());

  if (ifs.fail())
  {
    std::cout << "can't open \"" << file_name << "\" definition file." << std::endl;
    exit(1);
  }

  while (getline(ifs, line))
  {
    int first_idx = line.find_first_of("\"") + 1;
    int last_idx = line.find_last_of("\"");

    vec_resv_word->push_back(
        new ppcc::ResvWord(
            line.substr(first_idx, last_idx - first_idx),
            0));
  }

#ifdef _DEBUG
  for (ppcc::ResvWord *resv_word : *vec_resv_word)
  {
    std::cout
        << "ImportDef::LoadRescWord in import_def.cpp" << std::endl;
    std::cout << "  -> " + resv_word->GetWord() << std::endl;
  }
#endif

  ifs.close();
};
