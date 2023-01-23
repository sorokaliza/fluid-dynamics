#include <iostream>
#include <cstdio>

const int N = 256; // grid size
const double dt = 0.01; // time step
const double viscosity = 0.1; // fluid viscosity

double u[N][N], v[N][N], p[N][N]; // velocity and pressure fields
double u_prev[N][N], v_prev[N][N]; // previous velocity fields
double rho[N][N]; // density field

void advection(double u[N][N], double v[N][N]) {
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < N-1; j++) {
            u_prev[i][j] = u[i][j];
            v_prev[i][j] = v[i][j];
        }
    }

    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < N-1; j++) {
            u[i][j] = u_prev[i][j] - dt * (u_prev[i][j]*(u_prev[i+1][j]-u_prev[i-1][j])/2 + v_prev[i][j]*(u_prev[i][j+1]-u_prev[i][j-1])/2);
            v[i][j] = v_prev[i][j] - dt * (u_prev[i][j]*(v_prev[i+1][j]-v_prev[i-1][j])/2 + v_prev[i][j]*(v_prev[i][j+1]-v_prev[i][j-1])/2);
        }
    }
}

void diffusion(double u[N][N], double v[N][N]) {
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < N-1; j++) {
            u[i][j] += viscosity * dt * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1] - 4*u[i][j]) / (2*2);
            v[i][j] += viscosity * dt * (v[i+1][j] + v[i-1][j] + v[i][j+1] + v[i][j-1] - 4*v[i][j]) / (2*2);
        }
    }
}

void projection() {
    // solve pressure field
    // update velocity field
}

int main() {
    while (true) {
        advection(u
