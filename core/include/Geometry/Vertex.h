// =======================================================================
// Vertex.h     1.1  
// 
// Class:       vertex
// Purpose:     a vertex in a mesh
//
// Author:      Sashikumaar Ganesan 01.12.18
// =======================================================================

#ifndef __VERTEX__
#define __VERTEX__

#include <ParMooN_IO.h>
#include <Parameters.h>

/** @brief a vertex in a mesh**/
class Vertex
{
  protected:
    /** @brief coordinates**/
    double X, Y;
#ifdef __3D__
      /** @brief third coordinate**/
      double Z;
#endif

    /** an integer for storing clipboard information*/
    int ClipBoard;

#ifdef _MPI

    /** @brief Number of cells that containing this vertex **/
    /** @brief Number of dependent cells in parallel **/
    int N_Cells;

    /** @brief array of cells (instances of the cell class) containg this vertex **/
    TBaseCell **Cells;

    /** @brief marking this vertex as subdomain vertex**/
    bool SubDomainVert;

    /** @brief marking this vertex as cross vertex**/
    bool CrossVert;

    /** @brief number of ranks (SubDomains) containing this vertex**/
    int N_SubDomains;

    /** @brief ranks (SubDomains) that contain this vertex**/
    int *SubDomain_Ranks;

    /** @brief Global cell numbers of the neib cells that incident with this vertex**/
    int *SubDomainGlobalCellNo;

    /** @brief local index of this vertex in the neib cell**/
    int *SubDomainLocVertNo;

    /** @brief number of Cross neib cells that contain this vertex**/
    int N_CrossNeibCells;  
    
    /** @brief boundary ID of this vertex**/    
    int Bd_id; 
    
#endif
    
    /** @brief marking this vertex as boundary vertex**/
    bool BoundVert;   
    
  public:
    // Constructors

#ifdef __3D__
      /** @brief 3D vertex constructor**/
      TVertex(double initX, double initY, double initZ);
#else
      /**  @brief 2D vertex constructor**/ 
      TVertex(double initX, double initY);
#endif

    // Destructor
    ~TVertex();

    // Methods
    // set coordinates
#ifdef __3D__
      /** @brief set coordinates in 3D**/
      void SetCoords(double initX, double initY, double initZ);
#else
      /** @brief set coordinate in 2D**/
      void SetCoords(double initX, double initY);
#endif

    /** @brief return the x coordinate**/
    double GetX() const
    { return X; }
    /** @brief return the y coordinate**/
    double GetY() const
    { return Y; }
#ifdef __3D__
      /** @brief return the z coordinate (3D)**/
      double GetZ() const
      { return Z; }
      
      /** @brief return all three coordinates**/
      void GetCoords(double& x, double& y, double& z) const
      {
        x = X;
        y = Y;
        z = Z;
      }
#else
      /** @brief return all two coordinates**/
      void GetCoords(double& x, double& y) const
      {
        x = X;
        y = Y;
      }
#endif

    /** write some information of the vertex in stream s**/
    friend std::ostream& operator << (std::ostream& s, Vertex *v);

    /** @brief set value in ClipBoard**/
    void SetClipBoard(int value)
    { ClipBoard=value; }
    
    /** @brief get value from ClipBoard**/
    int GetClipBoard() const
    { return ClipBoard; }

    
     /** @brief set as boundary vertex**/
     void SetAsBoundVert()
      { BoundVert=TRUE; }    
     
     
     /** @brief is it a boundary vertex?**/    
     bool IsBoundVert() const
     { return BoundVert; }     
    
#ifdef _MPI

    /** @brief set cells (dependent) associated with this vertex**/
    void SetVertexCells(int n_Cells, BaseCell **cells);

    void SetSubDomainInfo(int n_SubDomains, int *subDomain_Ranks, int *subDomainGlobalCellNo, 
                          int *subDomainLocVertNo);

    void AddCrossNeib(int Neib_ID);

    void SetAsSubDomainVert()
     { SubDomainVert = TRUE; }

     bool IsSubDomainVert()
     { return SubDomainVert; }

     void SetAsCrossVert()
     {  CrossVert = TRUE; }
     
     bool IsCrossVert()
     { return CrossVert; }

     void GetCrossNeibs(int &n_VertCrossNeibs, int *&vertCrossNeibs) 
      {
       n_VertCrossNeibs = N_CrossNeibCells;
       vertCrossNeibs = SubDomain_Ranks;
      }

     void GetCrossNeibsInfo(int &N_NeibCells, int *&NeibCellRank, 
                            int *&GlobalNo, int *&LocVertNo)
      {
       N_NeibCells = N_CrossNeibCells;
       NeibCellRank = SubDomain_Ranks;
       GlobalNo = SubDomainGlobalCellNo;
       LocVertNo = SubDomainLocVertNo;
      }

     void GetNeibs(int &n_Neibs, BaseCell **&neighbs)
      {
       n_Neibs = N_Cells;
       neighbs = Cells;
      }
      
      int GetNNeibs()
      {  return N_Cells; } 
#ifdef _MPI
      void set_Bd_id(int key)
      {  Bd_id = key; }
      
      int get_Bd_id()
      { return Bd_id; }
#endif    
#endif
};

#endif
