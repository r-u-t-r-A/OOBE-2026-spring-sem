#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <list>
#include <iostream>

class Polynomial {
private:
    std::vector<double> coefficients;

public:
    Polynomial();
    Polynomial(const std::vector<double>& terms);

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(double scalar) const;
    Polynomial operator*(const Polynomial& other) const;
    double operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
};

#endif // POLYNOMIAL_H