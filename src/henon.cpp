#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame Henon(double x0, double y0, double a = 1.4, double b = 0.3, int iterations = 1e7) {
	// create the columns
	NumericVector x(iterations);
	NumericVector y(iterations);
	x[0]=x0;
	y[0]=y0;
	for(int i = 1; i < iterations; ++i) {
		x[i] = 1-a*(x[i-1]*x[i-1])+y[i-1];
		y[i] = b*x[i-1];
	}
	// return a new data frame
	return DataFrame::create(_["x"]= x, _["y"]= y);
}
