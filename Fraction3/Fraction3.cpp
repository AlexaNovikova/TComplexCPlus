

#include <iostream>
#include "UFract.h"
int main()
{
	TFract f1(1, 3);
	TFract f2(2, 3);

	TFract addFr = f1.add(f2);
	std::cout << f1 << " + " << f2 << " = " << addFr << std::endl;

	TFract subFr = f1.sub(f2);
	std::cout << f1 << " - " << f2 << " = " << subFr << std::endl;

	TFract multiplyFr = f1.multiply(f2);
	std::cout << f1 << " * " << f2 << " = " << multiplyFr << std::endl;

	TFract divideFr = f1.divide(f2);
	std::cout << f1 << " / " << f2 << " = " << divideFr << std::endl;

	TFract squareFr = f1.square();
	std::cout << f1 <<"^2" << " = " << squareFr << std::endl;

	TFract reverseFr = f1.reverse();
	std::cout << f1 << " reverse " << " = " << reverseFr << std::endl;

	TFract copy = f1.copy();
	std::cout << f1 << " copy " << " = " << copy << std::endl;

	TFract squareCopy = copy.square();
	std::cout << copy << "^2" << " = " << squareCopy << std::endl;

	std::cout << f1 << " > " << f2 <<"  " << f1.isGreater(f2) << std::endl;

	std::cout << f2 << " > " << f1 << "  " << f2.isGreater(f1) << std::endl;

	std::cout << f1 << " equals " << f2 <<"  "<< f1.equals(f2) << std::endl;


	std::cout << f1 << " numerator " << std::setprecision(2)<< f1.getNumeratorNumber() << std::endl;
	std::cout << f1 << " denumerator " << std::setprecision(2)<< f1.getDenumeratorNumber() << std::endl;
	std::cout << f1 << " numerator " << f1.getNumeratorString() << std::endl;
	std::cout << f1 << " denumerator " << f1.getDenumeratorString() << std::endl;

	std::cout << f1 << " equals " << f1 << "  "<< f1.equals(f1) << std::endl;
    system("pause");
	return 0;
}

