#include "node.h"
#include "poolOfNodes.h"
#include <cmath>

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
//  virtual const Literal* opMod(float) const =0;
//  virtual const Literal* opMod(int) const =0;

  virtual const Literal* power(const Literal& rhs) const =0;
  virtual const Literal* opPow(float) const =0;
  virtual const Literal* opPow(int) const =0; 

  virtual const Literal* floorDiv(const Literal& rhs) const =0;
  virtual const Literal* opFDiv(float) const =0;
  virtual const Literal* opFDiv(int) const =0;

  virtual const Literal* eval() const = 0;
  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}

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
    //return rhs.opMod(val);
  }
//  virtual const Literal* opMod(float lhs) const {
//    if ( val == 0 ) throw std::string("Zero Division Error");
//    const Literal* node = new FloatLiteral(static_cast<float>(lhs - lhs / val * val));
//    PoolOfNodes::getInstance().add(node);
//    return node; 
//  }
//  virtual const Literal* opMod(int lhs) const {
//    if ( val == 0 ) throw std::string("Zero Division Error");
//    const Literal* node = new FloatLiteral(static_cast<float>(lhs - lhs / val * val));
//    PoolOfNodes::getInstance().add(node);
//    return node;
//  }

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
    //return rhs.opMod(val);
  } 
 //virtual const Literal* opMod(float lhs) const {
 //   if ( val == 0 ) throw std::string("Zero Division Error");
 //   const Literal* node = new FloatLiteral(static_cast<float>(val - lhs / val * val));
 //   PoolOfNodes::getInstance().add(node);
 //   return node; 
 // }
 // virtual const Literal* opMod(int lhs) const {
 //   if ( val == 0 ) throw std::string("Zero Division Error");
 //   const Literal* node = new IntLiteral(val - lhs / val *val);
 //   PoolOfNodes::getInstance().add(node);
 //   return node;
 // }

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

  /* ********************************************************************************** */
  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << "INT: " << val << std::endl; 
  }

private:
  int val;
};

