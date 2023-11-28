#include "Copy.h"


// Copies result back to CPU and deallocates
void dealloc_grid(struct grid* gpu_grid, struct grid* gpu_grid_ptr) {
  int len = sizeof(FPpart) * gpu_grid->nxn * gpu_grid->nyn * gpu_grid->nzn;
  // Deallocate
  cudaFree(gpu_grid->XN_flat);
  cudaFree(gpu_grid->YN_flat);
  cudaFree(gpu_grid->ZN_flat);
  cudaFree(gpu_grid_ptr);
}

// Allocates and copies grid to GPU
void transfer_grid(struct grid* cpu_grid, struct grid* gpu_grid,
                                   struct grid** gpu_grid_ptr) {
  int count = sizeof(FPpart) * cpu_grid->nxn * cpu_grid->nyn * cpu_grid->nzn;

  std::memcpy(gpu_grid, cpu_grid, sizeof(grid));
  // Alloc
  cudaMalloc(&gpu_grid->XN_flat, count);
  cudaMalloc(&gpu_grid->YN_flat, count);
  cudaMalloc(&gpu_grid->ZN_flat, count);
  cudaMalloc(gpu_grid_ptr, sizeof(grid));

  // update unflattened pointer
  gpu_grid->XN = (FPpart***)gpu_grid->XN_flat;
  gpu_grid->YN = (FPpart***)gpu_grid->YN_flat;
  gpu_grid->ZN = (FPpart***)gpu_grid->ZN_flat;

  // Copy
  cudaMemcpy(gpu_grid->XN_flat, cpu_grid->XN_flat, count, cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_grid->YN_flat, cpu_grid->YN_flat, count, cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_grid->ZN_flat, cpu_grid->ZN_flat, count, cudaMemcpyHostToDevice);
  cudaMemcpy(*gpu_grid_ptr, gpu_grid, sizeof(grid), cudaMemcpyHostToDevice);
}

// Transfers params to gpu, deep copy not needed since we dont read those fields
void transfer_param(struct parameters* param, struct parameters** gpu_param_ptr) {
  //Alloc
  cudaMalloc(gpu_param_ptr, sizeof(parameters));
  //Copy
  cudaMemcpy(*gpu_param_ptr, param, sizeof(parameters), cudaMemcpyHostToDevice);
}

// Allocates and copies field to GPU
void transfer_field(struct EMfield* cpu_field, struct EMfield* gpu_field, struct EMfield** gpu_field_ptr, size_t count) {
  std::memcpy(gpu_field, cpu_field, sizeof(EMfield));
  // Alloc
  cudaMalloc(&gpu_field->Ex_flat, count * sizeof(FPpart));
  cudaMalloc(&gpu_field->Ey_flat, count * sizeof(FPpart));
  cudaMalloc(&gpu_field->Ez_flat, count * sizeof(FPpart));
  cudaMalloc(&gpu_field->Bxn_flat, count * sizeof(FPpart));
  cudaMalloc(&gpu_field->Byn_flat, count * sizeof(FPpart));
  cudaMalloc(&gpu_field->Bzn_flat, count * sizeof(FPpart));
  cudaMalloc(gpu_field_ptr, sizeof(EMfield));

  // Copy
  cudaMemcpy(gpu_field->Ex_flat, cpu_field->Ex_flat, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_field->Ey_flat, cpu_field->Ey_flat, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_field->Ez_flat, cpu_field->Ez_flat, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_field->Bxn_flat, cpu_field->Bxn_flat, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_field->Byn_flat, cpu_field->Byn_flat, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_field->Bzn_flat, cpu_field->Bzn_flat, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(*gpu_field_ptr, gpu_field, sizeof(EMfield), cudaMemcpyHostToDevice);
}

// Copies result back to CPU and deallocates
void dealloc_field(struct EMfield* gpu_field, struct EMfield* gpu_field_ptr, size_t count) {
  // Deallocate
  cudaFree(gpu_field->Ex_flat);
  cudaFree(gpu_field->Ey_flat);
  cudaFree(gpu_field->Ez_flat);
  cudaFree(gpu_field->Bxn_flat);
  cudaFree(gpu_field->Byn_flat);
  cudaFree(gpu_field->Bzn_flat);
  cudaFree(gpu_field_ptr);
}

// Allocates and copies field to GPU
void transfer_particles(struct particles* cpu_part, struct particles* gpu_part, struct particles** gpu_part_ptr, size_t count) {
  std::memcpy(gpu_part, cpu_part, sizeof(particles));
  // Alloc
  cudaMalloc(&gpu_part->x, count * sizeof(FPpart));
  cudaMalloc(&gpu_part->y, count * sizeof(FPpart));
  cudaMalloc(&gpu_part->z, count * sizeof(FPpart));
  cudaMalloc(&gpu_part->u, count * sizeof(FPpart));
  cudaMalloc(&gpu_part->v, count * sizeof(FPpart));
  cudaMalloc(&gpu_part->w, count * sizeof(FPpart));
  cudaMalloc(gpu_part_ptr, sizeof(particles));

  // Copy
  cudaMemcpy(gpu_part->x, cpu_part->x, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_part->y, cpu_part->y, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_part->z, cpu_part->z, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_part->u, cpu_part->u, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_part->v, cpu_part->v, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(gpu_part->w, cpu_part->w, count * sizeof(FPpart), cudaMemcpyHostToDevice);
  cudaMemcpy(*gpu_part_ptr, gpu_part, sizeof(particles), cudaMemcpyHostToDevice);
}

// Copies result back to CPU and deallocates
void get_particles(struct particles* gpu_part, struct particles* cpu_part, struct particles* gpu_part_ptr, size_t count) {

  // Get result
    // Copy
  cudaMemcpy(cpu_part->x, gpu_part->x, count * sizeof(FPpart), cudaMemcpyDeviceToHost);
  cudaMemcpy(cpu_part->y, gpu_part->y, count * sizeof(FPpart), cudaMemcpyDeviceToHost);
  cudaMemcpy(cpu_part->z, gpu_part->z, count * sizeof(FPpart), cudaMemcpyDeviceToHost);
  cudaMemcpy(cpu_part->u, gpu_part->u, count * sizeof(FPpart), cudaMemcpyDeviceToHost);
  cudaMemcpy(cpu_part->v, gpu_part->v, count * sizeof(FPpart), cudaMemcpyDeviceToHost);
  cudaMemcpy(cpu_part->w, gpu_part->w, count * sizeof(FPpart), cudaMemcpyDeviceToHost);

  // Deallocate
  cudaFree(gpu_part->x);
  cudaFree(gpu_part->y);
  cudaFree(gpu_part->z);
  cudaFree(gpu_part->u);
  cudaFree(gpu_part->v);
  cudaFree(gpu_part->w);
  cudaFree(gpu_part_ptr);
}