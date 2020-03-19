#ifndef __EQ2DEG_HPP
#define __EQ2DEG_HPP

/**
 * CS-17, Eq2deg.hpp
 * Base class to manage quadratics equations
 * a*x^2+b*x+c=0
 * 
 * with the following restrictions:
 * The coefficients are real
 * The roots are real
 * In case of complex roots an exception is thrown
 * 
 * @author Christophe Gattardi
 * @version 1.0 15/03/2020
 */

// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <vector>

#include <Utilities.hpp>

class Eq2deg: public Utilities{
    protected:
        double m_a, m_b, m_c;
        double m_delta;
        std::vector<double> m_rac;
    public:
        /**
         * @brief Construct a new Eq2deg object
         * 
         * @param a double: coefficent of x^2
         * @param b double: coefficient of x
         * @param c double: constant
         */
        Eq2deg(const double& iA, const double& iB, const double& iC );
        virtual ~Eq2deg();
        /**
         * @brief compute the discriminant and raise an exception if negative
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
        double getRoot(const int& iRootNumber) const;

        /**
         * @brief Get the discriminant
         * 
         * @return double 
         */
        virtual double getDelta();
        /**
         * @brief Object to handle exception when no reals roots exists
         * 
         */
        struct NegativeDeltaException : public std::exception {
            const char * what () const throw () {
                return "Invalid coefficients, no real roots";
            }
        };
    private:
        /**
         * Display of the object.
         *
         * @return std::string Dump of the object.
         */
        virtual std::string describe() const;
};

#endif //__EQ2DEG_HPP