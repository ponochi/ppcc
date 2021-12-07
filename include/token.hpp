/*
 * token.hpp
 *
 *  Created on: 2021/11/25
 *      Author: Nakahara Yoshihiro
 */

#pragma once

#include <memory>
#include <string>

namespace ppcc
{
  class Node
  {
  private:
    std::string token_;

    long logical_line_no_;        // 論理行番号
    long physical_line_no_;       // 実行番号
    std::string def_header_ = ""; // ヘッダでの定義
    long line_num_of_def_header_; // ヘッダでの定義の行番号

    std::shared_ptr<Node> ptr_root_;
    std::shared_ptr<Node> ptr_node1_;
    std::shared_ptr<Node> ptr_node2_;
    std::shared_ptr<Node> ptr_node3_;
    std::shared_ptr<Node> ptr_node4_;
    std::shared_ptr<Node> ptr_node5_;

  protected:
  public:
    Node()
    {
      ptr_node1_ = nullptr;
      ptr_node2_ = nullptr;
      ptr_node3_ = nullptr;
      ptr_node4_ = nullptr;
      ptr_node5_ = nullptr;
    };
    virtual ~Node(){};

    std::string GetToken() { return token_; };
    void SetToken(std::string token) { this->token_ = token; };

    long IncLogicalLineNo() { return ++logical_line_no_; };
    long IncPhysicalLineNo() { return ++physical_line_no_; };
    std::string GetDefHeader() { return def_header_; }
    void SetDefHeader(std::string def_header) { this->def_header_ = def_header; }
    long GetLineNoOfDefHeader() { return line_num_of_def_header_; }
    void SetLineNumOfDefHeader(long line_num_of_def_header) { this->line_num_of_def_header_ = line_num_of_def_header; }

    std::shared_ptr<ppcc::Node> create_p_root()
    {
      ptr_root_ = std::make_shared<ppcc::Node>();
      return ptr_root_;
    };

    std::shared_ptr<ppcc::Node> CreatePNode1()
    {
      ptr_node1_ = std::make_shared<ppcc::Node>();
      return ptr_node1_;
    };

    std::shared_ptr<ppcc::Node> CreatePNode2()
    {
      ptr_node2_ = std::make_shared<ppcc::Node>();
      return ptr_node2_;
    };

    std::shared_ptr<ppcc::Node> CreatePNode3()
    {
      ptr_node3_ = std::make_shared<ppcc::Node>();
      return ptr_node3_;
    };

    std::shared_ptr<ppcc::Node> CreatePNode4()
    {
      ptr_node4_ = std::make_shared<ppcc::Node>();
      return ptr_node4_;
    };

    std::shared_ptr<ppcc::Node> CreatePNode5()
    {
      ptr_node5_ = std::make_shared<ppcc::Node>();
      return ptr_node5_;
    };

    std::shared_ptr<ppcc::Node> GetParent() { return ptr_root_; };
    std::shared_ptr<ppcc::Node> GetNode1() { return ptr_node1_; };
    std::shared_ptr<ppcc::Node> GetNode2() { return ptr_node2_; };
    std::shared_ptr<ppcc::Node> GetNode3() { return ptr_node3_; };
    std::shared_ptr<ppcc::Node> GetNode4() { return ptr_node4_; };
    std::shared_ptr<ppcc::Node> GetNode5() { return ptr_node5_; };

    bool ResetPRoot()
    {
      ptr_root_.reset();
      if (ptr_root_ == nullptr)
      {
        return true;
      }
      else
      {
        return false;
      }
    };

    bool ResetPNode1()
    {
      ptr_node1_.reset();
      if (ptr_node1_ == nullptr)
      {
        return true;
      }
      else
      {
        return false;
      }
    };

    bool ResetPNode2()
    {
      ptr_node2_.reset();
      if (ptr_node2_ == nullptr)
      {
        return true;
      }
      else
      {
        return false;
      }
    };

    bool ResetPNode3()
    {
      ptr_node3_.reset();
      if (ptr_node3_ == nullptr)
      {
        return true;
      }
      else
      {
        return false;
      }
    };

    bool ResetPNode4()
    {
      ptr_node4_.reset();
      if (ptr_node4_ == nullptr)
      {
        return true;
      }
      else
      {
        return false;
      }
    };

    bool ResetPNode5()
    {
      ptr_node5_.reset();
      if (ptr_node5_ == nullptr)
      {
        return true;
      }
      else
      {
        return false;
      }
    };

    void SwapPNode(
        std::shared_ptr<ppcc::Node> node1,
        std::shared_ptr<ppcc::Node> node2)
    {
      std::swap(node1, node2);
    };
  };
}
