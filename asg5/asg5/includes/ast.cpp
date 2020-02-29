#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "ast.h"
#include "tableManager.h"


const Literal* IdentNode::eval() const {
  if(tag == "global"){ 
    if(!TableManager::getInstance().findGlobal(ident)) throw std::string("global variable undefined");
    else return static_cast<const Literal *>(TableManager::getInstance().getNodeGlobal(ident)); 
  }
  if(!TableManager::getInstance().find(ident)) throw std::string("variable undefined"); 
  return static_cast<const Literal *>(TableManager::getInstance().getNode(ident));
}

/* ************************************************************************************************* */
const Literal* FuncCallNode::eval() const {
  TableManager& tables = TableManager::getInstance();
  if(!tables.find(ident)) throw std::string("function undefined");
  else{
    int curr = tables.getScope();
    int i = tables.findScope(ident);
    const FuncNode* f = static_cast<const FuncNode *>(tables.getNode(ident));
    if (i == curr){
      return f->funcEval();
    }
    else{
      tables.changeScope(i);
      const Literal* res = f->funcEval();
      tables.changeScope(curr);
      return res;
    }
  }
}

/* ************************************************************************************************* */
const Literal* PlusUnaryNode::eval() const{
  if(!right) throw std::string("can't apply + to null");
  const Literal* x = right->eval();
  return x;
}

const Literal* MinusUnaryNode::eval() const{
  if(!right) throw std::string("can't apply - to null");
  const Literal* x = right->eval();
  return -(*x);
}
// ------------------------------------------------------ //
const Literal* PrintNode::eval() const{
   if(!right){
     std::cout << std::endl;
     return nullptr;
   }
   const Literal* res = right->eval();
   if(res) res->print();
   return nullptr;
}
// ------------------------------------------------------ //
const Literal * ReturnNode::eval() const{
  if(!right) throw std::string("error");
  const Literal * res = right->eval();
  if(!res){
    res = new VoidNode();
    PoolOfNodes::getInstance().add(res);
  }
  TableManager::getInstance().insert(std::string("__RETURN__"), res);
  return nullptr;
}
/* ************************************************************************************************ */
const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  TableManager::getInstance().insert(n, res);
  return res;
}

const Literal* AddAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  if(!TableManager::getInstance().findCurr(n)) throw std::string("varaible undefined");
  const Literal* l = TableManager::getInstance().getNode(n)->eval();
  const Literal* r = right->eval();
  TableManager::getInstance().insert(n, (*l+*r));
  return left->eval();
}

const Literal* SubAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  if(!TableManager::getInstance().findCurr(n)) throw std::string("varaible undefined");
  const Literal* l = TableManager::getInstance().getNode(n)->eval();
  const Literal* r = right->eval();
  TableManager::getInstance().insert(n, (*l-*r));
  return left->eval();
}

const Literal* MulAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  if(!TableManager::getInstance().findCurr(n)) throw std::string("varaible undefined");
  const Literal* l = TableManager::getInstance().getNode(n)->eval();
  const Literal* r = right->eval();
  TableManager::getInstance().insert(n, (*l)*(*r));
  return left->eval();
}

const Literal* DivAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  if(!TableManager::getInstance().findCurr(n)) throw std::string("varaible undefined");
  const Literal* l = TableManager::getInstance().getNode(n)->eval();
  const Literal* r = right->eval();
  TableManager::getInstance().insert(n, (*l)/(*r));
  return left->eval();
}

const Literal* ModAsgBinaryNode::eval() const {
  if (!left || !right) {
    throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  if(!TableManager::getInstance().findCurr(n)) throw std::string("varaible undefined");
  const Literal* l = TableManager::getInstance().getNode(n)->eval();
  const Literal* r = right->eval();
  TableManager::getInstance().insert(n, (*l)%(*r));
  return left->eval();
}

const Literal* FloorDivAsgBinaryNode::eval() const{
  if (!left || !right) {
     throw std::string("error");
  }
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  if(!TableManager::getInstance().findCurr(n)) throw std::string("varaible undefined");
  const Literal* l = TableManager::getInstance().getNode(n)->eval();
  const Literal* r = right->eval();
  TableManager::getInstance().insert(n, l->floorDiv(*r));
  return left->eval();
}

// ------------------------------------------------------ //
const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x+*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}

const Literal* ModBinaryNode::eval() const{
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* PowBinaryNode::eval() const{
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (x->power(*y));
}

const Literal* FloorDivBinaryNode::eval() const{
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (x->floorDiv(*y));
}

// ------------------------------------------------------ //
const Literal* LessBinaryNode::eval() const{
  if (!left || !right) {throw std::string("error");}
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)<(*y);
}

const Literal* GreaterBinaryNode::eval() const{
  if (!left || !right) {throw std::string("error");}
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)>(*y);
}

const Literal* EqualBinaryNode::eval() const{
  if (!left || !right) {throw std::string("error");}
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)==(*y);
}

const Literal* GreaterEqBinaryNode::eval() const{
  if (!left || !right) {throw std::string("error");}
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)>=(*y);
}

const Literal* LessEqBinaryNode::eval() const{
  if (!left || !right) {throw std::string("error");}
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)<=(*y);
}

const Literal* NotEqBinaryNode::eval() const{
  if (!left || !right) {throw std::string("error");}
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x)!=(*y);
}

/* ************************************************************************************************ */
const Literal * IfNode::eval() const{
  if(static_cast<const BoolLiteral *>(test->eval())->boolEval()) return ifstmts->eval();
  if(elsestmts) return elsestmts->eval();
  return nullptr; 
}

/* ************************************************************************************************ */
const Literal * SuiteNode::eval() const{
  TableManager & tm = TableManager::getInstance();
  for(const Node* n: stmts){
    if(n){
       n->eval();
       if(tm.find(std::string("__RETURN__")) && tm.getNode(std::string("__RETURN__")))
         break;
    }
  }
  return nullptr;
}

const Literal* FuncNode::eval() const{
  TableManager::getInstance().insert(ident, this);
  return nullptr;
}

const Literal* FuncNode::funcEval() const { 
  TableManager & tm = TableManager::getInstance();
  tm.pushScope();
  tm.insert(std::string("__RETURN__"), nullptr);
  stmts->eval();
  if(!tm.getNode(std::string("__RETURN__"))){
    tm.popScope();
    const Literal * none = new VoidNode();
    PoolOfNodes::getInstance().add(none);
    return none;
  }
  const Literal* res = tm.getNode(std::string("__RETURN__"))->eval(); 
  tm.popScope();
  return res;
}
