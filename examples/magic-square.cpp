#include <gecodert/gecodert.hh>
#include <gecodert/int.hh>
#include <gecodert/int/distinct.hh>
#include <gecodert/int/linear.hh>
#include <gecodert/int/rel.hh>
#include <iostream>

   using namespace GecodeRT;

   class MagicSquare : public GecodeSpace {
   //Square size
      const int n;
   public:
      MagicSquare(int); 
   };

   MagicSquare::MagicSquare(int i): n(i) {
   
   // Number of fields on square
      const int nn = n*n; 
   // Sum of all a row, column, or diagonal
      const int s  = nn*(nn+1) / (2*n);
   
      std::vector<CtVar> squareList;
      std::vector< std::vector<CtVar> > matriz, matrizCols;
      std::vector<CtVar> d1y, d2y;
      matriz.resize(n);
      matrizCols.resize(n);
      
      for(int i=0; i<n;i++){
         for(int j=0;j<n;j++){
            matriz[i].push_back(newIntVar(1, nn));
            squareList.push_back(matriz[i][j]);
            if(i==j) d1y.push_back(matriz[i][j]);
         }
      }
      
      for(int i=0; i<n; i++)
         for(int j=0; j<n; j++)
            matrizCols[i].push_back(matriz[j][i]);
         
      for(int i=n-1, j=0; i>=0; i--,j++){
         d2y.push_back(matriz[i][j]);
      }
   
      // cols and rows must have sum s
      for(int i=0; i<n; i++){
         linear(*this, matriz[i], IRT_EQ, s);
         linear(*this, matrizCols[i],IRT_EQ, s);
      }
      
      // Both diagonals must have sum s
      linear(*this, d1y, IRT_EQ, s);
      linear(*this, d2y, IRT_EQ, s);
   
      // All fields must be distinct
      distinct(*this, squareList);
      
      // Break some (few) symmetries
      rel(*this,   matriz[0][0], IRT_LE, matriz[n-1][n-1]);
      rel(*this, matriz[n-1][0], IRT_LE, matriz[0][n-1]);
      rel(*this,   matriz[0][0], IRT_LE, matriz[n-1][0]);
   
      branch(*this, squareList);
   }

   int main(int argc, char* argv[]) {
      int n=3;
      if(argc == 1)
         n=3;
      else if (argc == 2)
         n=atoi(argv[1]);
      else
         exit(0);
      
      MagicSquare q(n);   
      search(q);
      return 0;
   }
