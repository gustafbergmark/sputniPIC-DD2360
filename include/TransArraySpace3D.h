#ifndef TRANSARRAYSPACE3D_H
#define TRANSARRAYSPACE3D_H

#include "PrecisionTypes.h"

/** method to convert a 1D field in a 3D field not considering guard cells*/
void solver2phys(FPpart*** vectPhys, FPpart* vectSolver, int nx, int ny, int nz);
/** method to convert a 1D field in a 3D field not considering guard cells*/
void solver2phys(FPpart*** vectPhys1, FPpart*** vectPhys2, FPpart*** vectPhys3, FPpart* vectSolver, int nx, int ny, int nz);


/** method to convert a 3D field in a 1D field not considering guard cells*/
void phys2solver(FPpart* vectSolver, FPpart*** vectPhys, int nx, int ny, int nz);
/** method to convert a 3D field in a 1D field not considering guard cells*/
void phys2solver(FPpart* vectSolver, FPpart*** vectPhys1, FPpart*** vectPhys2, FPpart*** vectPhys3, int nx, int ny, int nz);

#endif
