#ifndef __EQ2DEGCOMP_HPP
#define __EQ2DEGCOMP_HPP

/**
 * CS-17, Eq2degComp.hpp
 * Derived class to manage quadratics equations with complex roots
 * a*x^2+b*x+c=0
 * 
 * with the following restrictions:
 * The coefficients are real
 * 
 * @author Christophe Gattardi
 * @version 1.0 15/03/2020
 */

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include<complex>

#include <Eq2deg.hpp>

class Eq2degComp: public Eq2deg{
    protected:
        bool m_complexRoots;
        std::vector<std::complex<double>> m_rac;
    public:
        /**
         * @brief Construct a new Eq2degComp object
         * 
         * @param a double: coefficent of x^2
         * @param b double: coefficient of x
         * @param c double: constant
         */
        Eq2degComp(const double& iA, const double& iB, const double& iC );
        virtual ~Eq2degComp();
        /**
         * @brief compute the discriminant
         * 
         */
        virtual void computeDelta();
        /**
         * @brief Compute the roots
         * 
         */
        virtual void computeRoots();
        /**
         * @brief Get the root value by number
         * 
         * @param rootNumber the number of the root to retrieve (1 or 2)
         * @return double 
         */
        std::complex<double> getRoot(const int& iRootNumber) const;
    private:
        /**
         * Display of the object.
         *
         * @return std::string Dump of the object.
         */
        virtual std::string describe() const;
};

#endif //__EQ2DEGCOMP_HPP