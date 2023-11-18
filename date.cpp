#include <iostream>
class Date 
{
	private:
		int years;
		int months;
		int days;
		void Normalize()
		{
			int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			if( months == 2 )
			{
				if( (years % 4 == 0 && years % 100 != 0) || (years % 400 ==0) )
				{
					day[1] = 29;
				}
			}

			while( days > day[months-1] )
			{
				days -= day[months-1];
				if( months == 12 )
				{
					++years;
					months = 1;
				}
				else 
				{
					++months;
				}
			}
			while( days <= 0 )
			{
				if( months == 1 )
				{
					--years;
					months = 12;
				}
				else 
				{
					--months;
				}
				days += day[months-1];
			}			
};
	public:
		Date( int y, int m, int d );
		Date( int d ): Date( 0, 0, d)
		{
		}
		int GetYears() const;
		int GetMonth() const;
		int GetDays() const;
		Date& operator += ( int d )
		{
			days +=d;
			Normalize();
			return *this;
		}
		Date operator+ ( int d ) const
		{
			return Date( years, months, days+d );
		}
		Date operator- ( int d ) const
		{
			return Date( years, months, days-d );
		}
		void AddDays( int d ) 
		{
			days += d;
			Normalize();
		}
		void MinusDays( int d )
		{
			days-=d;
			Normalize();
		}
};

	Date::Date( int y, int m, int d)
	{
		years = y;
		months = m;
		days = d;
		Normalize();
	}
	int Date::GetYears() const
	{
		return years;
	}
	int Date::GetMonth() const
	{
		return months;
	}
	int Date::GetDays() const
	{
		return days;
	}
	
	std::ostream& operator << ( std::ostream& out, const Date& d ) 
	{
		out << d.GetYears() << ":" << d.GetMonth() << ":" << d.GetDays();
		return out;
	}
	std::istream& operator >> ( std::istream& in, Date& d )
	{
		int yin, min, din;
		char c;
		in >> yin >> c;
		in >> min >> c;
		in >> din >> c;
		d = Date( yin, min, din);
		return in;
	}
	
int main()
{
	Date d( 2024, 2, 3);
	std::cout << "Date: " << d <<"\n" ;
	d.AddDays(40);
	std::cout << "Add days: " << d <<"\n" ;
	d.MinusDays(3);
	std::cout << "Minus days: " << d <<"\n" ;
}		

	
