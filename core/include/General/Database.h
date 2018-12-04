// =======================================================================
// Database.h   1.1
//
// Class:       Database
// Purpose:     database of needed refinement, mapping and
//              shape descriptors as well as iterators and parameter database
//
// Author:      Sashikumaar Ganesan 01.12.18
// =======================================================================

class Database;

#ifdef _MPI
#  include "mpi.h"
#endif

#ifdef _HYBRID
  #include <omp.h>
#endif

#ifndef __DATABASE__
#define __DATABASE__

#include <Iterator.h>
#include <RefDesc.h>
#include <Constants.h>
#include <Mapper.h>

struct ParameterDB
{
  int VERSION;

  //======================================================================
  /** parameters data output and input files                            */
  //======================================================================
  
//   vector<char[]> MAPFILE;
  char *OUTFILE;
  char *PODFILE;

  int SAVESOL;
  
  char *SAVE_DATA_FILENAME;
  char *READ_DATA_FILENAME;
  char *SMESHFILE;

  
  //======================================================================
  /** parameters for controling the program */
  //======================================================================
  int PRECOND_LS;
  int WRITE_MATLAB;
  int SAVE_DATA;
  int READ_DATA;
  int READ_GRAPE_FILE;
  int ESTIMATE_ERRORS;
  
  int timeprofiling;  //(time profiling)

  //======================================================================
  /** parameters for setting finite element spaces                      */
  //======================================================================
  int ANSATZ_ORDER;
  int TEST_ORDER;

  int VELOCITY_SPACE;
  int PRESSURE_SPACE;

  //======================================================================
  /** parameters for grid generation                                    */
  //======================================================================

  int OMPNUMTHREADS;

  double DRIFT_X;
  double DRIFT_Y;
  double DRIFT_Z;
  int REFINEMENT;
  int GRID_TYPE;
  int GRID_TYPE_1;
  int GRID_TYPE_2;
  int MESHGEN_ALLOW_EDGE_REF;
  int MESHGEN_REF_QUALITY;

  //======================================================================
  /** parameters for adaptive grid refinement                           */
  //======================================================================
  int ADAPTIVE_REFINEMENT_CRITERION;
  int ERROR_CONTROL;
  int REFINE_STRATEGY;
  int MAX_CELL_LEVEL;
  double REFTOL;
  double COARSETOL;
  double MIN_FRACTION_TO_CHANGE;
  double DECREASE_REFTOL_FACTOR;
  double INCREASE_COARSETOL_FACTOR;
  double FRACTION_OF_ERROR;
  int CONVERT_QUAD_TO_TRI;
  int N_CELL_LAYERS;

  //======================================================================
  /** parameters for setting the discretization                         */
  //======================================================================
  // general
  int DISCTYPE;
  int USE_ISOPARAMETRIC;
  int CELL_MEASURE;
  
  // parameter for non-conforming elements
  int NC_TYPE;
  
  // DISCTYPE for internal space, PBE
  int  INTL_DISCTYPE;
  
  /** upwind methods */
  int UPWIND_ORDER;
  double UPWIND_FLUX_DAMP;
  int UPWIND_APPLICATION;

  // Shishkin meshes
  int SHISHKIN_MESH;
  double SHISHKIN_DIAM;

  /** stabilization with face integrals */
  int WEAK_BC;
  double FACE_SIGMA;
  double WEAK_BC_SIGMA;
  double TAU;
  double TAU2;
  double TAU3;

  /** SUPG or SDFEM method */
  int    SDFEM_TYPE;
  double DELTA0;
  double DELTA1;
  double SDFEM_POWER0;
  int    SDFEM_NORM_B;
  double ADJOINT_FACTOR_4_OMEGA_EQ_0;
  int    CIP_TYPE;
  
