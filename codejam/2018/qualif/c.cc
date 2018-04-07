#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

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
	int a;
	int tries = 0;
	int ci = 2, cj = 2;
	int i=1, j=1; 
	
	cin >> a;
	
	vector<vector<bool>> m(1001, vector<bool>(1001, false));
	
	cerr << a << "\t" << i << "\t" << j << endl;
	while(i > 0 and j > 0 and tries < 1000)
	{
		++tries;
		cout << ci << " " << cj << endl << flush;
		cin >> i >> j;
		m[i][j] = true;
		bool full = true;
		for(int k=-1; k<=1; ++k)
			full &= m[ci+k][cj-1];
		if(full and a>9) cj++;
	}
	if(tries == 1000) throw;
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
		proc();
	}
	return 0;
}
