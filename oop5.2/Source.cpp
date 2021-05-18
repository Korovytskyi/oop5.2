#include <iostream>
#include <string>
#include <exception>
#include <math.h>
#include <sstream>

#include <iomanip>


using namespace std;

class Empty
{};

class Error
{
	string message;
public:
	Error(string message)
		: message(message)
	{}
	string What() { return message; }
};

class E : public exception
{
	string message;
public:
	E(string message)
		: message(message)
	{}
	string What() { return message; }
};

class Time
{
private:
	int hh, mm, ss, hh1, mm1, ss1;
public:
	void displayTime(void);
	int Time1(int hh, int mm, int ss, int hh1, int mm1, int ss1);
	int Time2(int hh, int mm, int ss, int hh1, int mm1, int ss1);
	int Time3(int hh, int mm, int ss, int hh1, int mm1, int ss1);
	int Time4(int hh, int mm, int ss, int hh1, int mm1, int ss1);
	int Time5(int hh, int mm, int ss, int hh1, int mm1, int ss1);
	int Time6(int hh, int mm, int ss, int hh1, int mm1, int ss1);
	void getTime(void);
	void getTime1(void);
};
int Time::Time1(int hh, int mm, int ss, int hh1, int mm1, int ss1) {
	if (hh > 24 && mm > 60 && ss > 60) throw 1;
	return  (hh - hh1)*3600 + (mm-mm1) * 60+ss;
}
int Time::Time2(int hh, int mm, int ss, int hh1, int mm1, int ss1)throw() {
	if (hh > 24 && mm > 60 && ss > 60) throw 1.0;
	return  (hh - hh1) * 3600 + (mm - mm1) * 60 + ss;
}
int Time::Time3(int hh, int mm, int ss, int hh1, int mm1, int ss1)throw(char) {
	if (hh > 24 && mm > 60 && ss > 60) throw '1';
	return (hh - hh1) * 3600 + (mm - mm1) * 60 + ss;
}
int Time::Time4(int hh, int mm, int ss, int hh1, int mm1, int ss1)throw (Empty) {
	if (hh > 24 && mm > 60 && ss > 60) throw Empty();
	return  (hh - hh1) * 3600 + (mm - mm1) * 60 + ss;
}
int Time::Time5(int hh, int mm, int ss, int hh1, int mm1, int ss1)throw(Error) {
	if (hh > 24 && mm > 60 && ss > 60) throw Error("Wrong time!");
	return  (hh - hh1) * 3600 + (mm - mm1) * 60 + ss;
}
int Time::Time6(int hh, int mm, int ss, int hh1, int mm1, int ss1)throw(int) {
	if (hh > 24 && mm > 60 && ss > 60) throw E("Wrong time!");
	return  (hh - hh1) * 3600 + (mm - mm1) * 60 + ss;
}

void Time::displayTime(void)
{
	cout << "The time is = "  << hh-hh1 << ":"<< mm-mm1 << ":" << ss-ss1 << endl;

}
void Time::getTime(void)

{
	cout << "Enter time:" << endl;
	cout << "Hours   ";          cin >> hh;
	cout << "Minut ";          cin >> mm;
	cout << "Sec ";               cin >> ss;
	
}
void Time::getTime1(void)

{
	cout << "Enter time:" << endl;
	cout << "Hours1   ";          cin >> hh1;
	cout << "Minut1 ";          cin >> mm1;
	cout << "Sec1 ";               cin >> ss1;
}
void unexpected() {
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void terminate() {
	cout << "unknown error! - terminate" << endl;
	abort();
}
int main()
{
	
	int hh, mm, ss, hh1, mm1, ss1;
	Time T;
	T.getTime();
	T.getTime1();
	T.displayTime();
	for (int i = 0; i < 6; i++)
	{
		cout << "Hours   ";          cin >> hh;
		cout << "Minut ";          cin >> mm;
		cout << "Sec ";               cin >> ss;
		cout << "Hours1   ";          cin >> hh1;
		cout << "Minut1 ";             cin >> mm1;
		cout << "Sec1 ";               cin >> ss1;
		try
		{
			if (i == 0)
			{
				cout << T.Time1(hh, mm, ss, hh1, mm1, ss1) << endl;
			}
			else if (i == 1)
			{
				cout << T.Time2(hh, mm, ss, hh1, mm1, ss1) << endl;
			}
			else if (i == 2)
			{
				cout << T.Time3(hh, mm, ss, hh1, mm1, ss1) << endl;
			}
			else if (i == 3)
			{
				cout << T.Time4(hh, mm, ss, hh1, mm1, ss1) << endl;
			}
			else if (i == 4)
			{
				cout << T.Time5(hh, mm, ss, hh1, mm1, ss1) << endl;
			}
			else
			{
				cout << T.Time6(hh, mm, ss, hh1, mm1, ss1) << endl;
			}
		}
		catch (int)
		{
			cout << " catch (int) <= Time1()" << endl;
		}
		catch (double)
		{
			cout << " catch (double) <= Time2()" << endl;
		}
		catch (char)
		{
			cout << " catch (char) <= Time3()" << endl;
		}
		catch (Empty)
		{
			cout << " catch (Empty) <= Time4()" << endl;
		}
		catch (Error e)
		{
			cout << " catch (Error) <= Time5() :" << endl;
			cout << e.What() << endl;
		}
		catch (bad_exception)
		{
			cout << " catch (bad_exception)" << endl;
		}
		catch (exception)
		{
			cout << " catch (exception) <= Time6() :" << endl;
		}
		catch (E e)
		{
			cout << " catch (E) <= Time6() :" << endl;
			cout << e.What() << endl;
		}

	}



	return 0;
}
	