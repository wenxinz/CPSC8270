#include "node.h"
#include "poolOfNodes.h"
#include <cmath>
#include <iostream>
#include <string>

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+() const = 0;
  virtual const Literal* operator-() const = 0;
  
  virtual const Literal* operator+(const Literal& rhs) const =0;
  virtual const Literal* opPlus(float) const =0;
  virtual const Literal* opPlus(int) const =0;

  virtual const Literal* operator*(const Literal& rhs) const =0;
  virtual const Literal* opMult(float) const =0;
  virtual const Literal* opMult(int) const =0;

  virtual const Literal* operator-(const Literal& rhs) const =0;
  virtual const Literal* opSubt(float) const =0;
  virtual const Literal* opSubt(int) const =0;

  virtual const Literal* operator/(const Literal& rhs) const =0;
  virtual const Literal* opDiv(float) const =0;
  virtual const Literal* opDiv(int) const =0;

  virtual const Literal* operator%(const Literal& rhs) const =0;

  virtual const Literal* power(const Literal& rhs) const =0;
  virtual const Literal* opPow(float) const =0;
  virtual const Literal* opPow(int) const =0; 

  virtual const Literal* floorDiv(const Literal& rhs) const =0;
  virtual const Literal* opFDiv(float) const =0;
  virtual const Literal* opFDiv(int) const =0;

  virtual const Literal* operator<(const Literal& rhs) const =0;
  virtual const Literal* opL(float) const =0;
  virtual const Literal* opL(int) const =0;

  virtual const Literal* operator<=(const Literal& rhs) const =0;
  virtual const Literal* opLE(float) const =0;
  virtual const Literal* opLE(int) const =0;

  virtual const Literal* operator>(const Literal& rhs) const =0;
  virtual const Literal* opG(float) const =0;
  virtual const Literal* opG(int) const =0;

  virtual const Literal* operator>=(const Literal& rhs) const =0;
  virtual const Literal* opGE(float) const =0;
  virtual const Literal* opGE(int) const =0;

  virtual const Literal* operator==(const Literal& rhs) const =0;
  virtual const Literal* opE(float) const =0;
  virtual const Literal* opE(int) const =0;

  virtual const Literal* operator!=(const Literal& rhs) const =0;
  virtual const Literal* opNE(float) const =0;
  virtual const Literal* opNE(int) const =0;

  virtual const Literal* eval() const = 0;
  virtual void print() const { std::cout << "Literal" << std::endl;}
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}

  /* ********************************************************************** */
  virtual const Literal* operator+() const {
    return this;
  }

  virtual const Literal* operator-() const {
    const Literal* node = new FloatLiteral(-val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  /* ********************************************************************** */
  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return this->operator-(*((this->operator/(rhs))->operator*(rhs)));
  }

  virtual const Literal* power(const Literal& rhs) const {
    return rhs.opPow(val);
  }
  virtual const Literal* opPow(float lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(int lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node; 
  } 
  
  virtual const Literal* floorDiv(const Literal& rhs) const {
    return rhs.opFDiv(val);
  }
  virtual const Literal* opFDiv(float lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(floor(lhs/val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opFDiv(int lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(floor(lhs/val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* operator<(const Literal& rhs) const;
  virtual const Literal* opL(float) const;
  virtual const Literal* opL(int) const;
  virtual const Literal* operator<=(const Literal& rhs) const;
  virtual const Literal* opLE(float) const;
  virtual const Literal* opLE(int) const;
  virtual const Literal* operator>(const Literal& rhs) const;
  virtual const Literal* opG(float) const;
  virtual const Literal* opG(int) const;
  virtual const Literal* operator>=(const Literal& rhs) const;
  virtual const Literal* opGE(float) const;
  virtual const Literal* opGE(int) const;
  virtual const Literal* operator==(const Literal& rhs) const;
  virtual const Literal* opE(float) const;
  virtual const Literal* opE(int) const;
  virtual const Literal* operator!=(const Literal& rhs) const;
  virtual const Literal* opNE(float) const;
  virtual const Literal* opNE(int) const;
  /* ************************************************************************* */
  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << "FLOAT: " << val << std::endl; 
  }

private:
  float val;
};

class IntLiteral: public Literal {
public:
  IntLiteral(int _val): val(_val) {}

  /* ********************************************************************** */
  virtual const Literal* operator+() const {
    return this;
  }

  virtual const Literal* operator-() const {
    const Literal* node = new IntLiteral(-val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  /* ******************************************************************************* */
  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral(static_cast<int>(std::floor(1.0*lhs / val)));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return this->operator-(*((this->operator/(rhs))->operator*(rhs)));
  } 

  virtual const Literal* power(const Literal& rhs) const {
    return rhs.opPow(val);
  }
  virtual const Literal* opPow(float lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(int lhs) const {
    const Literal* node = new IntLiteral(static_cast<int>(pow(lhs,val)));
    PoolOfNodes::getInstance().add(node);
    return node;
  } 
  
  virtual const Literal* floorDiv(const Literal& rhs) const {
    return rhs.opFDiv(val);
  }
  virtual const Literal* opFDiv(float lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(floor(lhs/val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opFDiv(int lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral(static_cast<int>(std::floor(1.0*lhs/val)));
    PoolOfNodes::getInstance().add(node);
    return node;    
  } 
  
  virtual const Literal* operator<(const Literal& rhs) const;
  virtual const Literal* opL(float) const;
  virtual const Literal* opL(int) const;
  virtual const Literal* operator<=(const Literal& rhs) const;
  virtual const Literal* opLE(float) const;
  virtual const Literal* opLE(int) const;
  virtual const Literal* operator>(const Literal& rhs) const;
  virtual const Literal* opG(float) const;
  virtual const Literal* opG(int) const;
  virtual const Literal* operator>=(const Literal& rhs) const;
  virtual const Literal* opGE(float) const;
  virtual const Literal* opGE(int) const;
  virtual const Literal* operator==(const Literal& rhs) const;
  virtual const Literal* opE(float) const;
  virtual const Literal* opE(int) const;
  virtual const Literal* operator!=(const Literal& rhs) const;
  virtual const Literal* opNE(float) const;
  virtual const Literal* opNE(int) const;  
  /* ********************************************************************************** */
  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << "INT: " << val << std::endl; 
  }

protected:
  int val;
};

class BoolLiteral: public IntLiteral {
public:
  BoolLiteral(int n): IntLiteral(n? 1:0) {}
  BoolLiteral(bool n): IntLiteral(n? 1:0) {}
  bool boolEval() const { if(val) return true; else return false;}
  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    if(val) std::cout << "True" << std::endl; 
    else std::cout << "False" << std::endl;
  }
  const BoolLiteral* operator!() {val = (val?0:1); return this;}
};

class VoidNode : public Literal {
public :
  virtual ~VoidNode(){}

  virtual const Literal* operator+() const { throw std::string("None: error");} 
  virtual const Literal* operator-() const { throw std::string("None: error");}

  virtual const Literal* operator+(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opPlus(float) const { throw std::string("None: error");}
  virtual const Literal* opPlus(int) const { throw std::string("None: error");}

  virtual const Literal* operator*(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opMult(float) const { throw std::string("None: error");}
  virtual const Literal* opMult(int) const { throw std::string("None: error");}

  virtual const Literal* operator-(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opSubt(float) const { throw std::string("None: error");}
  virtual const Literal* opSubt(int) const { throw std::string("None: error");}

  virtual const Literal* operator/(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opDiv(float) const { throw std::string("None: error");}
  virtual const Literal* opDiv(int) const { throw std::string("None: error");}

  virtual const Literal* operator%(const Literal&) const { throw std::string("None: error");}

  virtual const Literal* power(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opPow(float) const { throw std::string("None: error");}
  virtual const Literal* opPow(int) const { throw std::string("None: error");}

  virtual const Literal* floorDiv(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opFDiv(float) const { throw std::string("None: error");}
  virtual const Literal* opFDiv(int) const { throw std::string("None: error");}

  virtual const Literal* operator<(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opL(float) const { throw std::string("None: error");}
  virtual const Literal* opL(int) const { throw std::string("None: error");}

  virtual const Literal* operator<=(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opLE(float) const { throw std::string("None: error");}
  virtual const Literal* opLE(int) const { throw std::string("None: error");}

  virtual const Literal* operator>(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opG(float) const { throw std::string("None: error");}
  virtual const Literal* opG(int) const { throw std::string("None: error");}

  virtual const Literal* operator>=(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opGE(float) const { throw std::string("None: error");}
  virtual const Literal* opGE(int) const { throw std::string("None: error");}

  virtual const Literal* operator==(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opE(float) const { throw std::string("None: error");}
  virtual const Literal* opE(int) const { throw std::string("None: error");}

  virtual const Literal* operator!=(const Literal&) const { throw std::string("None: error");}
  virtual const Literal* opNE(float) const { throw std::string("None: error");}
  virtual const Literal* opNE(int) const { throw std::string("None: error");} 

  virtual const Literal* eval() const {return this;}
  virtual void print() const { std::cout << "None" << std::endl;}
};
