// =======================================================================
// BaseFunct1D.C   1.1
//
// Class:       BaseFunct1D
// Purpose:     base functions for 1d finite element
//
// Author:      Sashikumaar Ganesan 05.12.18
// =======================================================================

#include <Parameters.h>
#include <BaseFunct1D.h>
// #include <FEDatabase2D.h>
#include <stdlib.h>

/** constructor, fill in all information */
PBaseFunct1D::PBaseFunct1D(int dimension, BaseFunct1D basefunct,
                           shared_ptr< DoubleFunct1D > functions, 
                           shared_ptr< DoubleFunct1D > derivativesxi,
                           shared_ptr< DoubleFunct1D > derivativesxixi) : PBaseFunct(dimension)
{
 
  Basefunction = basefunct;

  
  if(Functions.size()!= N_MultiIndices2D) 
      {Functions.reserve(N_MultiIndices2D);}
      
  Functions[D0]=functions;
  Functions[D1]=derivativesxi;
  Functions[D2]=derivativesxixi;
}

/** constructor, fill in all information */
PBaseFunct1D::PBaseFunct1D(int dimension, BaseFunct1D basefunct,
                           shared_ptr< DoubleFunct1D > functions, 
                           shared_ptr< DoubleFunct1D > derivativesxi,
                           shared_ptr< DoubleFunct1D > derivativesxixi,
                           int polynomialdegree,
                           int accuracy) : PBaseFunct(dimension)
{
 
  Basefunction = basefunct;

  if(Functions.size()!= N_MultiIndices2D) 
    {Functions.reserve(N_MultiIndices2D);}
      
  Functions[D0]=functions;
  Functions[D1]=derivativesxi;
  Functions[D2]=derivativesxixi;

  PolynomialDegree = polynomialdegree;
  Accuracy = accuracy;
}


/** return the values for derivative MultiIndex at all
    quadrature points */
// void BaseFunct1D::GetDerivatives(MultiIndex1D MultiIndex, 
//                         TQuadFormula1D *formula, double **values)
// {
//   int i, N_;
//   double *w, *xi;
// 
//   formula->GetFormulaData(N_, w, xi);
// 
//   for(i=0;i<N_;i++)
//     GetDerivatives(MultiIndex, xi[i], values[i]);
// 
// }

/** set function for derivative MultiIndex */
// void PBaseFunct1D::SetFunction(S MultiIndex, T *function)
// {
//   if(changable)
//     Functions[MultiIndex] = function;
// }

/** make data on reference element */
// void PBaseFunct1D::MakeRefElementData(QuadFormula1D QuadFormula)
// {
//   int j;
//   double **Values, *AllValues;
//   TQuadFormula1D *qf;
// 
//   qf = TFEDatabase2D::GetQuadFormula1D(QuadFormula);
// 
//   // D0
//   Values=TFEDatabase2D::GetRefElementValues(BaseFunct, QuadFormula, D0);
//   if( Values==NULL)
//   {
//     Values = new double* [MaxN_QuadPoints_1D];
//     AllValues = new double [MaxN_QuadPoints_1D*MaxN_BaseFunctions1D];
//     for(j=0;j<MaxN_QuadPoints_1D;j++)
//       Values[j] = AllValues+j*MaxN_BaseFunctions1D;
//     GetDerivatives(D0, qf, Values);
// 
//     TFEDatabase2D::RegisterRefElementValues(BaseFunct, QuadFormula, 
//                                           D0, Values);
//   }
// 
//   // D1
//   Values=TFEDatabase2D::GetRefElementValues(BaseFunct, QuadFormula, D1);
//   if( Values==NULL)
//   {
//     Values = new double* [MaxN_QuadPoints_1D];
//     AllValues = new double [MaxN_QuadPoints_1D*MaxN_BaseFunctions1D];
//     for(j=0;j<MaxN_QuadPoints_1D;j++)
//       Values[j] = AllValues+j*MaxN_BaseFunctions1D;
//     GetDerivatives(D1, qf, Values);
//     TFEDatabase2D::RegisterRefElementValues(BaseFunct, QuadFormula, 
//                                           D1, Values);
//   }
// 
//   // D2
//   Values=TFEDatabase2D::GetRefElementValues(BaseFunct, QuadFormula, D2);
//   if( Values==NULL)
//   {
//     Values = new double* [MaxN_QuadPoints_1D];
//     AllValues = new double [MaxN_QuadPoints_1D*MaxN_BaseFunctions1D];
//     for(j=0;j<MaxN_QuadPoints_1D;j++)
//       Values[j] = AllValues+j*MaxN_BaseFunctions1D;
//     GetDerivatives(D2, qf, Values);
//     TFEDatabase2D::RegisterRefElementValues(BaseFunct, QuadFormula, 
//                                           D2, Values);
//   }
// 
// }