  /** parameters for SOLD methods */
  int SOLD_TYPE;
  int SOLD_PARAMETER_TYPE;
  double SOLD_CONST;
  double SOLD_POWER;
  double SOLD_S;
  double SOLD_U0;
  int SOLD_PARAMETER_SCALING;
  double SOLD_PARAMETER_SCALING_FACTOR;

  /** parameters for controlling algebraic flux correction (FEM-FCT schemes) */
  //! 0 - No AFC. 1 - FEM-TVD. Add more here!
  int ALGEBRAIC_FLUX_CORRECTION;
  //! TODO Use and comment!
  int FEM_FCT_LINEAR_TYPE;
  //! TODO Use and comment!
  int FEM_FCT_PRELIMITING;
  //! TODO Use and comment!
  int FEM_FCT_GROUP_FEM;
  //! TODO Use and comment!
  int GROUP_FEM;

  //======================================================================
  /** parameters for vectorial FE (Raviart-Thomas, Brezzi-Douglas-Marini) */
  //======================================================================
  int NORMAL_ORIENTATION_QUAD[4];
  int NORMAL_ORIENTATION_TRIA[3];
  int NORMAL_ORIENTATION_TETRA[4];
  int NORMAL_ORIENTATION_HEXA[6];

  //======================================================================
  /** parameter for local projection stabilization */
  //======================================================================
  int LP_FULL_GRADIENT;
  int LP_STREAMLINE;
  int LP_DIVERGENCE;
  int LP_PRESSURE;
  int LP_CROSSWIND;
  int LP_COEFF_TYPE;

  double LP_FULL_GRADIENT_COEFF;
  double LP_STREAMLINE_COEFF;
  double LP_DIVERGENCE_COEFF;
  double LP_PRESSURE_COEFF;

  double LP_FULL_GRADIENT_EXPONENT;
  double LP_STREAMLINE_EXPONENT;
  double LP_DIVERGENCE_EXPONENT;
  double LP_PRESSURE_EXPONENT;

  int LP_ORDER_DIFFERENCE;
  int LP_FULL_GRADIENT_ORDER_DIFFERENCE;
  int LP_STREAMLINE_ORDER_DIFFERENCE;
  int LP_DIVERGENCE_ORDER_DIFFERENCE;
  int LP_PRESSURE_ORDER_DIFFERENCE;
  
  int LP_CROSSWIND_COEFF_TYPE;
  double LP_CROSSWIND_COEFF;
  double LP_CROSSWIND_EXPONENT; 

  //======================================================================
  /** parameter for a posteriori parameter computation with adjoint problem */
  //======================================================================
  int SOLVE_ADJOINT_PROBLEM;
  int SOLD_ADJOINT;
  int N_STAGES_ADJOINT;
  int SC_NONLIN_ITE_ADJOINT;
  int OPTIMIZATION_ITE_TYPE_ADJOINT;
  int BFGS_VECTORS_ADJOINT;
  int PENALTY_ADJOINT;
  double RELATIVE_DECREASE_ADJOINT;
  double PENALTY_VALUE_AT_ZERO_ADJOINT;
  double PENALTY_SMALLEST_PARAM_FAC_ADJOINT;
  double PENALTY_LARGEST_PARAM_FAC_ADJOINT;
  double WEIGHT_RESIDUAL_L1_ADJOINT;
  double WEIGHT_RESIDUAL_L2_ADJOINT;
  double WEIGHT_GRADIENT_L1_ADJOINT;
  double WEIGHT_GRADIENT_L2_ADJOINT;
  double WEIGHT_STREAM_DER_L1_ADJOINT;
  double WEIGHT_STREAM_DER_ORTHO_L1_ADJOINT;
  double WEIGHT_STREAM_DER_ORTHO_L1_SQRT_ADJOINT;
  double REG_POINT_STREAM_DER_ORTHO_L1_SQRT_ADJOINT;
  double MIN_VAL_ADJOINT;
  double MAX_VAL_ADJOINT;
  double MIN_MAX_EXPONENT_ONE_ADJOINT;
  double MIN_MAX_EXPONENT_TWO_ADJOINT;
  double MIN_MAX_FACTOR_ONE_ADJOINT;
  double MIN_MAX_FACTOR_TWO_ADJOINT;
  double WEIGHT_RESIDUAL_LP_ADJOINT;
  double WEIGHT_RESIDUAL_EXP_LP_ADJOINT;
  double WEIGHT_RESIDUAL_CW_ADJOINT;
  double RESIDUAL_LP_ADJOINT;
  int MIN_MAX_ADJOINT;
  int INITIAL_STEEPEST_DESCENT_ADJOINT;


