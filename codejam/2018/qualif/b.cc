#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

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
	vector<int> a, b;
	rv(a);
	b=a;
	sort(a.begin(), a.end());
	bool done= false;
	while(not done)
	{
		done = true;
		for(int i=0; i< b.size()-2; ++i)
		if( b[i] > b[i+2] )
		{
			done = false;
			swap(b[i], b[i+2]);
		}
	}
	if(a==b) cout << "OK";
	else
	{
		for(int i=0; i<a.size(); ++i)
		{
			if(a[i] != b[i])
			{
				cout << i; break;
			}
		}
	}
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
		cout << "Case #" << i << ": ";
		proc();
		cout << endl; 
	}
	return 0;
}
