//Complex.h

#ifndef COMPLEX
#define COMPLEX
#include <string>

class Complex {
public:
	//constructors
	constexpr Complex(const double& _real = 0, const double& _imaginary = 0);
	Complex(const std::string& number);






private:
	double real;
	double imaginary;
};

#endif	
