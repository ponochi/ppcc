/*
 * parser.hpp
 *
 *  Created on: 2021/11/25
 *      Author: Nakahara Yoshihiro
 */

#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <string>

#include "token.hpp"
#include "import_def.hpp"
#include "resv_word.hpp"

namespace ppcc
{
  class Parser
  {
  private:
    ppcc::Node *root_;
    ppcc::ImportDef *imp_def_;

  protected:
  public:
    Parser(const std::vector<ppcc::ResvWord *> *vec_resv_word){};
    virtual ~Parser(){};

    auto MatchToken(std::vector<ppcc::ResvWord *> *vec_resv_word, std::string word) -> int;
    void LoadResvWord(std::vector<ppcc::ResvWord *> *vec_resv_word);
    void ParseSourceCode(std::string file_name, std::vector<ppcc::ResvWord *> *vec_resv_word, ppcc::Node *node);
  };
}
