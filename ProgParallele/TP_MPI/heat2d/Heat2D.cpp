#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int main (int argc, char *argv[]) {

// Read input data from file

    std::ifstream input("input.dat");

// Thermal diffusivity alpha

    double alpha;

    input >> alpha;

// Spatial discretization and limits

    int xpts, ypts;
    double xlo, xup, ylo, yup;

    input >> xlo >> xup >> xpts;
    input >> ylo >> yup >> ypts;

    double hx = (xup-xlo) / (double)(xpts-1);
    double hy = (yup-ylo) / (double)(ypts-1);

// Temporal discretization and limit

    double tstop, dt;

    input >> tstop >> dt;

// Boundary conditions

    double T0;
    input >> T0;

// Close input file

    input.close();

// Courant-Friedrichs-Loewy coefficient

    double cfl_x = alpha*dt/(hx*hx);
    double cfl_y = alpha*dt/(hy*hy);

// Summarize computational parameters

    std::cout << "# xlo = " << xlo << "  xup = " << xup << "  xpts = " << xpts;
    std::cout << "  hx = " << hx << std::endl;
    std::cout << "# ylo = " << ylo << "  yup = " << yup << "  ypts = " << ypts;
    std::cout << "  hy = " << hy << std::endl;
    std::cout << "# dt = " << dt << "  tstop = " << tstop << std::endl;
    std::cout << "# alpha = " << alpha << "  T0 = " << T0 << std::endl;
    std::cout << "# cfl = " << cfl_x+cfl_y << std::endl;

    int nrows = xpts;
    int ncols = ypts;

// Solution u with boundary conditions

    double* u = new double[nrows*ncols];
    for (int j=0; j<ncols; ++j) {
            u[j] = T0;
    }
    for (int n=ncols; n<nrows*ncols; ++n) {
        u[n] = 0.0;
    }

    double* du_x = new double [nrows*ncols];
    double* du_y = new double [nrows*ncols];

// Loop over time

    double t = 0.0;
    while (t < tstop) {
        t += dt;
        for (int i=1; i<nrows-1; ++i) {
            for (int j=1; j<ncols-1; ++j) {
                du_x[i*ncols+j] = u[(i+1)*ncols+j] - 2.0*u[i*ncols+j] + u[(i-1)*ncols+j];
                du_y[i*ncols+j] = u[i*ncols+j+1] - 2.0*u[i*ncols+j] + u[i*ncols+j-1];
            }
        }
        for (int i=1; i<nrows-1; ++i) {
            for (int j=1; j<ncols-1; ++j) {
                u[i*ncols+j] += cfl_x*du_x[i*ncols+j] + cfl_y*du_y[i*ncols+j];
            }
        }
    }

// Save final result to file

    std::ofstream output("results.dat");

    for (int i=0; i<nrows; ++i) {
        for (int j=0; j<ncols; ++j)
            output << u[i*ncols+j] << " ";
        output << std::endl;
    }

    output.close();

// Delete dynamically allocated arrays

    delete [] u;
    delete [] du_x;
    delete [] du_y;

    return 0;
}


