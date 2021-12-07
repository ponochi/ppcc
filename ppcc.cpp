/*
 * ppcc.cpp
 *
 *  Created on: 2021/11/25
 *      Author: Nakahara Yoshihiro
 */

#include <fstream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

#include "include/parser.hpp"
#include "include/ppcc.hpp"

#define MAX_NUM_OF_RESV_WORD 32

int main(int argc, char **argv)
{
  /*
   * "resv_word" is Reserved words of C Language.
   * "vec_resv_word" is wrapped *resv_word the vector.
   * "node" is an instance with a token set obtained
   * by parsing the target source code.
   */
  std::vector<ppcc::ResvWord *> *vec_resv_word = new std::vector<ppcc::ResvWord *>();
  ppcc::Node *node = new ppcc::Node();
  ppcc::Parser *parser = new ppcc::Parser(vec_resv_word);

  parser->LoadResvWord(vec_resv_word);

  for (ppcc::ResvWord *resv_word : *vec_resv_word)
  {
    std::cout << resv_word->GetWord() << std::endl;
  }

  for (int i = 1; i <= argc; i++)
  {
    parser->ParseSourceCode(argv[i], vec_resv_word, node);
  }

  // メモリ開放
  for (ppcc::ResvWord *resv_word : *vec_resv_word)
  {
    delete resv_word;
  }
  delete vec_resv_word;
  delete parser;
}
