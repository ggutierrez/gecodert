#ifndef __GECODERT_GECODERT_HH__
#define __GECODERT_GECODERT_HH__

#include <iostream>
#include <tuple>
#include <gecode/kernel.hh>
#include <gecode/int.hh>
#include <vector>

using namespace std;

typedef tuple <unsigned char, unsigned int> tupla;

/**
 * \namespace GecodeRT \brief Abstraction to provide a Gecode
 * interface that is friendly for interpreted languages.
 *
 * The GecodeRT namespace contains all the functionality required to
 * make gecode available as an interface for other languages.
 */
namespace GecodeRT {
  
  /**
   * \brief Class that abstracts copy and clonning from users
   * responsability.
   *
   * In order to interface Gecode from interpreted and high level
   * languages we need to abstract the fact that decision variables
   * need to be copied during search. This class offer mechanisms for
   * variable declaration. Copy of all declared variables is
   * automatically handled.
   */
  class GecodeSpace : public Gecode::Space {
  private:
    typedef std::vector<Gecode::IntVar> IvContainer;
    typedef IvContainer::iterator IvContainerIT;
    /// Storage for the int variables
    IvContainer iv;
    /// Copy constructor
    GecodeSpace(bool share, GecodeSpace&);
  public:
    /// Constructor for an empty space
    GecodeSpace(void);
    /// Destructor
    virtual ~GecodeSpace(void);
    /// Create a new integer variable
    tupla newIntVar(int min, int max);
    /// Copy function
    virtual Gecode::Space* copy(bool share);
  };
}

#endif
