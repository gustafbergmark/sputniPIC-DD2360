#include <iostream>
#include "Grid.h"
#include "Particles.h"
#include "EMfield.h"
#include "Parameters.h"
#include <cstring>

void get_grid(struct grid* gpu_grid, struct grid* cpu_grid, struct grid* gpu_grid_ptr);
void transfer_grid(struct grid* cpu_grid, struct grid* gpu_grid, struct grid** gpu_grid_ptr);

void transfer_param(struct parameters* param, struct parameters** gpu_param_ptr);

void transfer_field(struct EMfield* cpu_field, struct EMfield* gpu_field, struct EMfield** gpu_field_ptr, size_t count);
void get_field(struct EMfield* gpu_field, struct EMfield* cpu_field, struct EMfield* gpu_field_ptr, size_t count);

void transfer_particles(struct particles* cpu_part, struct particles* gpu_part, struct particles** gpu_part_ptr, size_t count);
void get_particles(struct particles* gpu_part, struct particles* cpu_part, struct particles* gpu_part_ptr, size_t count);