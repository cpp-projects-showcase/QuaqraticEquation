#ifndef __UTILITIES_HPP
#define __UTILITIES_HPP

/**
 * CS-17, Utilities.hpp
 * This class provides the base mechanism to display an object
 * 
 * The derived class should provide a "describe" method returning a string
 * The << operator is also provided here but not as a member of Utilities
 * 
 * 
 * @author Christophe Gattardi
 * @version 1.0 15/03/2020
 */


// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <iosfwd>
#include <sstream>
#include <string>

class Utilities{
    public:
    /**
     * Dump an Object into an output stream.
     *
     * @param ostream& the output stream.
     */
    void toStream (std::ostream& ioOut) const {
      ioOut << describe();
    }
    private:
    /**
     * Return a string representing the object
     *
     * @return std::string Dump of the object.
     */
    virtual std::string describe() const = 0;
};

/**
 * Piece of code given by Nicolai M. Josuttis, Section 13.12.1 "Implementing
 * Output Operators" (p653) of his book "The C++ Standard Library: A Tutorial
 * and Reference", published by Addison-Wesley.
 */
template <class charT, class traits>
inline
std::basic_ostream<charT, traits>&
operator<< (std::basic_ostream<charT, traits>& ioOut,
            const Utilities& iUtils) {
  /**
     string stream:
     - with same format
     - without special field width
  */
  std::basic_ostringstream<charT,traits> ostr;
  ostr.copyfmt (ioOut);
  ostr.width (0);

  // Fill string stream
  iUtils.toStream (ostr);

  // Print string stream
  ioOut << ostr.str();

  return ioOut;
}

#endif //__UTILITIES_HPP
