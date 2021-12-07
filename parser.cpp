/*
 * parser.cpp
 *
 *  Created on: 2021/11/25
 *      Author: Nakahara Yoshihiro
 */

#include <memory>
#include <regex>

#include "include/parser.hpp"
#include "include/util.hpp"

auto MatchToken(std::vector<ppcc::ResvWord *> *vec_resv_word, std::string word) -> int
{
  // TODO If the word passed as argument matches the list of reserved words, 0 is returned. Otherwise, -1 is returned.

  for (ppcc::ResvWord *rw : *vec_resv_word)
  {
    if ((word.length() > 0) && (word.compare(rw->GetWord().c_str())))
    {
      return 0;
    }
  }

  return -1;
};

void ppcc::Parser::LoadResvWord(std::vector<ppcc::ResvWord *> *vec_resv_word)
{
  std::string file_name = "resv_word.def";
  std::string resv_word = "";

  imp_def_ = new ppcc::ImportDef();

  imp_def_->LoadResvWord(
      vec_resv_word,
      file_name);
}

void ppcc::Parser::ParseSourceCode(std::string file_name, std::vector<ppcc::ResvWord *> *vec_resv_word, ppcc::Node *node)
{
  std::ifstream ifs;
  std::string line;
  std::string chars_to_trim = " \t";
  bool is_blk_comment = false;
  std::smatch results1, results2;

  ifs.open(file_name.c_str());

  if (ifs.fail())
  {
    std::cout << "can't open \"" << file_name << "\" definition file." << std::endl;
    exit(1);
  }

  // TODO The target source code is read and analyzed, and tokens are set in *nodes. A *node is a tree structure, and each level can hold up to five *nodes.
  printf("== %s ==============================\n", file_name.c_str());
  while (getline(ifs, line))
  {
    while (line.length() > 0)
    {
      //      LeftTrim(line, chars_to_trim);

      if (std::regex_search(line, results1, std::regex("/\\x2A")))
      {
        // 開始ブロックコメントが検出された場合
        if (results1.position() > 0)
        {
          // 行の途中で開始ブロックコメントが検出された場合、検出された箇所の次の文字以降を解析対象とする
          line = line.substr(results1.position());
        }

        if (std::regex_search(line, results2, std::regex("\\x2A/")))
        {
          // 閉じブロックコメントが検出された場合
          std::cout << line.substr(0, results2.position() + results2.length()) << std::endl;

          line = line.substr(results2.position() + results2.length());

          is_blk_comment = false;
        }
        else
        {
          // 閉じブロックコメントがなかった場合
          // (ブロックコメントが続く場合)
          std::cout << line << std::endl;

          line = "";
          is_blk_comment = true;
        }
      }
      else
      {
        // TODO 行中に開始ブロックコメントが検出されなかった

        if (is_blk_comment == true)
        {
          // ブロックコメントの途中の行の場合
          if (std::regex_search(line, results2, std::regex("\\x2A/")))
          {
            // 閉じブロックコメントが検出された場合
            std::cout << line.substr(0, results2.position() + results2.length()) << std::endl;

            line = line.substr(results2.position() + results2.length());

            is_blk_comment = false;
          }
          else
          {
            // 閉じブロックコメントが検出されなかった場合
            std::cout << line << std::endl;
            line = "";
          }
        }
        else if (is_blk_comment == false)
        {
          // TODO ブロックコメントではない行の場合
          line = "";
        }
      }
    }
  }

  printf("== %s ==============================\n", file_name.c_str());
  ifs.close();
}
