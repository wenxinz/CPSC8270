#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "node.h"

bool SymbolTable::find(const std::string& name) const{
 if(table.count(name)) return true;
 else return false; 
} 

const Node* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = table.find(name);
  if ( it == table.end() ) return nullptr;
  return it->second;
}

void SymbolTable::setValue(const std::string& name, const Node* val) { 
  table[name] = val;
}

void SymbolTable::erase(const std::string& name) {
  table.erase(name);
}
