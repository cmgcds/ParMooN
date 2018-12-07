// =======================================================================
// BaseFunct1D.h   1.1
//
// Class:       BaseFunct1D
// Purpose:     base functions for 1d finite element
//
// Author:      Sashikumaar Ganesan 05.12.18
// =======================================================================
#include <memory>
#include <vector>

#ifndef __BASEFUNCT1D__
#define __BASEFUNCT1D__

#include <BaseFunct.h>
// #include <QuadFormula1D.h>
#include <Parameters.h>
#include <FeEnumerations.h>

using namespace std;

/** set of all base function on the reference element in one-dimension */
class PBaseFunct1D  : public PBaseFunct
{
  protected:
    /** Id for this set of base functions */
    BaseFunct1D  Basefunction;
 
    /** array for all functions and derivatives */
    vector< shared_ptr< DoubleFunct1D > >Functions;
    
  public:
    /** constructor, fill in all information */
    PBaseFunct1D(int dimension, BaseFunct1D basefunct,
                 shared_ptr< DoubleFunct1D > functions, 
                 shared_ptr< DoubleFunct1D > derivativesxi,
                 shared_ptr< DoubleFunct1D > derivativesxixi);

    /** constructor, fill in all information */
    PBaseFunct1D(int dimension, BaseFunct1D basefunct,
                 shared_ptr< DoubleFunct1D > functions, 
                 shared_ptr< DoubleFunct1D > derivativesxi,
                 shared_ptr< DoubleFunct1D > derivativesxixi,
                 int polynomialdegree,
                 int accuracy);
      
    
     template <typename S,typename T>
     void SetFunction(S MultiIndex, T *function)
      { if(changable) Functions[MultiIndex] = function; }  
      
    /** return the values for derivative MultiIndex at xi */
//     void GetDerivatives(MultiIndex1D MultiIndex, double xi, std::vector<double>values)
//       { Functions[MultiIndex](xi, values); };

    /** return the values for derivative MultiIndex at all
        quadrature points */
//     void GetDerivatives(MultiIndex1D MultiIndex, 
//                         TQuadFormula1D *formula, double **values);

};

#endif
