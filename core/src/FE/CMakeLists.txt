

include_directories("${CMAKE_SOURCE_DIR}/include/FE")

#  GLOB_RECURSE will generate a list similar to the regular GLOB, 
# except it will traverse all the subdirectories of the matched directory and match the files
# list(APPEND_RECURSE FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/*.C")

# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ADICell.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ADICell1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ADISystem.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ADISystem1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Assemble2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/AuxParam2D.C") 
list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/BaseFunct1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/BaseFunct2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Bcgs.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Blas1.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Blas2.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Bulk.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Cg.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ConvDiff.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Convolution.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/DirectSolver.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/DiscreteForm2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FE1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FE2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FE2DMapper.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FE2DMapper1Reg.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEDatabase2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEDesc1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEDesc2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEFunction1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEFunction2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEM_TVD_FCT.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FESpace.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FESpace1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FESpace2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FgmresIte.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FixedPointIte.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/HNDesc.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/HangingNode.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ItMethod.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/JacobiIte.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/LinAlg.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/LineAffin.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/LocalProjection.C") 

# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Matrix.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MultiGridIte.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MultiGridScaIte.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE_MGLevel.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE_MGLevel1.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE_MGLevel2.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE_MGLevel3.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE_MGLevel4.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE_MGLevel5.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE_MGLevel14.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE_MultiGrid.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NodalFunctional1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NodalFunctional2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Output2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/PardisoSolver.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/QuadAffin.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/QuadIsoparametric.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/QuadBilinear.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/RationalLES.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/RefTrans1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/RefTrans2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Solver.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareMatrix.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareMatrix1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareMatrix2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareStructure.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareStructure1D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareStructure2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SSORIte.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Structure.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TimeDiscRout.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TriaAffin.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TriaIsoparametric.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/VMS.C") 

if("${AParMooN_GEO}" STREQUAL "2D")

# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Assemble2D_edge_Oseen.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Bulk_2d3d.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/CD2DErrorEstimator.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ConvDiff2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Darcy2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Drop.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEVectFunct2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FreeSurface2D.C") 
# # list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/LocalAssembling2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MGComponents2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MGLevel2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MovingNavierStokes.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MultiGrid2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Matrix2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE2DErrorEstimator.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE2D_AxialSymm3D_FixPo.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE2D_EquOrd_FixPo.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE2D_FixPo.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE2D_FixPoSkew.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE2D_FixPoRot.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE2D_Friction_FixPo.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE2D_Newton.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/PDAE_Index2D_2.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/RFB.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/RKV_FDM.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareMatrixNSE2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SSMUM.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/StructureNSE2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Structure2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Superconvergence2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TCD2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TimeConvDiff2D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TNSE2D_FixPo.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TNSE2D_FixPoRot.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TNSE2D_FixPo_SSMUM.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Upwind.C") 

elseif("${AParMooN_GEO}" STREQUAL "3D")

# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ALE_3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Assemble3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Aux2D3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/AuxParam3D.C")  
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/BaseFunct3D.C")  
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Bulk_3d4d.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/ConvDiff3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/DiscreteForm3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FE3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FE3DMapper.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FE3DMapper1Reg.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEDatabase3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEDesc3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEFunction3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FESpace3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FEVectFunct3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/FreeSurface3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/HexaAffin.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/HexaIsoparametric.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/HexaTrilinear.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MGComponents3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MGLevel3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Matrix3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/MultiGrid3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE3D_FixPo.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE3D_FixPoSkew.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE3D_Friction_FixPo.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NSE3D_Newton.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/NodalFunctional3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Output3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Queue.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareMatrix3D.C")
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/SquareStructure3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Structure3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Superconvergence3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TCD3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TNSE3D_FixPo.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TNSE3D_Newton.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/RefTrans3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/RFB.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TetraAffin.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/TetraIsoparametric.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Upwind3D.C") 
# list(APPEND FE_SOURCES "${PROJECT_SOURCE_DIR}/core/src/FE/Urea_3d4d.C") 
endif("${AParMooN_GEO}" STREQUAL "2D")


add_library(fe STATIC ${FE_SOURCES})


