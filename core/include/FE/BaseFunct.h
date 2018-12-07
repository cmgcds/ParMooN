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
    PBaseFunct(int dimension)
     {
      Dimension = dimension;
      changable = false;
     }


    /** return the dimension of local space */
    int GetDimension() { return Dimension; }

    /** set status to unchangable */
    void SetUnchangable() { changable = false; };

    /** set function for derivative MultiIndex */   
/*    template <typename S,typename T>
     void SetFunction(S MultiIndex, T *function)
      { if(changable) Functions[MultiIndex] = function; }  */ 
    
    /** make date on reference element */
    template <typename Q>
    void MakeRefElementData(Q QuadFormula);

    /** return polynomial degree */
    int GetPolynomialDegree() { return PolynomialDegree; };

    /** return accuracy */
    int GetAccuracy() { return Accuracy; };

};

#endif