  /** parameter for superconvergence */
  int SUPERCONVERGENCE_ORDER;

  /** the following parameters are for the membrane REACTOR */
  double REACTOR_P0;
  double REACTOR_P1;
  double REACTOR_P2;
  double REACTOR_P3;
  double REACTOR_P4;
  double REACTOR_P5;
  double REACTOR_P6;
  double REACTOR_P7;
  double REACTOR_P8;
  double REACTOR_P9;
  double REACTOR_P10;
  double REACTOR_P11;
  double REACTOR_P12;
  double REACTOR_P13;
  double REACTOR_P14;
  double REACTOR_P15;
  double REACTOR_P16;
  double REACTOR_P17;
  double REACTOR_P18;
  double REACTOR_P19;
  double REACTOR_P20;
  double REACTOR_P21;
  double REACTOR_P22;
  double REACTOR_P23;
  double REACTOR_P24;
  double REACTOR_P25;
  double REACTOR_P26;
  double REACTOR_P27;
  double REACTOR_P28;
  double REACTOR_P29;
  double REACTOR_P30;

   /** parameter for WENO scheme */
  int WENO_TYPE;
  
  //======================================================================
  /** PARAMETERS FOR STOKES AND NAVIER-STOKES PROBLEMS                  */
  //======================================================================

  /** general parameters */
  double RE_NR; //FIXME This parameter must really be removed from global scope!
  double RA_NR;
  double ROSSBY_NR;
  double START_RE_NR;
  double RE_NR_INCREMENT;
  int FLOW_PROBLEM_TYPE;
  int NSE_NONLINEAR_FORM;
  int NSTYPE;
  int LAPLACETYPE;
  int DEFECT_CORRECTION_TYPE;
  double OSEEN_ZERO_ORDER_COEFF;

  //======================================================================
  /** Parameters for Brinkman problems                  */
  //======================================================================
  int BrinkmanTYPE;
  double VISCOSITY;
  double EFFECTIVE_VISCOSITY;
  double PERMEABILITY;
    
  //======================================================================
  /** Parameter for residual-based equal-order stabilization of Brinkman problems                  */
  //======================================================================
    double equal_order_stab_weight_P1P1;
    double equal_order_stab_weight_P2P2;
    
  //======================================================================
  /** PARAMETERS FOR DARCY PROBLEM                  */
  //======================================================================
  int DARCYTYPE; 
  double SIGMA_PERM;
  //======================================================================
    
  double FR_NR;
  double WB_NR;
  double PR_NR;
  double PE_NR;
  double BI_NR;
  int Axial3D;
  int Axial3DAxis;
  
  /** parameters for LES */
  double FILTER_WIDTH_CONSTANT;
  double FILTER_WIDTH_POWER;
  double GAUSSIAN_GAMMA;
  int CONVOLUTE_SOLUTION;

  /** parameters for turbulent viscosity */
  int TURBULENT_VISCOSITY_TYPE;
  int TURBULENT_VISCOSITY_TENSOR;
  double TURBULENT_VISCOSITY_CONSTANT;
  double TURBULENT_VISCOSITY_POWER;
  double TURBULENT_VISCOSITY_SIGMA;

