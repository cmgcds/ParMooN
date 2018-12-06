// =======================================================================
// Database.h   1.1
//
// Class:       Database
// Purpose:     database of needed refinement, mapping and
//              shape descriptors as well as iterators and parameter database
//
// Author:      Sashikumaar Ganesan 01.12.18
// =======================================================================

#include <string.h>
#include <iostream>
#include <memory>

class Database;

#ifdef _MPI
#  include "mpi.h"
#endif

#ifdef _HYBRID
  #include <omp.h>
#endif

#ifndef __DATABASE__
#define __DATABASE__

// #include <Iterator.h>
// #include <RefDesc.h>
#include <Parameters.h>
// #include <Mapper.h>




struct ParameterDB
{
//   int VERSION;

  //======================================================================
  /** parameters data output and input files                            */
  //======================================================================
  std::string OUTFILE = "ParMooN_Default_OutFile";
  std::string SMESHFILE = "ParMooN_Default_SmeshFile";

//   //======================================================================
//   /** parameters for controling the program */
//   //======================================================================
//   int PRECOND_LS;
//   int WRITE_MATLAB;
//   int SAVE_DATA;
//   int READ_DATA;
//   int READ_GRAPE_FILE;
//   int ESTIMATE_ERRORS;
//   
//   int timeprofiling;  //(time profiling)
// 
//   //======================================================================
//   /** parameters for setting finite element spaces                      */
//   //======================================================================
//   int ANSATZ_ORDER;
//   int TEST_ORDER;
// 
//   int VELOCITY_SPACE;
//   int PRESSURE_SPACE;
// 
//   //======================================================================
//   /** parameters for grid generation                                    */
//   //======================================================================
// 
//   int OMPNUMTHREADS;
// 
//   double DRIFT_X;
//   double DRIFT_Y;
//   double DRIFT_Z;
//   int REFINEMENT;
//   int GRID_TYPE;
//   int GRID_TYPE_1;
//   int GRID_TYPE_2;
//   int MESHGEN_ALLOW_EDGE_REF;
//   int MESHGEN_REF_QUALITY;
// 
//   //======================================================================
//   /** parameters for setting the discretization                         */
//   //======================================================================
//   // generalParameterD
//   int DISCTYPE;
//   int USE_ISOPARAMETRIC;
//   int CELL_MEASURE;
//   
//   // parameter for non-conforming elements
//   int NC_TYPE;
//   
//   // DISCTYPE for internal space, PBE
//   int  INTL_DISCTYPE;
//     int SAVESOL;

//   char *SMESHFILE;
// 
//   
//   //======================================================================
//   /** parameters for controling the program */
//   //======================================================================
//   int PRECOND_LS;
//   int WRITE_MATLAB;
//   int SAVE_DATA;
//   int READ_DATA;
//   int READ_GRAPE_FILE;
//   int ESTIMATE_ERRORS;
//   
//   int timeprofiling;  //(time profiling)
// 
//   //======================================================================
//   /** parameters for setting finite element spaces                      */
//   //======================================================================
//   int ANSATZ_ORDER;ParameterD
//   int TEST_ORDER;
// 
//   int VELOCITY_SPACE;
//   int PRESSURE_SPACE;
// 
//   //======================================================================
//   /** parameters for grid generation                                    */
//   //======================================================================
// 
//   int OMPNUMTHREADS;
// 
//   double DRIFT_X;ParameterD
//   double DRIFT_Y;
//   double DRIFT_Z;
//   int REFINEMENT;
//   int GRID_TYPE;
//   int GRID_TYPE_1;
//   int GRID_TYPE_2;
//   int MESHGEN_ALLOW_EDGE_REF;
//   int MESHGEN_REF_QUALITY;
// 
//   //======================================================================
//   /** parameters for setting the discretization                         */
//   //======================================================================
//   // general
//   int DISCTYPE;
//   int USE_ISOPARAMETRIC;
//   int CELL_MEASURE;
//   
//   // parameter for non-conforming elements
//   int NC_TYPE;
//   
//   // DISCTYPE for internal space, PBE
//   int  INTL_DISCTYPE;
//   ParamDB
//   /** upwind methods */
//   int UPWIND_ORDER;
//   double UPWIND_FLUX_DAMP;
//   int UPWIND_APPLICATION;
// 
//   // Shishkin meshes
//   int SHISHKIN_MESH;
//   double SHISHKIN_DIAM;
// 
//   /** stabilization with face integrals */
//   int WEAK_BC;
//   double FACE_SIGMA;
//   double WEAK_BC_SIGMA;
//   double TAU;
//   double TAU2;
//   double TAU3;
// 
//   /** SUPG or SDFEM method */
//   int    SDFEM_TYPE;
//   double DELTA0;
//   double DELTA1;
//   double SDFEM_POWER0;
//   int    SDFEM_NORM_B;
//   double ADJOINT_FACTOR_4_OMEGA_EQ_0;
//   int    CIP_TYPE;
// 
//   //======================================================================
//   /** parameters for vectorial FE (Raviart-Thomas, Brezzi-Douglas-Marini) */
//   //======================================================================
//   int NORMAL_ORIENTATION_QUAD[4];
//   int NORMAL_ORIENTATION_TRIA[3];
//   int NORMAL_ORIENTATION_TETRA[4];
//   int NORMAL_ORIENTATION_HEXA[6];
// 
//   //======================================================================
//   /** parameter for local projection stabilization */
//   //======================================================================
//   int LP_FULL_GRADIENT;
//   int LP_STREAMLINE;
//   int LP_DIVERGENCE;
//   int LP_PRESSURE;
//   int LP_CROSSWIND;
//   int LP_COEFF_TYPE;
// 
//   double LP_FULL_GRADIENT_COEFF;
//   double LP_STREAMLINE_COEFF;
//   double LP_DIVERGENCE_COEFF;
//   double LP_PRESSURE_COEFF;
// 
//   double LP_FULL_GRADIENT_EXPONENT;
//   double LP_STREAMLINE_EXPONENT;
//   double LP_DIVERGENCE_EXPONENT;
//   double LP_PRESSURE_EXPONENT;
// 
//   int LP_ORDER_DIFFERENCE;
//   int LP_FULL_GRADIENT_ORDER_DIFFERENCE;
//   int LP_STREAMLINE_ORDER_DIFFERENCE;
//   int LP_DIVERGENCE_ORDER_DIFFERENCE;
//   int LP_PRESSURE_ORDER_DIFFERENCE;
//   
//   int LP_CROSSWIND_COEFF_TYPE;
//   double LP_CROSSWIND_COEFF;
//   double LP_CROSSWIND_EXPONENT; 
// 
//   //======================================================================
//   /** PARAMETERS FOR STOKES AND NAVIER-STOKES PROBLEMS                  */
//   //======================================================================
// 
//   /** general parameters */
//   double RE_NR; //FIXME This parameter must really be removed from global scope!
//   double RA_NR;
//   double ROSSBY_NR;
//   double START_RE_NR;
//   double RE_NR_INCREMENT;
//   int FLOW_PROBLEM_TYPE;
//   int NSE_NONLINEAR_FORM;
//   int NSTYPE;
//   int LAPLACETYPE;
//   int DEFECT_CORRECTION_TYPE;
//   double OSEEN_ZERO_ORDER_COEFF;
//     
//   double FR_NR;
//   double WB_NR;
//   double PR_NR;
//   double PE_NR;
//   double BI_NR;
//   int Axial3D;
//   int Axial3DAxis;
//   
//   /** parameters for LES */
//   double FILTER_WIDTH_CONSTANT;
//   double FILTER_WIDTH_POWER;
//   double GAUSSIAN_GAMMA;
//   int CONVOLUTE_SOLUTION;
// 
//   /** parameters for turbulent vParameterDiscosity */
//   int TURBULENT_VISCOSITY_TYPE;
//   int TURBULENT_VISCOSITY_TENSOR;
//   double TURBULENT_VISCOSITY_CONSTANT;
//   double TURBULENT_VISCOSITY_POWER;
//   double TURBULENT_VISCOSITY_SIGMA;
// 
//   /** parameters for VMS */
//   int VMS_LARGE_VELOCITY_SPACE;
//   int VMS_COARSE_MG_SMAGO;
// 
//   // constants in AdaptProjectionSpace
//   double VMS_ADAPT_LOWER;
//   double VMS_ADAPT_MIDDLE;
//   double VMS_ADAPT_UPPER;
//   int VMS_ADAPT_STEPS;
//   int VMS_ADAPT_COMP;
// 
//   double ARTIFICIAL_VISCOSITY_CONSTANT;
//   double ARTIFICIAL_VISCOSITY_POWER;
//   int VMM_COARSE_LEVEL;
//   int VMM_COARSE_SPACE_ORDER;
//   int RFB_SUBMESH_LAYERS;
// 
//   //======================================================================
//   /** parameters for slip with friction and penetration with resistance
//       boundary conditions                                               */
//   //======================================================================
//   double FRICTION_CONSTANT;
//   double FRICTION_POWER;
//   int    FRICTION_TYPE;
//   double FRICTION_U0;
//   double PENETRATION_CONSTANT;
//   double PENETRATION_POWER;
// 
// 
//   //======================================================================
//   // ******** parameters for saddle point system *********//
//   //======================================================================
//   // parameter for nonlinear iteParameterDration
//   //TODO Move that parameter to the local "nonlinear" Database!
//   int    SC_NONLIN_ITE_TYPE_SADDLE;
//   
//   //======================================================================
//   /** parameters for individual use in parallel computations */
//   //======================================================================
//   int PAR_P0; //out rank
//   int PAR_P1; // 1 - root takes part in computation; 0 - not
//   int PAR_P2; // mesh partition type: 1 - dual; 0 - nodal
//   int PAR_P3; // 1 - use halocells; 0 - dont
//   int PAR_P4; // 1-redistribution of masters 0-otherwise
//   int PAR_P5;
//   int PAR_P6;
//   int PAR_P7;
//   int PAR_P8;
//   int PAR_P9;
//   int MapperType;
//   int DSType;
//   double PAR_P10;
//   double PAR_P11;
//   double PAR_P12;
//   double PAR_P13;
//   double PAR_P14;
//   double PAR_P15;
//   double PAR_P16;
//   double PAR_P17;
//   double PAR_P18;
//   double PAR_P19;
//   double PAR_P20;
    
