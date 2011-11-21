#ifndef __GECODERT_GECODERT_HH__
#define __GECODERT_GECODERT_HH__

#include <iostream>
#include <tuple>
#include <vector>
#include <gecode/kernel.hh>
#include <gecode/int.hh>
#include <gecode/set.hh>

using namespace std;

/**
 * \namespace GecodeRT \brief Abstraction to provide a Gecode
 * interface that is friendly for interpreted languages.
 *
 * The GecodeRT namespace contains all the functionality required to
 * make Gecode available as an interface for other languages.
 */
namespace GecodeRT {
  
  // Forward declaration
  class GecodeSpace;
  /**
   * \brief Gecode constraint variable abstraction.
   *
   * This represents a constraint variable inside a Gecode space. The
   * idea of this class is to contain both the type of the variable
   * and a way to identify it inside the space. It also provides some
   * methods to perform tests on the type.
   */
  class CtVar {
    /* 
       This friendship relation allows only the space to create
       objects from this class.
    */
    friend class GecodeSpace;
  private:
    /**
     * \brief Type information.
     *
     * This attribute identifies the variable type according with:
     * - 'i' : IntVar
     * - 's' : SetVar
     * - 'b' : BoolVar
     */
    unsigned char type_;
    /// Stores the location of the variable in the space.
    unsigned int index_;
  private:
    /// Default constructor
    CtVar(void)
      : type_('x'), index_(0) {}
    /// Constructor for a variable of type \a type at index \a index
    CtVar(unsigned char type, unsigned int index)
      : type_(type), index_(index) {}
  public:
    /// Copy constructor
    CtVar(const CtVar& v)
      : type_(v.type_), index_(v.index_) {}
    /// Tests if the variable is an IntVar
    bool isIntVar(const CtVar& v) const {
      return v.type_ == 'i';
    }
    /// Prints the type information to \a os
    void print(std::ostream& os) const {
      os << type_ << " " << index_;
    }
  };
  /// Prints the type information for \a cv
  inline
  std::ostream& operator << (std::ostream& os, const CtVar& cv) {
    cv.print(os);
    return os;
  }

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
    CtVar newIntVar(int min, int max);
    /// Returns the constraint variable represented by \a var
    const Gecode::IntVar& intVar(const CtVar& var) const;
    const Gecode::SetVar& setVar(const CtVar& var) const;
    /// Copy function
    virtual Gecode::Space* copy(bool share);
    /// Dump space variables to \a os
    std::ostream& dump(std::ostream& os) const;
  };

  /**
   * \brief Branch on the variables in \a vars
   *
   */
  void branch(GecodeSpace& home, const std::vector<CtVar>& vars);  
  /**
   * \brief Search
   *
   */
  void search(GecodeSpace& root);
  
  
}

#endif
