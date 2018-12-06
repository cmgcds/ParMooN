// ======================================================================
// Sine problem
// ======================================================================

void ExampleFile()
{
  OutPut("Example: SineLaplace.h" << endl) ;
}

// exact solution
void Exact(double x, double y, double *values)
{
  values[0] = sin(Pi*x)*sin(Pi*y);
  values[1] = Pi*cos(Pi*x)*sin(Pi*y);
  values[2] = Pi*sin(Pi*x)*cos(Pi*y);
  values[3] = -2*Pi*Pi*sin(Pi*x)*sin(Pi*y);
}

// kind of boundary condition (for FE space needed)
void BoundCondition(int BdComp, double t, BoundCond &cond)
{
  if(BdComp==1)
    cond = NEUMANN;
  else
    cond = DIRICHLET;
}

// value of boundary condition
void BoundValue(int BdComp, double Param, double &value)
{
  static double eps=1/TDatabase::ParamDB->PE_NR;

  if(BdComp==1)
    value = -eps*Pi*sin(Pi*Param);
  else
    value = 0;
}

void BilinearCoeffs(int n_points, vector<double> x, vector<double> y,
                    vector< vector<double> >parameters, vector< vector<double> >coeffs)
{
  static double eps=1/TDatabase::ParamDB->PE_NR;
  int i;
  vector<double> coeff;

  for(i=0;i<n_points;i++)
  {
    coeff = coeffs[i];
    //double *param = parameters[i];

    coeff[0] = eps;
    coeff[1] = 0;
    coeff[2] = 0;
    coeff[3] = 0;

    coeff[4] = (2*Pi*Pi*eps)*sin(Pi*x[i])*sin(Pi*y[i]);
  }
}

 
