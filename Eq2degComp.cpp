// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cmath>
#include<complex>
#include<iostream>
#include <sstream>
// Eq2degComp object
#include <Eq2degComp.hpp>

// //////////////////////////////////////////////////////////////////////
Eq2degComp::Eq2degComp(const double& iA, const double& iB, const double& iC) :
    Eq2deg(iA, iB, iC), m_complexRoots(false) {
}


// //////////////////////////////////////////////////////////////////////
Eq2degComp::~Eq2degComp() {}

// //////////////////////////////////////////////////////////////////////
void Eq2degComp::computeDelta() {
    m_delta=m_b*m_b-4*m_a*m_c;
    if (m_delta < 0) m_complexRoots = true;
}

// //////////////////////////////////////////////////////////////////////
void Eq2degComp::computeRoots(){
    std::complex<double> zRoot;
    std::complex<double> zDelta = m_delta;
    if (m_delta == 0){
        zRoot = -m_b/(2*m_a);
        m_rac.push_back(zRoot);
    }else{
        zRoot = (-m_b-sqrt(zDelta))/(2*m_a);
        m_rac.push_back(zRoot);
        zRoot = (-m_b+sqrt(zDelta))/(2*m_a);
        m_rac.push_back(zRoot);
    }
}

// //////////////////////////////////////////////////////////////////////
std::complex<double> Eq2degComp::getRoot(const int& iRootNumber) const {
    return m_rac[iRootNumber - 1];
}

// //////////////////////////////////////////////////////////////////////
std::string Eq2degComp::describe() const {
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