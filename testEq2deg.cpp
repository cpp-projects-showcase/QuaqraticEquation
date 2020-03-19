// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <iostream>
#include <memory>
#include <cassert>
#include <math.h>

// Boost
#include <boost/filesystem.hpp>
// Boost Unit Test Framework (UTF)
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE TestEq2deg
#include <boost/test/unit_test.hpp>
// Characters
#include <Eq2degComp.hpp>

namespace boost_utf = boost::unit_test;

// (Boost) Unit Test XML Report
std::ofstream utfReportStream ("TestEq2deg_utfresults.xml");

/**
 * Configuration for the Boost Unit Test Framework (UTF)
 */
struct UnitTestConfig {
  /** Constructor. */
  UnitTestConfig() {
    boost_utf::unit_test_log.set_stream (utfReportStream);
    boost_utf::unit_test_log.set_format (boost_utf::OF_XML);
    boost_utf::unit_test_log.set_threshold_level (boost_utf::log_test_units);
  }

  /** Destructor. */
  ~UnitTestConfig() {
  }
};

// /////////////// Main: Unit Test Suite //////////////

// Set the UTF configuration (re-direct the output to a specific file)
BOOST_GLOBAL_FIXTURE (UnitTestConfig);

// Start the test suite
BOOST_AUTO_TEST_SUITE (master_test_suite)

/**
 * Test the resolution of x^2-x-1 in real (Eq2deg class)
 */
BOOST_AUTO_TEST_CASE (eq2deg1) {
  BOOST_TEST_MESSAGE("Testing x^2-x-1");
  Eq2deg* eq1 = new Eq2deg (1, -1, -1);
  assert (eq1 != nullptr);
  eq1->computeDelta();
  double delta = eq1->getDelta();
  eq1->computeRoots();
  std::cout << "Discriminant: " << delta << std::endl;
  BOOST_CHECK_MESSAGE (delta == 5,
                       "The discriminant should be 5");

  BOOST_CHECK_MESSAGE (eq1->getRoot(1) == (1-sqrt(5))/2,
                       "The first root should be -0.618034");

  BOOST_CHECK_MESSAGE (eq1->getRoot(2) == (1+sqrt(5))/2,
                       "The second root should be 1.61803");

  // Cleaning
  delete eq1; eq1 = nullptr;
}

/**
 * Test the resolution of x^2-2x+1 in real (Eq2deg class)
 */
BOOST_AUTO_TEST_CASE (eq2deg2) {
  BOOST_TEST_MESSAGE("Testing x^2-2x+1");
  Eq2deg eq1(1, -2, 1);
  eq1.computeDelta();
  double delta = eq1.getDelta();
  eq1.computeRoots();
  std::cout << "Discriminant: " << delta << std::endl;
  BOOST_CHECK_MESSAGE (delta == 0,
                       "The discriminant should be 0");

  BOOST_CHECK_MESSAGE (eq1.getRoot(1) == 1,
                       "The double root should be 1");
}

/**
 * Test that x^2+x+1 in real (Eq2deg class) 
 * the result should an exception
 */
BOOST_AUTO_TEST_CASE (eq2deg3) {
  BOOST_TEST_MESSAGE("Testing x^2+x+1");
  Eq2deg eq1(1, 1, 1);
  BOOST_CHECK_THROW(eq1.computeDelta(); , std::exception );
}

// Test for the Eq2degComp class

/**
 * Test the resolution of x^2+x+1 in complex (Eq2degComp class)
 */
BOOST_AUTO_TEST_CASE (eq2degComp1) {
  BOOST_TEST_MESSAGE("Testing x^2+x+1 in complex");
  Eq2degComp* eq1 = new Eq2degComp (1, 1, 1);
  assert (eq1 != nullptr);
  eq1->computeDelta();
  double delta = eq1->getDelta();
  eq1->computeRoots();
  std::cout << "Discriminant: " << delta << std::endl;
  std::complex<double> zDelta = delta;
  std::complex<double> zB = -1;
  std::complex<double> zD = 2;
  std::complex<double> zRoot1 = (zB-sqrt(zDelta))/zD;
  std::complex<double> zRoot2 = (zB+sqrt(zDelta))/zD;
  std::complex<double> zR1 = eq1->getRoot(1);
  std::complex<double> zR2 = eq1->getRoot(2);

  BOOST_CHECK_MESSAGE (delta == -3,
                       "The discriminant should be -3");
  BOOST_CHECK_MESSAGE (eq1->getRoot(1) == zRoot1,
                       "The first root should be (-0.5,-0.866025)");

  BOOST_CHECK_MESSAGE (eq1->getRoot(2) == zRoot2,
                       "The second root should be (-0.5,0.866025)");
  // Cleaning
  delete eq1; eq1 = nullptr;
}

// End the test suite
BOOST_AUTO_TEST_SUITE_END()
