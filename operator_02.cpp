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
	

	void print()
	{
		
		std::cout << numerator_ << " / " << denominator_ << std::endl;
	}
	void print2()
	{

		std::cout << "Значение дроби 1: " << numerator_ << " / " << denominator_ << std::endl;
	}
	 int divisor( int a, int b) {
		if (a % b == 0)
			return b;
		if (b % a == 0)
			return a;
		if (a > b)
			return divisor(a % b, b);
		return divisor(a, b % a);
	}


	
	Fraction operator + (const Fraction& other)
	{
		Fraction temp{0,0};
		if (denominator_ != other.denominator_)
		{
			temp.numerator_ = numerator_ * other.denominator_;
			temp.denominator_ = denominator_ * other.numerator_;
			temp.numerator_ = temp.numerator_ + temp.denominator_;
			temp.denominator_ = denominator_ * other.denominator_;
			return temp;
		}
		else
		{
			temp.numerator_ = numerator_ + other.numerator_;
			temp.denominator_ = denominator_;
			return temp;
		}
	}
	Fraction operator - (const Fraction& other)
	{
		Fraction temp{ 0,0 };
		if (denominator_ != other.denominator_)
		{
			temp.numerator_ = numerator_ * other.denominator_;
			temp.denominator_ = denominator_ * other.numerator_;
			temp.numerator_ = temp.numerator_ - temp.denominator_;
			temp.denominator_ = denominator_ * other.denominator_;
			return temp;
		}
		else
		{
			temp.numerator_ = numerator_ - other.numerator_;
			temp.denominator_ = denominator_;
			return temp;
		}


	}
	Fraction operator * (const Fraction& other)
	{
		Fraction temp{ 0,0 };

		temp.numerator_ = numerator_ * other.numerator_; 
		temp.denominator_ = denominator_ * other.denominator_; 
		
		int dev = divisor(temp.numerator_, temp.denominator_);
		
		temp.numerator_ = temp.numerator_ / dev;
		temp.denominator_ = temp.denominator_ / dev;

		return temp;
	}
	Fraction operator / (const Fraction& other)
	{
		Fraction temp{ 0,0 };

		temp.numerator_ = numerator_ * other.denominator_; 
		temp.denominator_ = denominator_ * other.numerator_; 
		
		return temp;
	}
	Fraction& sum()
	{
		Fraction temp{ 0,0 };
		temp.numerator_ = numerator_ + denominator_;
		temp.denominator_ = denominator_;
		return *this;
	}
	
	Fraction operator ++ ()
	{
		Fraction temp{ 0,0 };
		temp.numerator_ = numerator_ + denominator_;
		temp.denominator_ = denominator_;
		return temp;
	}
	Fraction operator ++ (int)
	{
		Fraction temp = *this;
		++(*this);
		
		return temp;
	}

	Fraction& res()
	{
		Fraction temp{ 0,0 };
		temp.numerator_ = numerator_ - denominator_;
		temp.denominator_ = denominator_;
		return *this;
	}

	Fraction operator -- ()
	{
		Fraction temp{ 0,0 };
		temp.numerator_ = numerator_ - denominator_;
		temp.denominator_ = denominator_;
		return temp;
	}
	Fraction operator -- (int)
	{
		Fraction temp = *this;
		--(*this);

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
	f3 = ++f1 * f2;
	std::cout << " ++ " << one_1 << " / " << one_2 << " * " << two_1 << " / " << two_2 << " = "; f3.print();
	f3 = f1-- * f2;
	std::cout << one_1 << " / " << one_2 <<"--" <<" * " << two_1 << " / " << two_2 << " = "; f3.print();




	f3 = ++f1; f3.print2();
	f3 = f1++; f3.print2();
	f3 = --f1; f3.print2();
	f3 = f1--; f3.print2();
	return 0;
}