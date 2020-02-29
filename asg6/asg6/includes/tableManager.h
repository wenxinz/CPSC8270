#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "symbolTable.h"

class TableManager {
public:
  static TableManager& getInstance();
  void insert(const std::string & name, const Node* node);
  void erase(const std::string & name);
  const Node* getNode(const std::string & name) const;
  const Node* getNodeCurr(const std::string & name) const;
  const Node* getNodeGlobal(const std::string & name) const;
  bool find(const std::string & name) const;
  bool findCurr(const std::string & name) const;
  bool findGlobal(const std::string & name) const;
  int findScope(const std::string & name) const;
  int getScope();
  void changeScope(int scope);
  void pushScope();
  void popScope();
private:
  int currentScope;
  std::vector<SymbolTable> tables;
  TableManager() : currentScope(0), tables() { tables.push_back(SymbolTable());}
};

#endif