  /** parameters for VMS */
  int VMS_LARGE_VELOCITY_SPACE;
  int VMS_COARSE_MG_SMAGO;

  // constants in AdaptProjectionSpace
  double VMS_ADAPT_LOWER;
  double VMS_ADAPT_MIDDLE;
  double VMS_ADAPT_UPPER;
  int VMS_ADAPT_STEPS;
  int VMS_ADAPT_COMP;

  double ARTIFICIAL_VISCOSITY_CONSTANT;
  double ARTIFICIAL_VISCOSITY_POWER;
  int VMM_COARSE_LEVEL;
  int VMM_COARSE_SPACE_ORDER;
  int RFB_SUBMESH_LAYERS;

  //======================================================================
  /** parameters for slip with friction and penetration with resistance
      boundary conditions                                               */
  //======================================================================
  double FRICTION_CONSTANT;
  double FRICTION_POWER;
  int    FRICTION_TYPE;
  double FRICTION_U0;
  double PENETRATION_CONSTANT;
  double PENETRATION_POWER;

  //======================================================================
  /** parameters for div-div stabilization */
  //======================================================================
  int    DIV_DIV_STAB_TYPE;
  double DIV_DIV_STAB_C1;
  double DIV_DIV_STAB_C2;

  //======================================================================
  // ******** parameters for saddle point system *********//
  //======================================================================
  // parameter for nonlinear iteration
  //TODO Move that parameter to the local "nonlinear" Database!
  int    SC_NONLIN_ITE_TYPE_SADDLE;
  

  double CHAR_L0;
  double D_VISCOSITY;
  double SURF_TENSION;
  double IMPACT_ANGLE;
  double Area;
  //======================================================================
  /** the following parameters are for individual use */
  //======================================================================
  double P0;
  double P1;
  double P2;
  double P3;
  double P4;
  double P5;
  double P6;
  double P7;
  double P8;
  double P9;
  double P10;
  double P11;
  double P12;
  double P13;
  double P14;
  double P15;
  //======================================================================
  /** PARAMETERS FOR APPLICATIONS */
  //======================================================================

  //======================================================================
  /** parameters for free surface calculation */
  //======================================================================
  int FS_MAGNETLAW;                               // 0 = Langevin, 1 = Vislovich
  double FS_L;                                    // characteristic length
  double FS_U;                                    // characteristic velocity
  double FS_T;                                    // characteristic time: T = L/U

  double FS_ETA;                                  // dynamic viscosity
  double FS_RHO;                                  // fluid density
  double FS_ALPHA;                                // coefficient of surface tension
  double FS_G;                                    // acceleration due to gravity

  double FS_MS;                                   // saturation magnetisation
  double FS_CHI0;                                 // initial susceptibility

  double FS_HM;                                   // mean field strength
  double FS_DELTA_H;                              // amplitude for field oscillations
  double FS_F;                                    // oscillation frequency

  double FS_H0;                                   // characteristic field strength
  double FS_H1;                                   // field inside for plane interface
  double FS_H2;                                   // field outside for plane interface

  double FS_LH;                                   // layer height
  double FS_GAMMA;                                // Langevin parameter
  double FS_HT;                                   // parameter for Vislovich approximation

  double FS_WE;                                   // Weber number = Re*Ca

  char *FS_INNAME;                                // file name for reading surface position
  char *FS_OUTNAME;                               // file name for writing surface position

  int FS_WRITE;                                   // != 0 => write free surface
  int FS_READ;                                    // != 0 => read free surface
 
  double HEAT_TANGENTIAL_STRESS_FACTOR;           // C_1/\sigma_sa
  double HEAT_SOLID_SURFACE_FACTOR;               // eps = (1/PE_NR)HEAT_SOLID_SURFACE_FACTOR
  double EQ_CONTACT_ANGLE;                        // equilibrium contact angle
  double AD_CONTACT_ANGLE;                        // advancing contact angle 
  double RE_CONTACT_ANGLE;                        // receding contact angle 
  double DY_CONTACT_ANGLE;                        // dynamic contact angle 
  int CONTACT_ANGLE_TYPE;                         // type of contact angle   
  
