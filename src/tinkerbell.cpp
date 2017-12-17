#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame Tinkerbell(double a = 0.9, double b = -0.6013, double c = 2, double d = 0.5, double x0 = -0.72, double y0 = -0.64, int iterations = 1e7) {
	// create the columns
	NumericVector x(iterations);
	NumericVector y(iterations);
	x[0]=x0;
	y[0]=y0;
	for(int i = 1; i < iterations; ++i) {
		x[i] = (x[i-1]*x[i-1])-(y[i-1]*y[i-1])+a*x[i-1]+b*y[i-1];
		y[i] = 2*x[i-1]*y[i-1]+c*x[i-1]+d*y[i-1];
	}
	// return a new data frame
	return DataFrame::create(_["x"]= x, _["y"]= y);
}
