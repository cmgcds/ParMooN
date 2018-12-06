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
                           DoubleFunct1D* functions, 
                           DoubleFunct1D* derivativesxi,
                           DoubleFunct1D* derivativesxixi)
{
//   Dimension=dimension;
// 
//   BaseFunct = basefunct;
// 
//   Functions[D0]=functions;
//   Functions[D1]=derivativesxi;
//   Functions[D2]=derivativesxixi;
// 
//   changable = false;
}

/** constructor, fill in all information */
PBaseFunct1D::PBaseFunct1D(int dimension, BaseFunct1D basefunct,
                           DoubleFunct1D* functions, 
                           DoubleFunct1D* derivativesxi,
                           DoubleFunct1D* derivativesxixi,
                           int polynomialdegree,
                           int accuracy)
{
//   Dimension=dimension;
// 
//   BaseFunct = basefunct;
// 
//   Functions[D0]=functions;
//   Functions[D1]=derivativesxi;
//   Functions[D2]=derivativesxixi;
// 
//   changable = false;
// 
//   PolynomialDegree = polynomialdegree;
//   Accuracy = accuracy;
}


/** constructor without filling data structure */
PBaseFunct1D::PBaseFunct1D(int dimension)
{
//   Dimension = dimension;
// 
//   changable = false;
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
void PBaseFunct1D::SetFunction(MultiIndex1D MultiIndex, 
                               DoubleFunct1D* function)
{
  if(changable)
    Functions[MultiIndex] = function;
}

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
