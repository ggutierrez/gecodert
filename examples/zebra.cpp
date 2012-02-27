#include <gecodert/gecodert.hh>
#include <gecodert/int.hh>
#include <gecodert/int/distinct.hh>
#include <gecodert/int/linear.hh>
#include <gecodert/int/rel.hh>
#include <iostream>

using namespace GecodeRT;

class Zebra_Puzzle : public GecodeSpace {

public:
  Zebra_Puzzle(void); 
};

Zebra_Puzzle::Zebra_Puzzle(void) {

  // Nationality
  CtVar eng = newIntVar( 1, 5);
  CtVar spa = newIntVar( 1, 5);
  CtVar jap = newIntVar( 1, 5);
  CtVar ita = newIntVar( 1, 5);
  CtVar nor = newIntVar( 1, 5);
  
  // Pet
  CtVar dog = newIntVar( 1, 5);
  CtVar sna = newIntVar( 1, 5);
  CtVar fox = newIntVar( 1, 5);
  CtVar hor = newIntVar( 1, 5);
  CtVar zeb = newIntVar( 1, 5);
  
  // Profession
  CtVar pai = newIntVar( 1, 5);
  CtVar scu = newIntVar( 1, 5);
  CtVar dip = newIntVar( 1, 5);
  CtVar vio = newIntVar( 1, 5);
  CtVar doc = newIntVar( 1, 5);
  
  // Drink
  CtVar tea = newIntVar( 1, 5);
  CtVar cof = newIntVar( 1, 5);
  CtVar mil = newIntVar( 1, 5);
  CtVar jui = newIntVar( 1, 5);
  CtVar wat = newIntVar( 1, 5);
  
  // Color
  CtVar red = newIntVar( 1, 5);
  CtVar gre = newIntVar( 1, 5);
  CtVar whi = newIntVar( 1, 5);
  CtVar yel = newIntVar( 1, 5);
  CtVar blu = newIntVar( 1, 5);

  std::vector<CtVar> nationality { eng, spa, jap, ita, nor};
  std::vector<CtVar> pet { dog, sna, fox, hor, zeb};
  std::vector<CtVar> profession { pai, scu, dip, vio, doc};
  std::vector<CtVar> drink { tea, cof, mil, jui, wat};
  std::vector<CtVar> color { red, gre, whi, yel, blu};
  
  std::vector<int> coef { 1, -1};
  std::vector<CtVar> gre_cof { gre, cof};
  std::vector<CtVar> nor_blu { nor, blu};
  std::vector<CtVar> fox_doc { fox, doc};
  std::vector<CtVar> hor_dip { hor, dip};

  distinct( *this, nationality);
  distinct( *this, pet);
  distinct( *this, profession);
  distinct( *this, drink);
  distinct( *this, color);
  
  rel( *this, eng, IRT_EQ, red);
  rel( *this, spa, IRT_EQ, dog);
  rel( *this, jap, IRT_EQ, pai);
  rel( *this, ita, IRT_EQ, tea);
  rel( *this, nor, IRT_EQ, 1);
  rel( *this, gre, IRT_EQ, cof);
  
  //  rel( *this, gre, IRT_EQ, cof + 1);
  linear( *this, coef, gre_cof, IRT_EQ, 1);
  
  rel( *this, scu, IRT_EQ, sna);
  rel( *this, dip, IRT_EQ, yel);
  rel( *this, mil, IRT_EQ, 3);
  
  //rel( *this, |nor - blue|, IRT_EQ, 1);
  linear( *this, coef, nor_blu, IRT_EQ, 1);
  linear( *this, coef, nor_blu, IRT_EQ, -1);
  
  rel( *this, vio, IRT_EQ, jui);
  
  //   rel( *this, |fox-doc|, IRT_EQ, 1);
  //   linear( *this, coef, fox_doc, IRT_EQ, 1);
  linear( *this, coef, fox_doc, IRT_EQ, -1);
  
  //rel( *this, |hor-dip|, IRT_EQ, 1);
  linear( *this, coef, hor_dip, IRT_EQ, 1);
  linear( *this, coef, hor_dip, IRT_EQ, -1);
  
  
  branch(*this, nationality);
  branch(*this, pet);
  branch(*this, profession);
  branch(*this, drink);
  branch(*this, color);
   
}

int main(void) {
  Zebra_Puzzle z;
  search( z);
  return 0;
}
