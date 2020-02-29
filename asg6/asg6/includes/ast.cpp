#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "ast.h"
#include "tableManager.h"

const Literal* IdentNode::eval() const {
  switch(tag){
    case local :
      if(!TableManager::getInstance().find(ident)) throw std::string("variable undefined"); 
      return static_cast<const Literal *>(TableManager::getInstance().getNode(ident));
    case args : return nullptr;
    case global : 
      if(!TableManager::getInstance().findGlobal(ident)) throw std::string("global variable undefined");
      else return static_cast<const Literal *>(TableManager::getInstance().getNodeGlobal(ident)); 
  }
  throw std::string("error");
}

/* ************************************************************************************************* */

const Literal* FuncCallNode::eval() const {
  TableManager& tables = TableManager::getInstance();
  if(!tables.find(ident)) throw std::string("function undefined");
  else{
      std::vector<const Node *> realargs;
      std::map<std::string, const Node *> keywordargs;
      bool keyword = false;
      for(Node* n: args){
        const Literal* res = n->eval();
        if(res){
          if(!keyword){
            realargs.push_back(res);
          }else{
            throw std::string("non-keyword args after keyword args");
          }
        }else{
          if(!keyword) keyword = true;
          std::string temp = static_cast<IdentNode *>(static_cast<const KeywordArg *>(n)->getLeft())->getIdent();
          keywordargs[temp] = static_cast<const KeywordArg *>(n)->getRight()->eval();
        }
    }
    int curr = tables.getScope();
    int i = tables.findScope(ident);
    const FuncNode* f = static_cast<const FuncNode *>(tables.getNode(ident));
    if (i == curr){
      return f->funcEval(realargs,keywordargs);
    }
    else{
      tables.changeScope(i);
      const Literal* res = f->funcEval(realargs,keywordargs);
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
const Literal* KeywordArg::eval() const{
  if (!left || !right) {
    throw std::string("error");
  }
  return nullptr;
}

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
  if(!TableManager::getInstance().findCurr(n)) throw std::string("addasgn varaible undefined");
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
  if(!TableManager::getInstance().findCurr(n)) throw std::string("subasgn varaible undefined");
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
  if(!TableManager::getInstance().findCurr(n)) throw std::string("mulasgn varaible undefined");
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
  if(!TableManager::getInstance().findCurr(n)) throw std::string("divasgn varaible undefined");
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
  if(!TableManager::getInstance().findCurr(n)) throw std::string("modasgn varaible undefined");
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
  if(!TableManager::getInstance().findCurr(n)) throw std::string("floordivasgn varaible undefined");
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

const Literal* FuncNode::funcEval(std::vector<const Node *> & args, std::map<std::string, const Node *>  & keyargs) const { 
  TableManager & tm = TableManager::getInstance();
  tm.pushScope();
  // default arguments
  for(const Node * n :default_args) n->eval();
  // arguments
  int i = 0;
  for(const Node * n: args){
    tm.insert(formal_args[i],n->eval());
    i++;
  }
  for(auto & pair: keyargs){
    tm.insert(pair.first,pair.second);
  }

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

bool FuncNode::checkargs(){
  bool def = false;
  TableManager & tm = TableManager::getInstance();
  tm.pushScope();
  auto iterator = default_args.begin();
  while(iterator != default_args.end()){
   if(!(*iterator)->eval()){
     if(def) {tm.popScope(); return false;}
      formal_args.push_back(static_cast<IdentNode *>(*iterator)->getIdent());
      iterator = default_args.erase(iterator);
    }else{
      if(!def) def = true;
      formal_args.push_back(static_cast<IdentNode *>(static_cast<AsgBinaryNode *>(*iterator)->getLeft())->getIdent()); 
      ++iterator;
    }
  }
  tm.popScope();
  return true;
}


