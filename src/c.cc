#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

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
	long long
		n,
		k,
		m,
		M; //= &n+1000;
	cin >> n >> k;
	typedef list<pair<long long, long long>> aggregqueue;
	aggregqueue q;
	q.emplace_back(n,1);
	
	
	while(k>0)
	{
		M = q.front().first/2;
		m = (q.front().first-1)/2;
		if(q.front().second < k)
			k -= q.front().second;
		else
			k = 0;
		//cerr << "k," << k << ": " << endl;
		//for(auto e:q) cerr << "\t" << e.first << ", " << e.second << endl;
		aggregqueue::reverse_iterator it=q.rbegin();
		if(q.size()>1 and it->first == M or q.size() > 2 and (++it)->first == M)
		{
			it->second += q.front().second;
		}
		else
		{
			q.emplace_back(M, q.front().second);
		}
		if(q.back().first == m)
		{
			q.back().second += q.front().second;
		}
		else
		{
			q.emplace_back(m, q.front().second);
		}
		q.pop_front();
	}
	cout << M << " " << m;
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
