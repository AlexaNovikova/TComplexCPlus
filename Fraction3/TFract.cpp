#include "UFract.h"
#include <iostream>


TFract::TFract() {
	this->numerator = 0;
	this->denominator = 1;
}


TFract::TFract(int numerator, int denominator) {
	if (denominator == 0) {
		this->numerator = 0;
		this->denominator = 1;
	}
	else {
		this->numerator = numerator;
		this->denominator = denominator;
		this->simplify();
	}
}

TFract::TFract(string str) {
	std::size_t pos = str.find("/");
	if (pos != std::string::npos) {
		this->numerator = atol(str.substr(0, pos).c_str());
		this->denominator = atol(str.substr(pos + 1).c_str());
		if (this->denominator != 0) {
			this->simplify();
		}
		else {
			this->numerator = 0;
			this->denominator = 1;
		}
	}
}


TFract TFract::add(TFract toAddTFract) {
	return this->commonOperation((*this), toAddTFract, std::plus<int>());
}

TFract TFract::minus() {
	return this->commonOperation( TFract(0,1), (*this),  std::minus<int>());
}

TFract TFract::sub(TFract toSubTFract) {
	return this->commonOperation((*this), toSubTFract, std::minus<int>());
}

TFract TFract::multiply(TFract multiplier) {
	TFract result(this->numerator * multiplier.numerator,
		this->denominator * multiplier.denominator);
	result.simplify();
	return result;
}

TFract TFract::divide(TFract divider) {
	this->checkDivisionByZero(divider, divider.numerator);

	TFract result(this->numerator * divider.denominator,
		this->denominator * divider.numerator);
	result.simplify();
	return result;
}

TFract TFract::square() //Квадрат
{
	TFract result(this->numerator * this->numerator,
		this->denominator * this->denominator);

	result.simplify();
	return result;
};

TFract TFract::reverse() //Обратное
{
	TFract result(this-> denominator,
		this->numerator);

	result.simplify();

	return result;
};

TFract TFract::copy() //Обратное
{
	TFract result(this->numerator,
		this->denominator);
	return result;
};

bool TFract::equals(TFract TFract) //Равно
{
	return this->numerator==TFract.numerator && 
		this->denominator==TFract.denominator;
};

bool TFract::isGreater(TFract TFract) //Равно
{
	return this->comparison((*this), TFract, std::greater<int>());
};




TFract TFract::operator+(const TFract& TFract) {
	return this->commonOperation((*this), TFract, std::plus<int>());
}


TFract TFract::operator-(const TFract& TFract) {
	return this->commonOperation((*this), TFract, std::minus<int>());
}


TFract TFract::operator*(const TFract& tFract) {
	TFract result (this->numerator * tFract.numerator,
		this->denominator * tFract.denominator);

	result.simplify();

	return result;
}


TFract TFract::operator/(const TFract& tFract) {
	this->checkDivisionByZero(tFract, tFract.numerator);

	TFract result(this->numerator * tFract.denominator,
		this->denominator * tFract.numerator);

	result.simplify();

	return result;
}


bool TFract::operator==(const TFract& TFract) {
	return this->comparison((*this), TFract, std::equal_to<int>());
}

bool TFract::operator!=(const TFract& TFract) {
	return this->comparison((*this), TFract, std::not_equal_to<int>());
}


bool TFract::operator>(const TFract& TFract) {
	return this->comparison((*this), TFract, std::greater<int>());
}


bool TFract::operator<(const TFract& TFract) {
	return this->comparison((*this), TFract, std::less<int>());
}


bool TFract::operator>=(const TFract& TFract) {
	return this->comparison((*this), TFract, std::greater_equal<int>());
}


bool TFract::operator<=(const TFract& TFract) {
	return this->comparison((*this), TFract, std::less_equal<int>());
}


double TFract::getDoubleValue() const {
	return this->numerator / (double)this->denominator;
}

float TFract::getFloatValue() const {
	return this->numerator / (float)this->denominator;
}


double TFract::getNumeratorNumber() {
	return static_cast<double>(this->numerator);
}
double TFract::getDenumeratorNumber() {
	return static_cast<double>(this->denominator);
}

string TFract::getNumeratorString() {
	std::stringstream asStream;

	asStream << this->numerator;

	return asStream.str();
}
string TFract::getDenumeratorString() {
	std::stringstream asStream;

	asStream << this->denominator;

	return asStream.str();
}

string TFract::getTFractString() {
	std::stringstream asStream;
	asStream << this->numerator << "/" << this->denominator;
	return asStream.str();
}

int TFract::gcd(int a, int b) const {
	for (;;) {

		if (a == 0) {
			return b;
		}

		b %= a;

		if (b == 0) {
			return a;
		}

		a %= b;
	}
}

int TFract::lcm(int a, int b) const {
	int gcd = this->gcd(a, b);

	return gcd ? (a / gcd * b) : 0;
}


void TFract::simplify() {
	int gcd = this->gcd(this->numerator, this->denominator);

	this->numerator /= gcd;
	this->denominator /= gcd;

	if (this->denominator < 0) {
		this->numerator = -this->numerator;
		this->denominator = -this->denominator;
	}
}

const std::string TFract::toString() const {
	std::stringstream asStream;

	asStream << this->numerator << "/" << this->denominator;

	return asStream.str();
}

void TFract::checkDivisionByZero(const TFract& TFract, int possibleZero) const {

	if (possibleZero == 0) {
		std::stringstream cause;
		cause << "Error: Division by zero ["
			<< this->toString()
			<< " / "
			<< TFract.toString()
			<< "]";

		throw FractionException(cause.str());
	}
}