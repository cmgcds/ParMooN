// =======================================================================
// BaseFunct.h   1.1
//
// Class:       BaseFunct
// Purpose:     base functions for finite elements
//
// Author:      Sashikumaar Ganesan 05.12.18
// =======================================================================
#include <memory>
#include <vector>

#ifndef __BASEFUNCT__
#define __BASEFUNCT__

// #include <QuadFormula1D.h>
#include <Parameters.h>
#include <FeEnumerations.h>

using namespace std;

/** set of all base function on the reference element for a finite elements */
class PBaseFunct
{
  protected:
    /** number of base functions = dimension of local space */
    int Dimension;
    
    /** status of changability of entries */
    bool changable;

    /** polynomial degree */
    int PolynomialDegree;

    /** accuracy */
    int Accuracy;

  public:

    /** constructor without filling data structure */
    PBaseFunct(int dimension);

    /** return the dimension of local space */
    int GetDimension() { return Dimension; }

    /** return the values for derivative MultiIndex at xi */
//     void GetDerivatives(MultiIndex1D MultiIndex, double xi, std::vector<double>values)
//       { Functions[MultiIndex](xi, values); };

    /** return the values for derivative MultiIndex at all
        quadrature points */
//     void GetDerivatives(MultiIndex1D MultiIndex, 
//                         TQuadFormula1D *formula, double **values);

    /** set status to unchangable */
    void SetUnchangable() { changable = false; };

    /** set function for derivative MultiIndex */
    void SetFunction(MultiIndex1D MultiIndex, DoubleFunct1D* function);

    
//     template <typename T>
//      void SetFunction(MultiIndex1D MultiIndex, DoubleFunct1D* function);
    
    /** make date on reference element */
//     void MakeRefElementData(QuadFormula1D QuadFormula); !!!!! remove it after installing quad formulae

    /** return polynomial degree */
    int GetPolynomialDegree() { return PolynomialDegree; };

    /** return accuracy */
    int GetAccuracy() { return Accuracy; };

};

#endif
