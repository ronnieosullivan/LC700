// generate random number in triangle
pair<double, double> A = { 0.0, 0.0 }, B = { 1.0, 0.0 }, C = { 0.0, 1.0 };
double x = (1 - sqrt(r1)) * A.first 
	+ (sqrt(r1) * (1 - r2)) * B.first 
	+ (sqrt(r1) * r2) * C.first;
double y = (1 - sqrt(r1)) * A.second 
	+ (sqrt(r1) * (1 - r2)) * B.second 
	+ (sqrt(r1) * r2) * C.second;