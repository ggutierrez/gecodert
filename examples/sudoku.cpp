#include <gecodert/gecodert.hh>
#include <gecodert/int.hh>
#include <gecodert/int/distinct.hh>
#include <gecodert/int/linear.hh>
#include <gecodert/int/rel.hh>
#include <iostream>

using namespace GecodeRT;

class Sudoku : public GecodeSpace {

public:
  Sudoku(void);
};

Sudoku::Sudoku(void) {

  // Example
  std::vector< std::vector<int> > example;
  example.resize(9);

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      example[i].push_back(-1);
    }
  }

  example[0][1] = 1;
  example[0][2] = 2;
  example[0][3] = 3;
  example[0][7] = 5;

  example[1][2] = 7;
  example[1][3] = 6;
  example[1][5] = 2;
  example[1][7] = 1;
  example[1][8] = 3;

  example[2][0] = 5;
  example[2][4] = 4;
  example[2][7] = 2;

  example[3][2] = 8;
  example[3][3] = 7;
  example[3][6] = 9;

  example[4][0] = 3;
  example[4][2] = 9;
  example[4][3] = 1;
  example[4][6] = 2;
  example[4][8] = 6;

  example[5][2] = 5;
  example[5][4] = 3;
  example[5][5] = 4;
  example[5][6] = 8;

  example[6][1] = 2;
  example[6][4] = 1;
  example[6][8] = 7;

  example[7][0] = 7;
  example[7][1] = 9;
  example[7][3] = 5;
  example[7][5] = 3;
  example[7][6] = 1;

  example[8][1] = 5;
  example[8][5] = 8;
  example[8][6] = 3;
  example[8][7] = 9;


  
  std::vector<CtVar> squareList;
  std::vector< std::vector<CtVar> > squareRows, squareCols, squareBoxes;
  squareRows.resize(9);
  squareCols.resize(9);
  squareBoxes.resize(9);

  for(int i=0; i<9;i++){
    for(int j=0;j<9;j++){
      squareRows[i].push_back(newIntVar(1, 9));
      squareList.push_back(squareRows[i][j]);
    }
  }


  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
      squareCols[i].push_back(squareRows[j][i]);

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      for(int k=0; k<3; k++){
        for(int l=0; l<3; l++){
          squareBoxes[(3*i)+j].push_back(squareRows[(3*i)+k][(3*j)+l]);
        }
      }
    }
  }


  //   cols, rows and local squares must have distinct numbers
  for(int i=0; i<9; i++){
    distinct(*this, squareRows[i]);
    distinct(*this, squareCols[i]);
    distinct(*this, squareBoxes[i]);
  }

  //   Initial constraints, from the example
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      if(example[i][j] != -1){
        rel(*this, squareRows[i][j], IRT_EQ, example[i][j]);
        std::cout << example[i][j] << " ";
      }
      else{
        std::cout << "* ";
      }
    }
    std::cout << "" << std::endl;
  }

  branch(*this, squareList);
}

int main(void) {
  Sudoku s;
  search(s);
  return 0;
}
