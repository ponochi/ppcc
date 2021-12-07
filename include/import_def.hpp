/*
 * import_def.hpp
 *
 *  Created on: 2021/11/25
 *      Author: Nakahara Yoshihiro
 */

#pragma once

#include <fstream>
#include <istream>
#include <ostream>

#include <string>
#include <vector>

#include "resv_word.hpp"

namespace ppcc
{
  class ImportDef
  {
  private:
  protected:
  public:
    ImportDef(){};
    virtual ~ImportDef(){};

    void LoadResvWord(
        std::vector<ppcc::ResvWord *> *vec_resv_word,
        std::string file_name);
  };
}
