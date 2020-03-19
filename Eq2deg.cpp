// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <math.h>
#include<iostream>
#include <sstream>
// Eq2deg object
#include <Eq2deg.hpp>

// //////////////////////////////////////////////////////////////////////
Eq2deg::Eq2deg(const double& iA, const double& iB, const double& iC) :
    m_a(iA == 0 ? throw std::out_of_range("x^2 coeff cannot be null") : iA),
        m_b(iB), m_c(iC) {}


// //////////////////////////////////////////////////////////////////////
Eq2deg::~Eq2deg() {}

// //////////////////////////////////////////////////////////////////////
void Eq2deg::computeDelta() {
    m_delta=m_b*m_b-4*m_a*m_c;
    if (m_delta < 0) throw NegativeDeltaException();
}

// //////////////////////////////////////////////////////////////////////
double Eq2deg::getDelta(){
    return m_delta;
}

// //////////////////////////////////////////////////////////////////////
void Eq2deg::computeRoots(){
    double root;
    if (m_delta > 0){
        root = (-m_b-sqrt(m_delta))/(2*m_a);
        m_rac.push_back(root);
        root = (-m_b+sqrt(m_delta))/(2*m_a);
        m_rac.push_back(root);
    }
    if (m_delta == 0){
        root = -m_b/(2*m_a);
        m_rac.push_back(root);
    }
}

// //////////////////////////////////////////////////////////////////////
double Eq2deg::getRoot(const int& iRootNumber) const {
    return m_rac[iRootNumber - 1];
}

// //////////////////////////////////////////////////////////////////////
std::string Eq2deg::describe() const {
    std::ostringstream ostr;
    ostr << "Equation: " << m_a << "*x^2 + " << m_b << "*x + " << m_c
         << " = 0 " << std::endl << "Discriminant: " << m_delta << std::endl;
    if (m_delta == 0){
        ostr << "Racine double: " << this->getRoot(1) << std::endl;
    }else{
        ostr << "Racine 1: " << this->getRoot(1) << std::endl;
        ostr << "Racine 2: " << this->getRoot(2) << std::endl;
    }
    return ostr.str();
}