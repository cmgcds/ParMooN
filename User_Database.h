// =======================================================================
// Database.h   1.1
//
// Class:      User Database, to define all global variables
// Purpose:    database of needed Stabilization
//
// Author:      Sashikumaar Ganesan 04.12.18
// =======================================================================

#if defined(_MPI) || defined(_SMPI)
#  include "mpi.h"
#endif

#ifdef _HYBRID
  #include <omp.h>
#endif

#ifndef __USERDATABASE__
#define __USERDATABASE__

#include <Iterator.h>
#include <RefDesc.h>
#include <Constants.h>

#include <Domain.h>

class UserDatabase;


struct UserParamDB
{
    
    
  // indicate what kind of problem is solved (T means time dependent)
  //  0: not set
  //  1: CD
  //  2: TCD
  //  3: Stokes
  //  4: TStokes
  //  5: NSE
  //  6: TNSE
  int PROBLEM_TYPE;    
 
  char *PODFILE;
  char *BNDFILE;
  char *GEOFILE_INTL;
  char *BNDFILE_INTL;
  char *MAPFILE;
  
  //======================================================================
  /** PARAMETERS FOR APPLICATIONS */
  //======================================================================

  int TENSOR_TYPE;                        // conformation stress tensor or deformation tensor in DEVSS
  int FREE_SURFACE_FLOW;                 // Impinging droplet (free surface flow)
  int TWO_PHASE_FLOW;                    // Two Phase flow
  int PHASE1_TYPE;                      // 1 - Newtonian, 2 - Oldroyd, 3- Giesekus
  int PHASE2_TYPE;                      // 1 - Newtonian, 2 - Oldroyd, 3- Giesekus
  
  //======================================================================
  /** parameters for free surface calculation */
  //======================================================================
  bool INTERFACE_FLOW;                             // free surface or Interface flow or not
  
  double HEAT_TANGENTIAL_STRESS_FACTOR;           // C_1/\sigma_sa
  double HEAT_SOLID_SURFACE_FACTOR;               // eps = (1/PE_NR)HEAT_SOLID_SURFACE_FACTOR
  double EQ_CONTACT_ANGLE;                        // equilibrium contact angle
  double AD_CONTACT_ANGLE;                        // advancing contact angle 
  double RE_CONTACT_ANGLE;                        // receding contact angle 
  double DY_CONTACT_ANGLE;                        // dynamic contact angle 
  int CONTACT_ANGLE_TYPE;                         // type of contact angle 
  
  
  int  MESH_SLIP_WITH_FRICTION;  
  
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

  
  
}
