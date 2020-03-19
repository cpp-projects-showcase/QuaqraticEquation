C++ Course - Second Degree Equations
====================================

[![Build Status](https://travis-ci.com/cpp-projects-showcase/QuaqraticEquation.svg?branch=master)](https://travis-ci.com/cpp-projects-showcase/QuaqraticEquation)

# What is this repository for?
* This project povides tools to solve quadratics equations
* Version 1.0  15 March 2020
* Generated documentation on https://cpp-projects-showcase.github.io/QuaqraticEquation

The tools have some limitations:
* The equation must be quadratic,
  _e.g._ the coefficient of `x^2` cannot be null
* The coefficient are real numbers (integer, etc...),
  complex numbers not allowed

The [`Eq2deg` class](Eq2deg.hpp) is designed to deal with equations having real roots.
It throws an exception in case of negative discriminant.
 
The Eq2degComp class is derived from Eq2deg and allow complex roots. The 
coefficients need to be real numbers.


# How do I get set up?

* Clone the repos: `git clone git@github.com:cpp-projects-showcase/QuaqraticEquation.git`
* Go into the cloned directory: `cd QuaqraticEquation`
* Create your `build` directory and change into it: `mkdir build && cd build`
* Launch the build: `cmake .. && make`
* Test everything: `make check`
* Build the documentation: `make docs` (it needs Doxygen)
* Read the doc: `<myBrowser> html/index.html`


