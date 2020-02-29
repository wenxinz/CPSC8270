#include <iostream>
#include <string>
#include <vector>
#include "tableManager.h"

TableManager& TableManager::getInstance() {
  static TableManager instance;
  return instance;
}

void TableManager::insert(const std::string & name, const Node* node){
  tables[currentScope].setValue(name, node);
}

void TableManager::erase(const std::string & name){
  tables[currentScope].erase(name);
}

bool TableManager::find(const std::string & name) const{
  int i = currentScope;
  while(i >= 0){
    if(tables[i].find(name)) return true;
    i--;
  }
  return false;
}

bool TableManager::findGlobal(const std::string & name) const{
  return tables[0].find(name);
}

bool TableManager::findCurr(const std::string & name) const{
  return tables[currentScope].find(name);
}

const Node* TableManager::getNode(const std::string & name) const{
/*  if(find(name)){
   int i; 
   try{
      i = findScope(name);
    }
    catch (const std::string& msg){
      throw msg;
    }
    return tables[i].getValue(name);
  }else
    return nullptr;
*/
  int i = currentScope;
  while(i >= 0){
    if(tables[i].find(name)) {
      return tables[i].getValue(name);
    }
    i--;
  }
  return nullptr;
}

int TableManager::findScope(const std::string & name) const{
  int i = currentScope;
  while(i >=0){
     if(tables[i].find(name)) return i;
     i--;
  }
  throw std::string("not defined in all scope");
}

int TableManager::getScope(){
  return currentScope;
}


void TableManager::changeScope(int scope){
   currentScope = scope;
}

const Node* TableManager::getNodeGlobal(const std::string & name) const{
  return tables[0].getValue(name);
}

const Node* TableManager::getNodeCurr(const std::string & name) const{
  return tables[currentScope].getValue(name);
}

void TableManager::pushScope(){
//  tables.push_back(SymbolTable());
  currentScope++;
  auto it = tables.begin()+currentScope;
  tables.insert(it, SymbolTable());
}

void TableManager::popScope(){
  if(!currentScope) throw std::string("error");
//  tables.pop_back();
  auto it = tables.begin()+currentScope;
  tables.erase(it); 
  currentScope--;
}
