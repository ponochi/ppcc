/*
 * resv_word.hpp
 *
 *  Created on: 2021/11/25
 *      Author: Nakahara Yoshihiro
 */

#pragma once

#include <string>

namespace ppcc
{
  class ResvWord
  {
  private:
    std::string word_; // 予約語
    long count_;       // 出現回数

  protected:
  public:
    // コンストラクタ
    ResvWord() : word_(std::string("")), count_(0){};
    ResvWord(std::string word, long count) : word_(word), count_(count){};
    virtual ~ResvWord(){};

    std::string GetWord() { return word_; };
    long GetCount() { return count_; };

    // コピーコンストラクタ
    ResvWord(const ResvWord &rhs) : word_(rhs.word_), count_(rhs.count_){

                                                      };
  };
}
