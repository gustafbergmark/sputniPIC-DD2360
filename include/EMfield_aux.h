#ifndef EMFIELD_AUX_H
#define EMFIELD_AUX_H

#include "Alloc.h"
#include "Grid.h"

/** structure with auxiliary field quantities like potentials or quantities defined at centers  */
struct EMfield_aux {
    
    
    /* Electrostatic potential defined on central points*/
    FPpart*** Phi;
    FPpart* Phi_flat;

    /* Electric field at time theta */
    FPpart*** Exth;
    FPpart* Exth_flat;

    FPpart*** Eyth;
    FPpart* Eyth_flat;

    FPpart*** Ezth;
    FPpart* Ezth_flat;

    /* Magnetic field defined on nodes: last index is component - Centers */
    FPpart*** Bxc;
    FPpart* Bxc_flat;
    FPpart*** Byc;
    FPpart* Byc_flat;
    FPpart*** Bzc;
    FPpart* Bzc_flat;
    
};

/** allocate electric and magnetic field */
void field_aux_allocate(struct grid*, struct EMfield_aux*);

/** deallocate */
void field_aux_deallocate(struct grid*, struct EMfield_aux*);

#endif
