#include <iostream>
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
	long
		n,
		k,
		m,
		M; // min and Max
	r(n); r(k);
	
	cerr << n << "  " << k << endl;
	vector<bool> v(n, false);
	cerr << n;
	
	for(; k>0; --k)
	{
		int g = 0; // current gap size
		int mg = 0; // biggest gap size
		int mgi = 0;
		for(int i=0; i<n; i++)
		{
			g++;
			if(v[i])
				g=0;
			if(g>mg)
			{
				mg=g;
				mgi=i-g/2;
			}
			//cerr << k << ": " << i << ": " << mg << " " << mgi << " " << g << endl;
		}
		m = mg;
		v[mgi] = true;
	}
	
	cout << m/2 << " " << m/2 - (m%2?0:1) ;
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
		cout << "Case #" << i << ":";
		proc();
		cout << endl; 
	}
	return 0;
}
