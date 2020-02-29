#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"


const Literal* IdentNode::eval() const { 
  const Literal* val = SymbolTable::getInstance().getValue(ident);
  return val;
}

/* ************************************************************************************************* */
const Literal* PlusUnaryNode::eval() const{
  if(!right) throw "error";
  const Literal* x = right->eval();
  return x;
}

const Literal* MinusUnaryNode::eval() const{
  if(!right) throw "error";
  const Literal* x = right->eval();
  return -(*x);
}

/* ************************************************************************************************ */
AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
//  const Literal* res = right->eval();
//  const std::string n = static_cast<IdentNode*>(left)->getIdent();
//  SymbolTable::getInstance().setValue(n, res);
}
const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
  return res;
}

AddAsgBinaryNode::AddAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
//  const Literal* l = left->eval();
//  const Literal* r = right->eval();
//  const std::string n = static_cast<IdentNode*>(left)->getIdent();
//  SymbolTable::getInstance().setValue(n, (*l+*r));
}  
const Literal* AddAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* l = left->eval();
  const Literal* r = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, (*l+*r));
  return left->eval();
}

SubAsgBinaryNode::SubAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right){  
//  const Literal* l = left->eval();
//  const Literal* r = right->eval();
//  const std::string n = static_cast<IdentNode*>(left)->getIdent();
//  SymbolTable::getInstance().setValue(n, (*l-*r));
}
const Literal* SubAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* l = left->eval();
  const Literal* r = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, (*l-*r));
  return left->eval();
}

MulAsgBinaryNode::MulAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right){
//  const Literal* l = left->eval();
//  const Literal* r = right->eval();
//  const std::string n = static_cast<IdentNode*>(left)->getIdent();
//  SymbolTable::getInstance().setValue(n, (*l)*(*r));
}
const Literal* MulAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* l = left->eval();
  const Literal* r = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, (*l)*(*r));
  return left->eval();
}

DivAsgBinaryNode::DivAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right){
//  const Literal* l = left->eval();
//  const Literal* r = right->eval();
//  const std::string n = static_cast<IdentNode*>(left)->getIdent();
//  SymbolTable::getInstance().setValue(n, (*l)/(*r));
}
const Literal* DivAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* l = left->eval();
  const Literal* r = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, (*l)/(*r));
  return left->eval();
}

ModAsgBinaryNode::ModAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right){
//  const Literal* l = left->eval();
//  const Literal* r = right->eval();
//  const std::string n = static_cast<IdentNode*>(left)->getIdent();
//  SymbolTable::getInstance().setValue(n, (*l)%(*r));
}
const Literal* ModAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* l = left->eval();
  const Literal* r = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, (*l)%(*r));
  return  left->eval();
}

FloorDivAsgBinaryNode::FloorDivAsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right){
//  const Literal* l = left->eval();
//  const Literal* r = right->eval();
//  const std::string n = static_cast<IdentNode*>(left)->getIdent();
//  SymbolTable::getInstance().setValue(n, l->floorDiv(*r));
}
const Literal* FloorDivAsgBinaryNode::eval() const{
  if (!left || !right) {
     throw "error";
  }
  const Literal* l = left->eval();
  const Literal* r = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, l->floorDiv(*r));
  return left->eval();
}

// ------------------------------------------------------ //
const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x+*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}

const Literal* ModBinaryNode::eval() const{
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* PowBinaryNode::eval() const{
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (x->power(*y));
}

const Literal* FloorDivBinaryNode::eval() const{
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (x->floorDiv(*y));
}
