# README #

### What is this repository for? ###

* This project povides tools to solve quadratics equations
* Version 1.0 15/03/2020

The tools have limitations:
 * The equation must be quadratic, eg the coefficient of x^2 cannot be null
 * The coefficient are real (integer, etc...), complex not allowed

The Eq2deg class is designed to deal with equations having real roots.
It throw an exception in case of negative discriminant
 
The Eq2degComp class is derived from Eq2deg and allow complex roots. The 
coefficients needs to be real


### How do I get set up? ###

* clone the repos: `git clone git@github.com:cpp-projects-showcase/QuaqraticEquation.git`
* cd into the cloned directory: `cd quadraticequation`
* create your build dir and change into it: `mkdir build && cd build`
* launch the build: `cmake .. && make`
* test everything: `make check`
* build the doc: `make docs`(need doxygen)
* read the doc: `<myBrowser> html/index.html`