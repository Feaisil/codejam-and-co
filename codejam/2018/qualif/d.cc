#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

template<typename T>
void r(T& o)
{
	cin >> o;
}
template<typename T>
void rv( int n, vector<T> &o) 
{
	for(int bal=0; bal<n;bal++)
	{
		int j=0;
		r(j);
		o.push_back(j);
	}
}
template<typename T>
void rv(vector<T> &o)
{
	int t;
	r(t);
	rv(t,o);
}

template<typename T>
void ov(const vector<T> &i)
{
	for(auto v: i)
	{
		cout << v << " ";
	}
}

void proc()
{
	double a;
	static double s2 = 1.414213;
	static double pi = 3.141592653589793;
	cin >> a;
	double t=(acos(a/s2));
	cerr << t << endl;
	cout << setprecision(20) << 0.5*cos(t-pi/4) << " "  <<  0.5*sin(t-pi/4) << " " <<  0 << endl;
	cout << 0.5*cos(t+pi/4) << " " <<0.5*sin(t+pi/4) << " " << 0 << endl;
	cout << 0 << " " << 0 << " " << 0.5 << endl;
	
}

int main()
{
	int t;
	int n;
	int j;
	r(t);
	cerr << "Going for " << t << " cases" << endl;
	for(int i = 1; i<t+1; i++)
	{
		cerr << "Starting case " << i << endl;
		cout << "Case #" << i << ": " << endl;
		proc();
		cout << endl; 
	}
	return 0;
}
