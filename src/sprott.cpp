#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame sprott(int iterations = 1e7, double x0 = 1, double y0 = 1,
    double a1 = 0.48, double a2 = -0.63, double a3=1.02, double a4=-1.66, double a5=-0.15,
    double a6=2.08, double a7=0.26, double a8=1.39, double a9=-0.66, double a10=-0.41,
    double a11=-0.25, double a12=-1.29, double a13=-1.21, double a14=-0.65) {
    NumericVector x(iterations);
    NumericVector y(iterations);
    x[0]=x0;
    y[0]=y0;
    for(int i = 1; i < iterations; ++i) {
	    x[i] = a1+a2*x[i-1]+ a3*y[i-1]+ a4*pow(fabs(x[i-1]), a5)+ a6*pow(fabs(y[i-1]), a7);
	    y[i] = a8+a9*x[i-1]+ a10*y[i-1]+ a11*pow(fabs(x[i-1]), a12)+ a13*pow(fabs(y[i-1]), a14);
    }
    // return a new data frame
    return DataFrame::create(_["x"]= x, _["y"]= y);
}
