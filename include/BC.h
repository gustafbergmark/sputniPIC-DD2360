#ifndef BC_H
#define BC_H

#include "InterpDensSpecies.h"
#include "PrecisionTypes.h"
#include "Parameters.h"
#include "Grid.h"

/** Put Boundary Conditions on Boundaries */


//////////
// POPULATE GHOST CELL ON NODES
//////////


/** Apply BC to scalar interp quantity defined on nodes - Interpolation quantity */
void applyBCscalarDensN(FPinterp*** scalarN, grid* grd, parameters* param);

/** Apply BC to scalar interp quantity defined on nodes - Interpolation quantity */
void applyBCscalarFieldN(FPpart*** scalarN, grid* grd, parameters* param);


///////// USE THIS TO IMPOSE BC TO ELECTRIC FIELD
///////// NOW THIS IS FIXED TO ZERO

/** Apply BC to scalar interp quantity defined on nodes - Interpolation quantity */
void applyBCscalarFieldNzero(FPpart*** scalarN, grid* grd, parameters* param);

///////////////
////
////    add Densities
////
////
///////////////

// apply boundary conditions to species interpolated densities
void applyBCids(struct interpDensSpecies* ids, struct grid* grd, struct parameters* param);


//////////
// POPULATE GHOST CELL ON CELL CENTERS
//////////


/** Apply BC to scalar interp quantity defined on nodes - Interpolation quantity */
void applyBCscalarDensC(FPinterp*** scalarC, grid* grd, parameters* param);

/** Apply BC to scalar field quantity defined on center - Interpolation quantity */
void applyBCscalarFieldC(FPpart*** scalarC, grid* grd, parameters* param);

/** Apply BC to scalar field quantity defined on nodes - Interpolation quantity */
// set to zero ghost cell
void applyBCscalarFieldCzero(FPpart*** scalarC, grid* grd, parameters* param);

#endif
