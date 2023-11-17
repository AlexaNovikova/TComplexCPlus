#pragma once
#ifndef UFract_H
#define UFract_H

#include <iostream>
#include <sstream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <functional>
#include "Fraction_E.h"

class TFract {

public:
	TFract();
	TFract(int, int);
	TFract(string str);

	// Common operations
	TFract operator+(const TFract&);
	TFract operator-(const TFract&);
	TFract operator*(const TFract&);
	TFract operator/(const TFract&);
	
	// Comparators
	bool operator==(const TFract&);
	bool operator!=(const TFract&);
	bool operator>(const TFract&);
    bool operator<(const TFract&);
    bool operator>=(const TFract&);
	bool operator<=(const TFract&);


	double getDoubleValue() const;
	float getFloatValue() const;

	double getNumeratorNumber();
	double getDenumeratorNumber();
	string getNumeratorString();
	string getDenumeratorString();
	string getTFractString();

	TFract add(TFract toAddTFract);
	TFract sub(TFract toSubTFract);
	TFract multiply(TFract multiplier);
	TFract divide(TFract divider);
	TFract square();
	TFract minus();
	TFract reverse();
	bool equals(TFract TFract);
	bool isGreater(TFract toCompare);
	TFract copy();
	

	const std::string toString() const;

	friend std::ostream& operator<<(std::ostream& strm, TFract TFract) {
		return strm << TFract.toString();
	}

private:
	// numerator/denominator
	int numerator;
	int denominator;


	// Utils methods
	void checkDivisionByZero(const TFract&, int) const;
	int gcd(int, int) const;
	int lcm(int, int) const;
	void simplify();

	// Generic functional comparator
	template <typename ComparisonOperator>
	bool comparison(const TFract& f1,
		const TFract& f2,
		ComparisonOperator operation) {

		if (f1.denominator == f2.denominator) {
			return operation(f1.numerator, f2.numerator);
		}

		int lcm = f1.lcm(f1.denominator, f2.denominator);

		return operation(f1.numerator * (lcm / f1.denominator),
			f2.numerator * (lcm / f2.denominator));
	}

	template <typename ComparisonOperator>
	bool comparison(const TFract& f1,
		const int& i1,
		ComparisonOperator operation) {

		if (this->denominator == 1) {
			return this->numerator == i1;
		}

		return operation(this->numerator,
			i1 * this->denominator);
	}

	template<typename PlusMinusOperator>
	TFract commonOperation(const TFract& f1,
		const TFract& f2,
		PlusMinusOperator operation) {

		int lcm = f1.lcm(f1.denominator, f2.denominator);

		TFract TFract(
			operation(
				f1.numerator * (lcm / f1.denominator),
				f2.numerator * (lcm / f2.denominator)
			), lcm);

		TFract.simplify();

		return TFract;
	}

	template<typename PlusMinusOperator>
	TFract commonOperation(const TFract& f1,
		const int& i1,
		PlusMinusOperator operation) {
		TFract TFract(
			operation(
				f1.numerator,
				i1 * f1.denominator
			), f1.denominator);

		TFract.simplify();

		return TFract;
	}

};


#endif
