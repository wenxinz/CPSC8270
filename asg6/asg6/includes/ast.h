#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <vector>
#include "literal.h"
#include "tableManager.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

enum VarType{ local, global, args};

/* ************************************************************************************************* */
class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id), tag(local) {}
  IdentNode(const std::string id, VarType t) : Node(), ident(id), tag(t) {} 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  VarType getTag() const {return tag;}
  virtual const Literal* eval() const;
private:
  std::string ident;
  VarType tag;
};

/* ************************************************************************************************* */
class FuncCallNode : public Node {
public:
  FuncCallNode(const std::string id, std::vector<Node *> & _args) : Node(), ident(id), args(_args) {}
  virtual ~FuncCallNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
  std::vector<Node *> args;  
};

/* ************************************************************************************************* */
class UnaryNode : public Node {
public:
  UnaryNode(Node* r) : Node(), right(r) {}
  virtual ~UnaryNode() {}
  virtual const Literal* eval() const = 0;
  Node* getRight() const {return right;}
  UnaryNode(const UnaryNode&) = delete;
  UnaryNode& operator=(const UnaryNode&) = delete;
protected:
  Node *right;
};

class PlusUnaryNode : public UnaryNode {
public:
  PlusUnaryNode(Node* right) : UnaryNode(right) {}
  virtual const Literal* eval() const;
};

class MinusUnaryNode : public UnaryNode {
public:
  MinusUnaryNode(Node* right) : UnaryNode(right) {}
  virtual const Literal* eval() const;
};

// --------------------------------------------- //
class PrintNode : public UnaryNode{
public:
  PrintNode(Node* right) : UnaryNode(right) {}
  PrintNode() : UnaryNode(nullptr) {}
  virtual const Literal* eval() const; 
};

// --------------------------------------------- //
class ReturnNode : public UnaryNode {
public:
  ReturnNode(Node* right) : UnaryNode(right) {}
  ReturnNode() : UnaryNode(new VoidNode()) {PoolOfNodes::getInstance().add(right);}
  virtual const Literal* eval() const;
};

/* *********************************************************************************************** */
class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual ~BinaryNode() {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class KeywordArg : public BinaryNode {
public:
  KeywordArg(Node * left, Node* right): BinaryNode(left, right){}
  virtual const Literal* eval() const;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right): BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class AddAsgBinaryNode : public BinaryNode {
public:
  AddAsgBinaryNode(Node* left, Node* right): BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class SubAsgBinaryNode : public BinaryNode {
public:
  SubAsgBinaryNode(Node* left, Node* right): BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class MulAsgBinaryNode : public BinaryNode {
public:
  MulAsgBinaryNode(Node* left, Node* right): BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivAsgBinaryNode : public BinaryNode {
public:
  DivAsgBinaryNode(Node* left, Node* right): BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class ModAsgBinaryNode : public BinaryNode {
public:
  ModAsgBinaryNode(Node* left, Node* right): BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class FloorDivAsgBinaryNode : public BinaryNode {
public:
  FloorDivAsgBinaryNode(Node* left, Node* right): BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

// --------------------------------------------- //
class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class FloorDivBinaryNode : public BinaryNode {
public:
  FloorDivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

// --------------------------------------------- //
class LessBinaryNode : public BinaryNode {
public:
  LessBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GreaterBinaryNode : public BinaryNode {
public:
  GreaterBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class EqualBinaryNode : public BinaryNode {
public:
  EqualBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GreaterEqBinaryNode : public BinaryNode {
public:
  GreaterEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class LessEqBinaryNode : public BinaryNode {
public:
  LessEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class NotEqBinaryNode : public BinaryNode {
public:
  NotEqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

/* ********************************************************************************************* */
class IfNode : public Node {
public:
  IfNode(Node* t, Node* is): Node(), test(t), ifstmts(is), elsestmts(nullptr) {}
  IfNode(Node* t, Node* is, Node* es) : Node(), test(t), ifstmts(is), elsestmts(es) {}
  virtual ~IfNode() {}
  virtual const Literal* eval() const;
  IfNode(const IfNode&) = delete;
  IfNode& operator=(const IfNode&) = delete;
private:
  Node *test;
  Node *ifstmts;
  Node *elsestmts;
};

/* ********************************************************************************************* */
class SuiteNode : public Node {
public:
  SuiteNode(Node * stmt): Node(), stmts(){ stmts.push_back(stmt);}
  virtual ~SuiteNode(){ }
  void addStmtAtEnd(Node * stmt) {stmts.push_back(stmt);}
  virtual const Literal* eval() const;
  SuiteNode(const SuiteNode&) = delete;
  SuiteNode& operator=(const SuiteNode&) = delete;
private:
  std::vector<Node *> stmts;
};

class FuncNode : public Node {
public:
  FuncNode(const std::string id, Node * suite, std::vector<Node *> & fp): Node(), ident(id), stmts(suite), default_args(fp), formal_args(){
   if(!checkargs()) throw std::string("non-default argument follows default argument");
  }
  virtual ~FuncNode(){}
  const Literal* funcEval(std::vector<const Node *> & args, std::map<std::string, const Node *> & keyargs) const;
  virtual const Literal* eval() const;
  virtual void print() const { std::cout << "function" << std::endl;}
  FuncNode(const FuncNode&) = delete;
  FuncNode& operator=(const FuncNode&) = delete;
private:
  std::string ident;
  Node * stmts;
  std::vector<Node *> default_args;
  std::vector<std::string> formal_args; 
  bool checkargs();
  void exeargs();
};

