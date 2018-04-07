#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>

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
void o(const vector<T> &i)
{
	for(auto v: i)
	{
		cout << v << " ";
	}
}

template<typename T>
void o(const T i)
{
	cout << i ;
}

void proc()
{
	int n,k;
	r(n); r(k);
	vector<double> v;
	rv(n,v);

	sort(v.begin(), v.end());
	double m;
	
	for(int i=0; i<=k; i++)
	{
		m = 0;
		for(double e:v) { m+=e/double(n); }
		for(double &e:v) { 
			e=e<m?m:e;
		}
	}
		
	o(m);
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
		cout << setprecision(10) <<"Case #" << i << ": ";
		proc();
		cout << endl; 
	}
	return 0;
}