  //======================================================================
  /** parameters for turbulent channel flow */
  //======================================================================
  int CHANNEL_STATISTICS2_WITH_MODEL;

  //======================================================================
  /** parameters for turbulent flow around a squared cylinder */
  //======================================================================
  double CYLINDER_22000_YPLUS_SIDES;
  double CYLINDER_22000_YPLUS_FRONT;
  double CYLINDER_22000_YPLUS_BACK;
  
  // TODO CB All these parameters starting with BULK are used for one
  // single example. Let's hardcode them there and remove them from global
  // scope. Other parameter groups should experience the same treatment
  // in time.
  //======================================================================
  /** parameters for BULK computations */
  //======================================================================
  int BULK_REACTION_DISC;
  int BULK_PB_DISC;
  int BULK_PB_DISC_STAB;
  int BULK_PB_DISC_FCT_GROUP;
  int BULK_COUPLING;
  int BULK_GROWTH_RATE;
  int BULK_REACTION_MASS_LUMPING;
  int BULK_METHODS_OF_MOMENTS;
  int BULK_MOM_DISC;
  int BULK_SOLD_PARAMETER_TYPE;
  int N_CELL_LAYERS_PSD;
  int N_CELL_LAYERS_PSD_2;
  int OUTPUT_NODE_LAYER_PSD;
  double BULK_REACTION_C_CUT;

  double BULK_l_infty;
  double BULK_u_infty;
  double BULK_c_infty;
  double BULK_c_C_infty_sat;
  double BULK_c_C_infty;
  double BULK_f_infty;

  double BULK_density;
  double BULK_dynamic_viscosity;

  double BULK_C_g;
  double BULK_C_nuc;
  double BULK_C_sat;
  double BULK_C_2;
  double BULK_D_A;
  double BULK_D_P_0;
  double BULK_D_P_MAX;
  double BULK_k_g;
  double BULK_k_r;
  double BULK_k_nuc;
  double BULK_D_P_MIN;

  //======================================================================
  /** parameters for shear slip mesh update method computations */
  //======================================================================
  double SSMUM_MP_X;
  double SSMUM_MP_Y;
  double SSMUM_INNER_RADIUS;
  double SSMUM_OUTER_RADIUS;
  double SSMUM_ROT_PER_SECOND;
  double SSMUM_ANGLE;
  int SSMUM_MAX_CELLS_LAYERS;  
  int SSMUM_INTERPOLATION;

  int PB_DISC_TYPE;
  int PB_TIME_DISC;

  //======================================================================
  /** internal parameters
  cannot be set in the readin file
  are used as global variables */
  //======================================================================
  int    INTERNAL_PROBLEM_LINEAR;
  int    INTERNAL_PROJECT_PRESSURE;
  int    INTERNAL_PRESSURE_SPACE;
  int    INTERNAL_SLIP_WITH_FRICTION;
  int    INTERNAL_SLIP_WITH_FRICTION_IDENTITY;
  int    INPUT_QUAD_RULE;
  int    INTERNAL_QUAD_HEXA;
  int    INTERNAL_QUAD_TETRA;
  int    INTERNAL_QUAD_QUAD;
  int    INTERNAL_QUAD_TRIA;
  int    INTERNAL_QUAD_RULE;
  int    INTERNAL_LOCAL_DOF;
  int    INTERNAL_PERIODIC_IDENTITY;
  int    INTERNAL_PROBLEM_IDENTITY;
  int    INTERNAL_LEVEL;
  int    INTERNAL_CONVECTION_EQ_VELOFIELD;
  int    INTERNAL_STEADY_STATE_MATRICES_OR_RHS;
  int    INTERNAL_AMG_SOLVES;
  double INTERNAL_AMG_PREPARE_TIME;
  int    INTERNAL_GMRES_INFO;
  int    INTERNAL_POLYNOMIAL_DEGREE;
  int    INTERNAL_MESH_CELL_TYPE;
  double INTERNAL_BULK_MEAN;
  double INTERNAL_BULK_SIMULATION;
  double INTERNAL_VERTEX_X[8];
  double INTERNAL_VERTEX_Y[8];
  double INTERNAL_VERTEX_Z[8];
  double INTERNAL_HK_CONVECTION;
  int    INTERNAL_MEAN_COMPUTATION;
  int    INTERNAL_MOMENT;
  int    INTERNAL_LINEAR_SCHEME;
  int    INTERNAL_SOLD_ACTIVE;
  int    INTERNAL_UMFPACK_FLAG;
  int    INTERNAL_SORT_AMG;
  int    INTERNAL_FESPACE_CONSTRUCT; 
  int    INTERNAL_DO_NOT_RESPECT_DIRICHLET_BC; 
  
