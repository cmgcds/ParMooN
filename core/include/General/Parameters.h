// =======================================================================
// Parameter.h   1.1  
// Purpose:     constants, parameters, and function definitions used in ParMooN
//
// Author:     Sashikumaar Ganesan 01.12.18
// =======================================================================

#include <math.h>
#include <iostream>
#include <vector>

using std::vector;

#ifndef __PARAMETERS__
#define __PARAMETERS__

#ifdef NULL
  #undef NULL
#endif

#define NULL 0

#ifdef __2D__
#define GEO_DIM 2
#else
#define GEO_DIM 3
#endif


#define Pi M_PI
#define ln2 log((double) 2.0)

// #define SizeOfPointer  ((long) 4)
// #define SizeOfInt      ((long) 4)
// #define SizeOfFloat    ((long) 4)
// #define SizeOfDouble   ((long) 8)

#ifdef FALSE
#undef FALSE
#endif
#ifdef TRUE
#undef TRUE
#endif

#ifdef _MPI
  #define BYADD 0
  #define BYMASTER 1
  #define BYOWN 2
#endif

enum class boolean {FALSE, TRUE};

#define N_BOUNDCOND 10
enum class BoundCond { DIRICHLET, NEUMANN, ROBIN, SLIP, FREESURF, 
                 SLIP_FRICTION_PENETRATION_RESISTANCE, 
                 INTERFACE, SUBDOMAIN_INTERFACE, SUBDOMAIN_HALOBOUND, DIRICHLET_WEAK};

enum class JointType {Joint, JointEqN, BoundaryPoint, BoundaryEdge, BoundaryFace,
                InterfaceJoint, PeriodicJoint, IsoInterfaceJoint,
                IsoJointEqN, IsoBoundEdge, IsoBoundFace,
                Joint_2to1, 
                InterfaceJoint3D, IsoInterfaceJoint3D,
                SubDomainJoint, SubDomainHaloJoint, InnerInterfaceJoint,
                InnerEdge, IsoEdge3D, BDEdge3D};

typedef void DoubleFunct1D(double, vector<double> );
typedef void DoubleFunct2D(double, double, vector<double> );
typedef void DoubleFunct3D(double, double, double, vector<double>);
typedef void DoubleFunctND(int, vector<double>, vector<double>);
typedef void DoubleFunctVect(vector<double>, vector<double>);
typedef int IntFunct2D(double, double);
typedef double DoubleFunct2Param(double, double);

typedef void BoundCondFunct3D(int, double, double, double, BoundCond &);
typedef void BoundValueFunct3D(int, double, double, double, double &);
typedef void BoundCondFunct2D(int, double, BoundCond &);
typedef void BoundValueFunct2D(int, double, double &);

typedef void ErrorMethod2D(int, vector<double>, vector<double>, 
                           vector<double>, vector<double>, double,
                           vector<vector<double> >, vector<vector<double> >,
                           vector<vector<double> >, vector<double>);

typedef void ErrorMethod3D(int, vector<double>, vector<double>, vector<double>,
                           vector<double>, vector<double>, double,
                           vector<vector<double> >, vector<vector<double> >,
                           vector<vector<double> >, vector<double>);

typedef DoubleFunctVect ParamFct;

typedef void CoeffFct2D(int n_points, vector<double>X, vector<double>Y,
                        vector<vector<double> >param, vector<vector<double> >coeffs);

typedef void CoeffFct3D(int n_points, vector<double>X, vector<double>Y, vector<double>Z,
                        vector<vector<double> >param, vector<vector<double> >coeffs);
                        
typedef void CoeffFctND(int n_points, int N_Dim, vector<vector<double> >Coords,
                        vector<vector<double> >param, vector<vector<double> >coeffs);  

typedef void AssembleFct2D(double, vector<double>, double, vector<vector<double> >, 
                           int *, vector<vector<vector<double> > >, vector<vector<double> >);

typedef void AssembleFctParam2D(double, vector<double>, vector<double>,
                                double, vector<vector<double> >, 
                                int *, vector<vector<vector<double> > >, vector<vector<double> >);

