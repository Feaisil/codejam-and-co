#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <math.h>

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
	vector< long int> b;
	int k, c, s;
	r(k);r(c);r(s);
	cerr << endl << "\t" << k << "\t" << c << "\t" << s << endl;
	if(k > c * s)
	{
		cout << "IMPOSSIBLE";
		return;
	}
	long d=1;
	long ci=1;
	long long kp[c];
	kp[0] = 1;
	for(int i=1; i<c; i++)
	{
		kp[i] = kp[i-1] * k;
		cerr << kp[i]<< " ";
	}
	cerr << endl;
	for(int i=0; i<k ; i++)
	{
		cerr << "=> " << i << " " << ci << " " << i*kp[c-d] << " " << d << endl;
		ci += i * kp[c-d];
		d++;
		if(d>c)
		{
			b.push_back(ci);
			d=1;
			ci=1;
		}
	}
	if(d>1)
	{
		b.push_back(ci);
	}

	ov(b);
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
