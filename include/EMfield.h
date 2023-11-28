#ifndef EMFIELD_H
#define EMFIELD_H

#include "Alloc.h"
#include "Grid.h"


/** structure with field information */
struct EMfield {
    // field arrays: 4D arrays
    
    /* Electric field defined on nodes: last index is component */
    FPpart*** Ex;
    FPpart* Ex_flat;
    FPpart*** Ey;
    FPpart* Ey_flat;
    FPpart*** Ez;
    FPpart* Ez_flat;
    /* Magnetic field defined on nodes: last index is component */
    FPpart*** Bxn;
    FPpart* Bxn_flat;
    FPpart*** Byn;
    FPpart* Byn_flat;
    FPpart*** Bzn;
    FPpart* Bzn_flat;
    
    
};

/** allocate electric and magnetic field */
void field_allocate(struct grid*, struct EMfield*);

/** deallocate electric and magnetic field */
void field_deallocate(struct grid*, struct EMfield*);

#endif
