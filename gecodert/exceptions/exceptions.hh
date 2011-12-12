#include <iostream>

using namespace std;

class CopiaEx: public exception {
public:                                                                   
  CopiaEx(int mot) : exception(), motivo(mot) {}                        
  const char* what() const throw();                                       
private:                                                      
  int motivo;          
}; 

