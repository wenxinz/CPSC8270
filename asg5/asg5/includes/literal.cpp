#include "literal.h"

const Literal*  FloatLiteral::operator<(const Literal& rhs) const {
   return rhs.opG(val);
 }
const Literal* FloatLiteral::opL(float lhs) const {
   const Literal* node = new BoolLiteral(val < lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
 }
const Literal* FloatLiteral::opL(int lhs) const {
   const Literal* node = new BoolLiteral(val < lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}

const Literal* FloatLiteral::operator<=(const Literal& rhs) const {
   return rhs.opGE(val);
}
const Literal* FloatLiteral::opLE(float lhs) const {
   const Literal* node = new BoolLiteral(val <= lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}
const Literal* FloatLiteral::opLE(int lhs) const {
   const Literal* node = new BoolLiteral(val <= lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}

const Literal* FloatLiteral::operator>(const Literal& rhs) const {
   return rhs.opL(val);
}
const Literal* FloatLiteral::opG(float lhs) const {
   const Literal* node = new BoolLiteral(val > lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}
const Literal* FloatLiteral::opG(int lhs) const {
   const Literal* node = new BoolLiteral(val > lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}

const Literal* FloatLiteral::operator>=(const Literal& rhs) const {
   return rhs.opLE(val);
}
const Literal* FloatLiteral::opGE(float lhs) const {
  const Literal* node = new BoolLiteral(val >= lhs);
  PoolOfNodes::getInstance().add(node);
  return node;
}
const Literal* FloatLiteral::opGE(int lhs) const {
  const Literal* node = new BoolLiteral(val >= lhs);
  PoolOfNodes::getInstance().add(node);
  return node;
}

const Literal* FloatLiteral::operator==(const Literal& rhs) const {
   return rhs.opE(val);
}
const Literal* FloatLiteral::opE(float lhs) const {
   const Literal* node = new BoolLiteral(val == lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}
const Literal* FloatLiteral::opE(int lhs) const {
   const Literal* node = new BoolLiteral(val == lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}

const Literal* FloatLiteral::operator!=(const Literal& rhs) const {
   return rhs.opNE(val);
}
const Literal* FloatLiteral::opNE(float lhs) const {
   const Literal* node = new BoolLiteral(val != lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}
const Literal* FloatLiteral::opNE(int lhs) const {
   const Literal* node = new BoolLiteral(val != lhs);
   PoolOfNodes::getInstance().add(node);
   return node;
}

 const Literal*  IntLiteral::operator<(const Literal& rhs) const {
    return rhs.opG(val);
  }
  const Literal* IntLiteral::opL(float lhs) const {
    const Literal* node = new BoolLiteral(val < lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal* IntLiteral::opL(int lhs) const {
    const Literal* node = new BoolLiteral(val < lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 const Literal* IntLiteral::operator<=(const Literal& rhs) const {
    return rhs.opGE(val);
  }
 const Literal* IntLiteral::opLE(float lhs) const {
    const Literal* node = new BoolLiteral(val <= lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal* IntLiteral::opLE(int lhs) const {
    const Literal* node = new BoolLiteral(val <= lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 const Literal* IntLiteral::operator>(const Literal& rhs) const {
    return rhs.opL(val);
  }
 const Literal* IntLiteral::opG(float lhs) const {
    const Literal* node = new BoolLiteral(val > lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal* IntLiteral::opG(int lhs) const {
    const Literal* node = new BoolLiteral(val > lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 const Literal* IntLiteral::operator>=(const Literal& rhs) const {
    return rhs.opLE(val);
  }
 const Literal* IntLiteral::opGE(float lhs) const {
    const Literal* node = new BoolLiteral(val >= lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal* IntLiteral::opGE(int lhs) const {
    const Literal* node = new BoolLiteral(val >= lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 const Literal* IntLiteral::operator==(const Literal& rhs) const {
    return rhs.opE(val);
  }
 const Literal* IntLiteral::opE(float lhs) const {
    const Literal* node = new BoolLiteral(val == lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal* IntLiteral::opE(int lhs) const {
    const Literal* node = new BoolLiteral(val == lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 const Literal* IntLiteral::operator!=(const Literal& rhs) const {
    return rhs.opNE(val);
  }
 const Literal* IntLiteral::opNE(float lhs) const {
    const Literal* node = new BoolLiteral(val != lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 const Literal* IntLiteral::opNE(int lhs) const {
    const Literal* node = new BoolLiteral(val != lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
