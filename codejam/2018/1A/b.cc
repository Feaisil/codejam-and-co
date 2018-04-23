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

long long items(long long elapsed, long long mi, long long si, long long pi)
{
	return min(mi, max(0ll,(elapsed - pi)/si));
}
long long items(long long elapsed, int r, vector<long long> m, vector<long long> s, vector<long long> p)
{
	vector<long long> res(m.size(),0);
	for(long long i=0; i<m.size(); ++i)
	{
		res[i]=items(elapsed, m[i],s[i],p[i]);
	}
	sort(res.begin(), res.end());
	long long resu = 0;
	for(long long i=0; i<r ; ++i)
	{
		resu += res[res.size()-1-i];
	}
	return resu;
}
void proc()
{
	int r, b, c;
	cin >> r >> b >> c;
	vector<long long> m;
	vector<long long> s;
	vector<long long> p;
	vector<long long> nb;
	
	long long secstart = 1000000000;
	long long secend = 0;
	for(int i=0; i<c; ++i){
		long long mi, si, pi;
		cin >> mi >> si>>pi;
		m.push_back(mi);
		s.push_back(si);
		p.push_back(pi);
		nb.push_back( pi + si);
		secend = max(secend, pi+si*mi);
		secstart = min(pi, secstart);
	}
	
	for(
		long long i = (secend + secstart)/2; true;
		i = (secend+secstart)/2)
	{
		if(secstart == secend - 1){
			cout << secend ; return;
		}
		auto e = items(i, r, m,s,p);
		if( e >= b)
		{
			secend = i;
		}
		else if(e < b)
		{
			secstart = i;
		}
	}

}

int main()
{
	int t;
	int n;
	int j;
	r(t);
	for(int i = 1; i<t+1; i++)
	{
		cout << "Case #" << i << ": ";
		proc();
		cout << endl; 
	}
	return 0;
}
