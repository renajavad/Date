#include <iostream>

struct WrongDayException            //Add Struct Wrong Exception
{
	int day;
};
struct WrongMonthException
{
	int month;
};
struct WrongYearException
{
	int year;
};

class Date 
{
	private:
		int day;
		int month;
		int year;
		
	public:
		Date( int d, int m, int y )
		{
			int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
				if( (y % 4 == 0 && y % 100 != 0) || (y % 400 ==0) )
				{
					days[1] = 29;
				}
				if( d <= 0 || d > days[m] )
				{
					throw WrongDayException(d);        //Add throw WrongException
				}
				if( m <= 0 || m > 12 )
				{
					throw WrongMonthException(m);
				}
				if( y <= 0 )
				{
					throw WrongYearException(y);
				}
				day = d;
				month = m;
				year = y;
		}

		Date( int d ): Date( d, 1, 1 )
		{
			int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			if( day <= 0 || day > days[month] )
				{
					throw WrongDayException(d);
				}
		}

		int GetDay() const;
		int GetMonth() const;
		int GetYear() const;

		Date& operator += ( int d )
		{
			day +=d;
			Date( day, month, year);
			return *this;
		}
		Date operator+ ( int d ) const
		{
			return Date( day+d, month, year );
		}
		Date operator- ( int d ) const
		{
			return Date( day-d, month, year );
		}

		void AddDay( int d ) 
		{
			day += d;
			Date( day, month, year);
		}
		void MinusDay( int d )
		{
			day-=d;
			Date( day, month, year);
		}
};

	int Date::GetDay() const
	{
		return day;
	}
	int Date::GetMonth() const
	{
		return month;
	}
	int Date::GetYear() const
	{
		return year;
	}
	
	std::ostream& operator << ( std::ostream& out, const Date& d ) 
	{
		out << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear();
		return out;
	}
	std::istream& operator >> ( std::istream& in, Date& d )
	{
		std::cin.exceptions(std::istream::failbit);
		int din;
		int min;
		int yin;
		char c;
		in >> din >> c;
		in >> min >> c;
		in >> yin >> c;
		d = Date( din, min, yin);
		return in;
	}
	
int main() 
{
	try					      //Add try-catch
		{
			Date d( 3, 2, 2024);
		}
		catch( const WrongDayException& day)
		{
			std::cerr << "Wrong day " << "\n";
			return 1;
		}
		catch( const WrongMonthException& month)
		{
			std::cerr << "Wrong month " << "\n";
			return 1;
		}
		catch( const WrongYearException& year)
		{
			std::cerr << "Wrong year " << "\n";
			return 1;
		}
		catch( const std::istream::failure& ex )
		{
			std::cerr << "Failed to read data: " << ex.what() << "\n";
		}
		catch(...)
		{
			std::cerr << "Other failure" << "\n";
		}
		return 0;
}		

	
