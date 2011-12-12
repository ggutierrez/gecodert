#include <exceptions.hh>

const char* CopiaEx::what() const throw() {    
  switch(motivo) {                                    
  case 1:                                                
    return "Error1";                                           
  case 2:                                            
    return "Error2";                             
  }                        
  return "Error inesperado";                                       
} // (1)     