  double INTERNAL_COERCIVITY;
  double *INTERNAL_P1_Array;
  double *INTERNAL_WEIGHT_Array;
  int    *INTERNAL_INDICATOR_Array;
  int    INTERNAL_FACE_INTEGRALS;
  int    INTERNAL_NO_ESTIMATE_DIRICHLET_CELLS;
  int    INTERNAL_WRONG_NEUMANN_CHECKED;
  double INTERNAL_BFGS_RESTART_ADJOINT;
  int    INTERNAL_ARRAY_LENGTH;
  int    INTERNAL_CELL;
  int    INTERNAL_OUTFLOW_BOUNDARY[10];
  double INTERNAL_WEIGHT_SUPG_ADJOINT;
  double INTERNAL_WEIGHT_SOLD_ADJOINT;
  int    INTERNAL_NEW_MATRICES_B;
  int    INTERNAL_FULL_MATRIX_STRUCTURE;
  int    INTERNAL_DISC_FLAG;
  int    INTERNAL_START_PARAM;
  
  // parameter for tetgen
  double TETGEN_QUALITY;
  double TETGEN_VOLUMEN;
  int 	 TETGEN_STEINER;

  //======================================================================
  /** parameters for individual use in parallel computations */
  //======================================================================
  int Par_P0; //out rank
  int Par_P1; // 1 - root takes part in computation; 0 - not
  int Par_P2; // mesh partition type: 1 - dual; 0 - nodal
  int Par_P3; // 1 - use halocells; 0 - dont
  int Par_P4; // 1-redistribution of masters 0-otherwise
  int Par_P5;
  int Par_P6;
  int Par_P7;
  int Par_P8;
  int Par_P9;
  int MapperType;
  int DSType;
  double Par_P10;
  double Par_P11;
  double Par_P12;
  double Par_P13;
  double Par_P14;
  double Par_P15;
  double Par_P16;
  double Par_P17;
  double Par_P18;
  double Par_P19;
  double Par_P20;

  //======================================================================
  /** parameters for ROM */
  //======================================================================
  int WRITE_SNAPSHOTS;
  int DO_ROM;
  int DO_ROM_P;
  int RANK_OF_BASIS;
  int RANK_OF_BASIS_P;
  int POD_INNER_PRODUCT;
  int POD_INNER_PRODUCT_P;
  int BUILD_PODFILE;
  int POD_FLUCT_FIELD;
  int POD_FLUCT_FIELD_P;
  int P_ROM_METHOD;
  
  //======================================================================
  /** parameters for projection methods (NSE) */
  //======================================================================
  int PROJECTION_METHOD;
  
  //======================================================================
  /** parameters for population balance computations */
  //======================================================================
  int PBE_P0;
  int PBE_P1;
  int PBE_P2;
  int PBE_P3;
  int PBE_P4;
  int PBE_P5;
  int PBE_P6;
  int PBE_P7;
  int PBE_P8;
  int PBE_P9;

