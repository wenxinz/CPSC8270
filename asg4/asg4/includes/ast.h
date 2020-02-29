#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include "literal.h"
#include <iostream>
#include <string>
#include <map>

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) {} 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

/* ************************************************************************************************* */
class UnaryNode : public Node {
public:
  UnaryNode(Node* r) : Node(), right(r) {}
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

/* *********************************************************************************************** */
class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class AddAsgBinaryNode : public BinaryNode {
public:
  AddAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class SubAsgBinaryNode : public BinaryNode {
public:
  SubAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class MulAsgBinaryNode : public BinaryNode {
public:
  MulAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class DivAsgBinaryNode : public BinaryNode {
public:
  DivAsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class ModAsgBinaryNode : public BinaryNode {
public:
  ModAsgBinaryNode(Node* left, Node* right); 
  virtual const Literal* eval() const;
};

class FloorDivAsgBinaryNode : public BinaryNode {
public:
  FloorDivAsgBinaryNode(Node* left, Node* right);
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
