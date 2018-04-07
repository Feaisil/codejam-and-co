#include <iostream>
#include <vector>
#include <set>
#include <map>
#include  <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define ALL(v) v.begin(),v.end()
#define UNIQUE(c) (c).resize(distance((c).begin(), unique(ALL(c))))
using namespace std;

typedef long long int LL;
typedef long long unsigned int LLU;

typedef vector<int>   VI;       typedef vector<bool> VB;
typedef vector<VI>   VVI;       typedef vector<double> VD;
typedef vector<VVI> VVVI;       typedef vector<VD> VDD;

typedef pair<int,int> PI;       typedef pair<double,double> PD;
typedef pair<PI,int> PII;

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
		cerr << v << " ";
	}
}

void proc()
{
    cerr << "====" << endl;
    int n, p;
    cin >> n >> p;
    cerr << "\t" << n << " " << p << endl;
    VI r(n,0);
	FOR(i,n) cin >> r[i];
	VVI q(n, VI(p,0));
	FOR(i,n) FOR(j,p) cin >> q[i][j];

	vector<multimap<int, int>> m(n),mc(n); //size, id
	FOR(i,n)
	{
        FOR(j, q[i].size())
        {
            int t = (q[i][j]/r[i]);
            if(t>0 and t*r[i]*0.9 <=  q[i][j] and t*r[i]*1.1 >= q[i][j])
            {
                m[i].insert(make_pair(t,j));
            }
            if(  (t+1)*r[i]*0.899999 <= q[i][j] and (t+1)*r[i]*1.100001 >= q[i][j])
            {
                m[i].insert(make_pair(t+1,j));
            }
            if(t>0 and  (t-1)*r[i]*0.899999 <= q[i][j] and (t-1)*r[i]*1.100001 >= q[i][j])
            {
                m[i].insert(make_pair(t-1,j));
            }
        }
	}
	cerr << endl;
	for(auto ma:m){ for(auto pa:ma) {cerr << pa.first << " " << pa.second << "," ;} cerr << endl;}

    FOR(i, n){ mc[i].clear(); mc[i].insert(m[i].begin(), m[i].end());}
	int maxres=0;
	int j=0;
	FOR(j,n)
	{
        FOR(i, n){ m[i].clear(); m[i].insert(mc[i].begin(), mc[i].end());}
        int res=0;
        for(auto it = m[j].begin(); it != m[j].end(); ++it)
        {
            int s = it->first;
            bool f = true;
            for(int i=0;i<n; i++)
            {
                if(i != j)
                    f = m[i].find(s) != m[i].end();
            }
            if(f)
            {
                {
                    auto em = it;
                    em++;
                    auto e = it;
                    while(em != m[j].end())
                    {
                        if(em->second == e->second)
                        {
                            m[j].erase(em);
                            break;
                        }
                        ++em;
                    }
                }
                for(int i=0;i<n; i++)
                {
                    if(i==j)continue;
                    auto e = m[i].find(s);
                    m[i].erase(e);
                    auto em = m[i].find(s-1);
                    while(em != m[i].end() and em->first == s-1)
                    {
                        if(em->second == e->second)
                        {
                            m[i].erase(em);
                            break;
                        }
                        ++em;
                    }
                    em = m[i].find(s+1);
                    while(em != m[i].end() and em->first == s+1)
                    {
                        if(em->second == e->second)
                        {
                            m[i].erase(em);
                            break;
                        }
                        ++em;
                    }
                }
                    res+=1;
            }

        }
        maxres = max(maxres, res);
    }

	ov(r);
	cerr << endl;
	for(auto ma:m){ for(auto pa:ma) {cerr << pa.first << " " << pa.second << "," ;} cerr << endl;}
	cout << maxres;
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