  //======================================================================
  /** parameters for DG computations */
  //======================================================================
  double DG_P0;
  double DG_P1;
  double DG_P2;
  double DG_P3;
  double DG_P4;
  double DG_P5;
  double DG_P6;
  double DG_P7;
  double DG_P8;
  double DG_P9;
  
  //======================================================================
  /** parameters for moving domains */
  //======================================================================
  
  int MOVING_BOUNDARY;
  
  int DEPENDENT_BASIS;
  int DEPENDENT_BASIS_Q1;
  int DEPENDENT_BASIS_Q2;
    
  //======================================================================
  /** parameters for weakly imposing boundary/interface conditions for Brinkman problems  */
  //======================================================================
    // number of boundary components with neumann conditions
    int n_neumann_boundary;
    // ID's of boundary components with neumann conditions
    std::vector<int> neumann_boundary_id;
    // factor for boundary integrals
    std::vector<double> neumann_boundary_value;
    
    int n_g_v_boundary;
    std::vector<int> g_v_boundary_id;
    std::vector<double> g_v_boundary_value;
    
    int n_unvn_boundary;
    std::vector<int> unvn_boundary_id;
    std::vector<double> unvn_boundary_value;
    
    int n_graduvn_boundary;
    std::vector<int> graduvn_boundary_id;
    std::vector<double> graduvn_boundary_value;
    
    int n_gradunv_boundary;
    std::vector<int> gradunv_boundary_id;
    std::vector<double> gradunv_boundary_value;
    
    int n_u_v_boundary;
    std::vector<int> u_v_boundary_id;
    std::vector<double> u_v_boundary_value;
    
    int n_p_v_n_boundary;
    std::vector<int> p_v_n_boundary_id;
    std::vector<double> p_v_n_boundary_value;
    
    // Nitsche Combi - weak Dirichlet
    int n_nitsche_boundary ;
    std::vector<int> nitsche_boundary_id;
    std::vector<double> nitsche_penalty;
    
  //======================================================================
    
  #ifdef _MPI
  /** MPI_Comm for which the computation is started (should not be changed during coomputation)*/
  MPI_Comm Comm;
 #endif
  
  ~TParaDB();
};

typedef struct TParaDB TParamDB;

struct TTimDB
{
  double CURRENTTIME;
  double CURRENTTIMESTEPLENGTH;
  double TIMESTEPLENGTH;
  double INTERNAL_STARTTIME;
  double MIN_TIMESTEPLENGTH;
  double MAX_TIMESTEPLENGTH;
  double TIMESTEPLENGTH_TOL;
  int TIMESTEPLENGTH_CONTROL;
  int TIMESTEPLENGTH_CONTROLLER;  // mlh
  double TIMESTEPLENGTH_PARA_KK_I;
  double TIMESTEPLENGTH_PARA_KK_P;
  double TIMESTEPLENGTH_PARA_KK_E;
  double TIMESTEPLENGTH_PARA_KK_R;
  double TIMESTEPLENGTH_PARA_KK_D;
  double TIMESTEPLENGTH_PARA_FAC;
  double TIMESTEPLENGTH_PARA_FAC_MAX;
  double TIMESTEPLENGTH_PARA_FAC_MIN;
  double TIMESTEPLENGTH_PARA_TOL;
  double TIMESTEPLENGTH_PARA_ATOL;
  double TIMESTEPLENGTH_PARA_RTOL;
  int FIRST_SSC_STEP;
  int RESET_CURRENTTIME;
  double RESET_CURRENTTIME_STARTTIME;
  double STEADY_STATE_TOL;
  double SCALE_DIVERGENCE_CONSTRAINT;

  int CONTROL;
  double CONTROL_ALPHA;
  double CONTROL_BETA;
  double CONTROL_GAMMA;
  double CONTROL_SAFTY;
  double CONTROL_MAXSCALE;
  double CONTROL_MINSCALE;
  
