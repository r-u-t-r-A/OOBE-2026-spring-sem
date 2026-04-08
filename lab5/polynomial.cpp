#include "polynomial.h"
#include <cmath>
#include <algorithm>

Polynomial::Polynomial() {
    coefficients = {0.0, 7.0, 0.0, -1.3, 2.0};
}

Polynomial::Polynomial(const std::vector<double>& terms) {
    coefficients = terms;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> result(maxSize, 0.0);
    
    for (size_t i = 0; i < maxSize; ++i) {
        double a = (i < coefficients.size()) ? coefficients[i] : 0.0;
        double b = (i < other.coefficients.size()) ? other.coefficients[i] : 0.0;
        result[i] = a + b;
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> result(maxSize, 0.0);
    
    for (size_t i = 0; i < maxSize; ++i) {
        double a = (i < coefficients.size()) ? coefficients[i] : 0.0;
        double b = (i < other.coefficients.size()) ? other.coefficients[i] : 0.0;
        result[i] = a - b;
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(double scalar) const {
    std::vector<double> result = coefficients;
    for (double& val : result) {
        val *= scalar;
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    if (coefficients.empty() || other.coefficients.empty()) {
        return Polynomial(std::vector<double>());
    }
    
    std::vector<double> result(coefficients.size() + other.coefficients.size() - 1, 0.0);
    for (size_t i = 0; i < coefficients.size(); ++i) {
        for (size_t j = 0; j < other.coefficients.size(); ++j) {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return Polynomial(result);
}

double Polynomial::operator[](int index) const {
    if (index >= 0 && index < static_cast<int>(coefficients.size())) {
        return coefficients[index];
    }
    return 0.0; 
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    if (p.coefficients.empty()) {
        os << "0";
        return os;
    }

    bool isFirst = true;
    bool allZero = true;

    for (int i = p.coefficients.size() - 1; i >= 0; --i) {
        if (p.coefficients[i] != 0.0) {
            allZero = false;
            
            if (!isFirst) {
                if (p.coefficients[i] > 0) {
                    os << " + ";
                } else {
                    os << " - ";
                }
            } else if (p.coefficients[i] < 0) {
                os << "-";
            }

            os << std::abs(p.coefficients[i]);

            if (i > 0) {
                os << "x^" << i;
            }
            
            isFirst = false;
        }
    }
    
    if (allZero) {
        os << "0";
    }
    
    return os;
}