typedef void AssembleFct3D(double, vector<double>, double, vector<vector<double> >, 
                           int *, vector<vector<vector<double> > >, vector<vector<double> >);

typedef void AssembleFctParam3D(double, vector<double>, vector<double>,
                                double, vector<vector<double> >, 
                                int *, vector<vector<vector<double> > >, vector<vector<double> >);

class TBaseCell;
typedef void ManipulateFct2D(int, vector<vector<double> >, vector<vector<double> >, TBaseCell *);

typedef void ManipulateFct3D(int, vector<vector<double> >, vector<vector<double> >, TBaseCell *);

class TCollection;
typedef void EvalAllNF(TCollection *, TBaseCell *, vector<double>, vector<double>);
typedef void EvalJointNF(TCollection *, TBaseCell *, int, vector<double>, vector<double>);

class TFESpace2D;
typedef void CheckWrongNeumannNodesFunct2D(TCollection *, TFESpace2D *,
                                           int &, int* &,
                                           int* &, double* &);

class TSquareMatrix;
class TMatrix;
typedef void MatVecProc(TSquareMatrix **, TMatrix **, vector<double>, vector<double>);
typedef void DefectProc(TSquareMatrix **, TMatrix **, vector<double>, vector<double>,
                        vector<double>);

class TVertex;
class TIsoBoundEdge;
typedef void ModifyMeshCoords(double , double , double &, double &, double );
typedef void ModifyBoundCoords(int *, TVertex **, TIsoBoundEdge **,  vector<double>, double);

typedef void ModifyMeshCoords_3D(double , double ,double , double &, double &,double &, double );
typedef void ModifyBoundCoords_3D(int, TVertex **, int, int *, TBaseCell **, double);
class TFEVectFunct3D;
typedef void MoveBound_3D(TFEVectFunct3D *, TFEVectFunct3D *, vector<double>, int, TVertex **, int, int *, TBaseCell **, double);

#ifdef _MPI
class TParVectorNSE3D;
typedef void ParDefectProc(TSquareMatrix **, TMatrix **, TParVectorNSE3D  *, TParVectorNSE3D *,
                        TParVectorNSE3D *);
#endif

typedef int TypeBoundSwitchFunct2D(int, double );

class TFEFunction2D;
class TFEVectFunct2D;
typedef void EvaluateSolutionFunct2D(TFEFunction2D **, TFEVectFunct2D **, 
                                     vector<double>, int *);


#define GALERKIN         1
#define SDFEM            2
#define SUPG             2
#define UPWIND           3
#define SMAGORINSKY      4
#define SMAGORINSKY_EXPL 5
#define CLASSICAL_LES    6
#define GL00_CONVOLUTION 7
#define GL00_AUX_PROBLEM 8
#define VMS_PROJECTION   9
#define VMS_PROJECTION_EXPL 10
#define VMS_RFB_EXPL     11
#define VMS_PROJECTION_SD     12
#define VMS_RFB_EXPL_COUPLED     13
#define LERAY_ALPHA_EXPL   16
#define LERAY_ALPHA_IMPL   17
#define NSE_RFB          21
#define SDFEM_DIVDIV     5
#define LOCAL_PROJECTION 14
#define LOCAL_PROJECTION_2_LEVEL 15
#define CIP              4
#define DG               5
#define GLS              6
#define FD               0
#define ENO_3           13
#define WENO_5          14
#define HEATLINE        100

#define OSEEN_PROBLEM    13

   

#define AMG_SOLVE 0
#define GMG 1
#define DIRECT 2

// maybe we should define more types here (like CD, TCD, TNSE, TSTOKES,...)
#define NSE    0
#define STOKES 1
#define OSEEN  2

#define SCALAR 100

#define MAXN_LEVELS 100

#ifdef _MPI
  #define BEGIN_SEQ \
    MPI_Barrier(comm); \
    for(int _i=0;_i<size;++_i) \
    { \
      if ( rank == _i ) \
      { 
      
  #define END_SEQ \
      } \
      MPI_Barrier(comm); \
    }
#endif


#endif