  //======================================================================
    
  #ifdef _MPI
  /** MPI_Comm for which the computation is started (should not be changed during coomputation)*/
  MPI_Comm Comm;
 #endif
};


struct TimeDB
{
//   double CURRENTTIME;
//   double CURRENTTIMESTEPLENGTH;
//   double TIMESTEPLENGTH;
//   double INTERNAL_STARTTIME;
//   double MIN_TIMESTEPLENGTH;
//   double MAX_TIMESTEPLENGTH;
//   double TIMESTEPLENGTH_TOL;
//   int TIMESTEPLENGTH_CONTROL;
//   
//   // control parameter
//   double THETA1;
//   double THETA2;
//   double THETA3;
//   double THETA4;
// 
//   int TIME_DISC;
//   int TIME_DISC2;
// 
//   // start and end time
//   double STARTTIME;
//   double ENDTIME;
// 
//   // write only every n-th time step
//   int STEPS_PER_IMAGE;
//   int STEPS_PER_SNAP;
  
  
//   /** upwind methods */
//   int UPWIND_ORDER;
//   double UPWIND_FLUX_DAMP;
//   int UPWIND_APPLICATION;
// 
//   // Shishkin meshes
//   int SHISHKIN_MESH;
//   double SHISHKIN_DIAM;
// 
//   /** stabilization with face integrals */
//   int WEAK_BC;
//   double FACE_SIGMA;
//   double WEAK_BC_SIGMA;
//   double TAU;
//   double TAU2;
//   double TAU3;
// 
//   /** SUPG or SDFEM method */
//   int    SDFEM_TYPE;
//   double DELTA0;
//   double DELTA1;
//   double SDFEM_POWER0;
//   int    SDFEM_NORM_B;
//   double ADJOINT_FACTOR_4_OMEGA_EQ_0;
//   int    CIP_TYPE;
// 
//   //======================================================================
//   /** parameters for vectorial FE (Raviart-Thomas, Brezzi-Douglas-Marini) */
//   //======================================================================
//   int NORMAL_ORIENTATION_QUAD[4];
//   int NORMAL_ORIENTATION_TRIA[3];
//   int NORMAL_ORIENTATION_TETRA[4];
//   int NORMAL_ORIENTATION_HEXA[6];
// 
//   //======================================================================
//   /** parameter for local projection stabilization */
//   //======================================================================
//   int LP_FULL_GRADIENT;
//   int LP_STREAMLINE;
//   int LP_DIVERGENCE;
//   int LP_PRESSURE;
//   int LP_CROSSWIND;
//   int LP_COEFF_TYPE;
// 
//   double LP_FULL_GRADIENT_COEFF;
//   double LP_STREAMLINE_COEFF;
//   double LP_DIVERGENCE_COEFF;
//   double LP_PRESSURE_COEFF;
// 
//   double LP_FULL_GRADIENT_EXPONENT;
//   double LP_STREAMLINE_EXPONENT;
//   double LP_DIVERGENCE_EXPONENT;
//   double LP_PRESSURE_EXPONENT;
// 
//   int LP_ORDER_DIFFERENCE;
//   int LP_FULL_GRADIENT_ORDER_DIFFERENCE;
//   int LP_STREAMLINE_ORDER_DIFFERENCE;
//   int LP_DIVERGENCE_ORDER_DIFFERENCE;
//   int LP_PRESSURE_ORDER_DIFFERENCE;
//   
//   int LP_CROSSWIND_COEFF_TYPE;
//   double LP_CROSSWIND_COEFF;
//   double LP_CROSSWIND_EXPONENT; 
// 
//   //======================================================================
//   /** PARAMETERS FOR STOKES AND NAVIER-STOKES PROBLEMS                  */
//   //======================================================================
// 
//   /** general parameters */
//   double RE_NR; //FIXME This parameter must really be removed from global scope!
//   double RA_NR;
//   double ROSSBY_NR;
//   double START_RE_NR;
//   double RE_NR_INCREMENT;
//   int FLOW_PROBLEM_TYPE;
//   int NSE_NONLINEAR_FORM;
//   int NSTYPE;
//   int LAPLACETYPE;
//   int DEFECT_CORRECTION_TYPE;
//   double OSEEN_ZERO_ORDER_COEFF;
//     
//   double FR_NR;
//   double WB_NR;
//   double PR_NR;
//   double PE_NR;
//   double BI_NR;
//   int Axial3D;
//   int Axial3DAxis;
//   
//   /** parameters for LES */
//   double FILTER_WIDTH_CONSTANT;
//   double FILTER_WIDTH_POWER;
//   double GAUSSIAN_GAMMA;
//   int CONVOLUTE_SOLUTION;
// 
//   /** parameters for turbulent viscosity */
//   int TURBULENT_VISCOSITY_TYPE;
//   int TURBULENT_VISCOSITY_TENSOR;
//   double TURBULENT_VISCOSITY_CONSTANT;
//   double TURBULENT_VISCOSITY_POWER;
//   double TURBULENT_VISCOSITY_SIGMA;
// 
//   /** parameters for VMS */
//   int VMS_LARGE_VELOCITY_SPACE;
//   int VMS_COARSE_MG_SMAGO;
// 
//   // constants in AdaptProjectionSpace
//   double VMS_ADAPT_LOWER;
//   double VMS_ADAPT_MIDDLE;
//   double VMS_ADAPT_UPPER;
//   int VMS_ADAPT_STEPS;
//   int VMS_ADAPT_COMP;
// 
//   double ARTIFICIAL_VISCOSITY_CONSTANT;
//   double ARTIFICIAL_VISCOSITY_POWER;
//   int VMM_COARSE_LEVEL;
//   int VMM_COARSE_SPACE_ORDER;
//   int RFB_SUBMESH_LAYERS;
// 
//   //======================================================================
//   /** parameters for slip with friction and penetration with resistance
//       boundary conditions                                               */
//   //======================================================================
//   double FRICTION_CONSTANT;
//   double FRICTION_POWER;
//   int    FRICTION_TYPE;
//   double FRICTION_U0;
//   double PENETRATION_CONSTANT;
//   double PENETRATION_POWER;
// 
// 
//   //======================================================================
//   // ******** parameters for saddle point system *********//
//   //======================================================================
//   // parameter for nonlinear iteration
//   //TODO Move that parameter to the local "nonlinear" Database!
//   int    SC_NONLIN_ITE_TYPE_SADDLE;
//   
//   //======================================================================
//   /** parameters for individual use in parallel computations */
//   //======================================================================
//   int PAR_P0; //out rank
//   int PAR_P1; // 1 - root takes part in computation; 0 - not
//   int PAR_P2; // mesh partition type: 1 - dual; 0 - nodal
//   int PAR_P3; // 1 - use halocells; 0 - dont
//   int PAR_P4; // 1-redistribution of masters 0-otherwise
//   int PAR_P5;
//   int PAR_P6;
//   int PAR_P7;
//   int PAR_P8;
//   int PAR_P9;
//   int MapperType;
//   int DSType;
//   double PAR_P10;
//   double PAR_P11;
//   double PAR_P12;
//   double PAR_P13;
//   double PAR_P14;
//   double PAR_P15;
//   double PAR_P16;
//   double PAR_P17;
//   double PAR_P18;
//   double PAR_P19;
//   double PAR_P20;
//     
//   //======================================================================
//     
//   #ifdef _MPI
//   /** MPI_Comm for which the computation is started (should not be changed during coomputation)*/
//   MPI_Comm Comm;
//  #endif
// };
// 
// 
// struct TimeDB
// {
//   double CURRENTTIME;
//   double CURRENTTIMESTEPLENGTH;
//   double TIMESTEPLENGTH;
//   double INTERNAL_STARTTIME;
//   double MIN_TIMESTEPLENGTH;
//   double MAX_TIMESTEPLENGTH;
//   double TIMESTEPLENGTH_TOL;
//   int TIMESTEPLENGTH_CONTROL;
//   
//   // control parameter
//   double THETA1;
//   double THETA2;
//   double THETA3;
//   double THETA4;
// 
//   int TIME_DISC;
//   int TIME_DISC2;
// 
//   // start and end time
//   double STARTTIME;
//   double ENDTIME;
// 
//   // write only every n-th time step
//   int STEPS_PER_IMAGE;
//   int STEPS_PER_SNAP;
};

 


/** database of needed refinement, mapping and
    shape descriptors as well as iterators */
class Database
{
  public:
//     /** database of shape descriptors */
//     static TShapeDesc **ShapeDB;
// 
//     /** database of refinement descriptors */
//     static TRefDesc **RefDescDB;
// 
//     /** database of mapper */
//     static TMapper **MapperDB;
// 
//     /** database of iterators */
//     static TIterator **IteratorDB;

    /** general parameters */
   static ParameterDB *ParamDB;
    
//      static std::shared_ptr <ParameterDB> ParamDB;

     
    /** parameter for time discretization */
//     static TimeDB *TimeDB;

  public:
    // Constructors
    /** initialize the database */
    Database();


    // set default parameters

    static void SetDefaultParameters();

    static void WriteParamDB(char *ExecutedFile);

    static void WriteTimeDB();

    static void CheckParameterConsistencyNSE();
};
#endif
