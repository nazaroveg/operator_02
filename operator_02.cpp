// operator_02.cpp :
//

#include <iostream>
#include <exception>
class Fraction
{
private:
	int numerator_ = 0;
	int denominator_ = 0;
	int count = 0;

public:
	Fraction(int numerator, int denominator)
	{
		
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction (int cou): count (cou) {}

	void print()
	{
		
		std::cout << numerator_ << " / " << denominator_ << std::endl;
	}
	void print2()
	{

		std::cout << "Значение дроби 1: " << numerator_ << " / " << denominator_ << std::endl;
	}
	
	Fraction operator+(const Fraction& other)
	{
		Fraction temp{0,0};
		
		temp.numerator_ = numerator_ * other.denominator_; 
		temp.denominator_ = denominator_ * other.numerator_; 
		temp.numerator_ = temp.numerator_ + temp.denominator_;
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}
	Fraction operator-(const Fraction& other)
	{
		Fraction temp{ 0,0 };

		temp.numerator_ = numerator_ * other.denominator_; 
		temp.denominator_ = denominator_ * other.numerator_; 
		temp.numerator_ = temp.numerator_ - temp.denominator_;
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}
	Fraction operator*(const Fraction& other)
	{
		Fraction temp{ 0,0 };

		temp.numerator_ = numerator_ * other.denominator_; 
		temp.denominator_ = denominator_ * other.numerator_; 
		temp.numerator_ = temp.numerator_ * temp.denominator_;
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}
	Fraction operator/(const Fraction& other)
	{
		Fraction temp{ 0,0 };

		temp.numerator_ = numerator_ * other.denominator_; 
		temp.denominator_ = denominator_ * other.numerator_; 
		temp.numerator_ = temp.numerator_ / temp.denominator_;
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}






};





int main()
{
	setlocale(LC_ALL, "RUS");
	
	
		std::cout << "Введите числитель дроби 1: ";
		int one_1 = 0;
		std::cin >> one_1;
		std::cout << "Введите знаменатель дроби 1: ";
		int one_2 = 0;
		std::cin >> one_2;

		std::cout << "Введите числитель дроби 2: ";
		int two_1 = 0;
		std::cin >> two_1;
		std::cout << "Введите знаменатель дроби 2: ";
		int two_2 = 0;
		std::cin >> two_2;
		

		

		
		
		
			Fraction f1(one_1, one_2);
		
			Fraction f2(two_1, two_2);
		
		    Fraction f3(0, 0);

	f3 = f1 + f2;
	std::cout << one_1 << " / " << one_2 << " + " << two_1 << " / " << two_2 << " = "; f3.print();
	f3 = f1 - f2;
	std::cout << one_1 << " / " << one_2 << " - " << two_1 << " / " << two_2 << " = "; f3.print();
	f3 = f1 * f2;
	std::cout << one_1 << " / " << one_2 << " * " << two_1 << " / " << two_2 << " = "; f3.print();
	f3 = f1 / f2;
	std::cout << one_1 << " / " << one_2 << " / " << two_1 << " / " << two_2 << " = "; f3.print();
	
	
	/*f3 = ++f1 * f2;
	std::cout << one_1 << " / " << one_2 << " ++ " << two_1 << " / " << two_2 << " = "; f3.print();
	f3 = f1-- * f2;
	std::cout << one_1 << " / " << one_2 << " -- " << two_1 << " / " << two_2 << " = "; f3.print();
	++f1;
	 f1.print();
	 f1++;
	 f1.print();
	 --f1;
	 f1.print();
	 f1--;
	 f1.print();*/
	 
	 
	 
	return 0;
}