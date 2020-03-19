// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <iostream>

#include <Eq2deg.hpp>

int main() {
    double a;
    double b;
    double c;
    
    // add code to retrieve the coeffcients from user input

  try { // Eq2deg can throw exceptions so we need to catch them
      
    // We use pointer because it allow funny tests
    Eq2deg* myEq = new Eq2deg(a, b, c);
    assert (myEq != nullptr); // Just make sure everything OK

    // Add code to solve the equation and display the result

    // Don't forget to free memory a "new" as been called

  } catch (const std::exception& ex) {
    std::cerr << "Exception raised: " << ex.what() << std::endl;
  }
  // Improve exception handling by separating different exception type
  return 0;
}