  // control parameter
  double THETA1;
  double THETA2;
  double THETA3;
  double THETA4;

  int TIME_DISC;
  int TIME_DISC2;

  // start and end time
  double STARTTIME;
  double ENDTIME;
  double EXTRAPOLATE_WEIGHT;
  double EXTRAPOLATE_STEPS;
  int    EXTRAPOLATE_PRESSURE;
  // between time steps
  int    EXTRAPOLATE_VELOCITY;

  // parameter for individual use
  double T0;
  double T1;
  double T2;
  double T3;
  double T4;
  double T5;
  double T6;
  double T7;
  double T8;
  double T9;

  // write only every n-th time step
  int STEPS_PER_IMAGE;
  int STEPS_PER_SNAP;

  // parameters for Rosenbrock methods
  int RB_TYPE;
  int RB_TYPE2;
  int RB_SSC;
  double RB_SSC_TOL;
  double RB_SSC_ALPHA;
  double RB_SSC_ALPHA_MAX;
  double RB_SSC_ALPHA_MIN;
  double RB_SSC_MAX_ERROR;

  int RB_APPROX_J;
  int RB_APPROX_C;
  int RB_APPROX_STEPS;

  double RB_GAMMA_I;
  double RB_GAMMA_II;
  double RB_ALPHA_I;
  double RB_SIGMA_I;
  double RB_A_IJ[10];
  double RB_C_IJ[10];
  double RB_S_IJ[10];
  double RB_M_I;
  double RB_MS_I;
  
  // parameters for higher order Galerkin-type methods
  int INTERNAL_SYSTEMSIZE;  
  double *INTERNAL_ALPHA;
  double *INTERNAL_BETA;
  double *VALUE_AT_ONE; 
  double *VAL_AT_QUAD_POINTS;
  double *DER_AT_QUAD_POINTS;
  double *CORR_AT_QUAD_POINTS;  
  double *DER_CORR_AT_QUAD_POINTS;
  double *DER_AT_START;
  double *DER_AT_ONE;
  double *DER_COR_AT_ONE;
  double NORMW;
  double *ZETA;
  double *WEIGHTS;
  int N_QUADPOINTS;
  int N_DEGREES;
  double *ALPHA0;
  double *BETA0;
  double *GAMMA0;
  double *CORRECTION;
  double *POINTS;

  double RK_A[5][5];
  double RK_c[5];
  double RK_b[5];
  double RK_e[5];
  int RK_ord;   // Ordnung des RK-Verfahrens    mlh
  int RK_ord_e;   // Ordnung des eingebetteten RK-Verfahrens  mlh
};

typedef struct TTimDB TTimeDB;

/** database of needed refinement, mapping and
    shape descriptors as well as iterators */
class TDatabase
{
  public:
    /** database of shape descriptors */
    static TShapeDesc **ShapeDB;

    /** database of refinement descriptors */
    static TRefDesc **RefDescDB;

    /** database of mapper */
    static TMapper **MapperDB;

    /** database of iterators */
    static TIterator **IteratorDB;

    /** general parameters */
    static TParamDB *ParamDB;

    /** parameter for time discretization */
    static TTimeDB *TimeDB;

  public:
    // Constructors
    /** initialize the database */
    TDatabase();
    
    ~TDatabase();

    // Methods
#ifdef __MORTAR__
    /** add descriptor for mortar refinement with base edge 0 */
    void AddMortar0(int Mortar_Ni, int N);
    /** add descriptor for mortar refinement with base edge 1 */
    void AddMortar1(int Mortar_Ni, int N);
#endif

    // set default parameters

    static void SetDefaultParameters();

    static void WriteParamDB(char *ExecutedFile);

    static void WriteTimeDB();

    static void CheckParameterConsistencyNSE();
};
#endif
