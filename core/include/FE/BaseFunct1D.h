// =======================================================================
// BaseFunct1D.h   1.1
//
// Class:       BaseFunct1D
// Purpose:     base functions for 1d finite element
//
// Author:      Sashikumaar Ganesan 05.12.18
// =======================================================================

#ifndef __BASEFUNCT1D__
#define __BASEFUNCT1D__

// #include <QuadFormula1D.h>
#include <Parameters.h>
#include <FeEnumerations.h>

/** set of all base function on the reference element for a finite 
    element in two dimensions */
class PBaseFunct1D
{
  protected:
    /** number of base functions = dimension of local space */
    int Dimension;

    /** Id for this set of base functions */
    BaseFunct1D BaseFunct;
// std::shared_ptr<Base> p 
    /** array for all functions and derivatives */
    DoubleFunct1D *Functions[N_MultiIndices1D];

    /** status of changability of entries */
    bool changable;

    /** polynomial degree */
    int PolynomialDegree;

    /** accuracy */
    int Accuracy;

  public:
    /** constructor, fill in all information */
    PBaseFunct1D(int dimension, BaseFunct1D basefunct,
                 DoubleFunct1D* functions, 
                 DoubleFunct1D* derivativesxi,
                 DoubleFunct1D* derivativesxixi);

    /** constructor, fill in all information */
    PBaseFunct1D(int dimension, BaseFunct1D basefunct,
                 DoubleFunct1D* functions, 
                 DoubleFunct1D* derivativesxi,
                 DoubleFunct1D* derivativesxixi,
                 int polynomialdegree,
                 int accuracy);

    /** constructor without filling data structure */
    PBaseFunct1D(int dimension);

    /** return the dimension of local space */
    int GetDimension() 
    { return Dimension; }

    /** return the values for derivative MultiIndex at xi */
    void GetDerivatives(MultiIndex1D MultiIndex, double xi, std::vector<double>values)
      { Functions[MultiIndex](xi, values); };

    /** return the values for derivative MultiIndex at all
        quadrature points */
//     void GetDerivatives(MultiIndex1D MultiIndex, 
//                         TQuadFormula1D *formula, double **values);

    /** set status to unchangable */
    void SetUnchangable()
      { changable = false; };

    /** set function for derivative MultiIndex */
    void SetFunction(MultiIndex1D MultiIndex, DoubleFunct1D* function);

    /** make date on reference element */
//     void MakeRefElementData(QuadFormula1D QuadFormula); !!!!! remove it after installing quad formulae

    /** return polynomial degree */
    int GetPolynomialDegree()
      { return PolynomialDegree; };

    /** return accuracy */
    int GetAccuracy()
      { return Accuracy; };

};

#endif
