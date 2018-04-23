#include <iostream>
#include <algorithm>
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
template<typename T>
void ov(const vector<vector<T>> &i)
{
	for(auto v: i)
	{
		ov(v); cout << endl;
	}
}

void proc()
{
	int r, c, h, v, chocs =0;
	cin >> r >> c >> h >> v;
	vector<vector<char>> m(r, vector<char>(c,'.'));
	for(auto&v : m) for(auto&e:v) cin >> e;
	for(auto&v : m) for(auto&e:v) if(e=='@') chocs++;
	if(chocs == 0)
{
		cout << "POSSIBLE";
		return;
	}
	if(chocs%((h+1)*(v+1)) != 0 )
	{
		cout << "IMPOSSIBLE";
		return;
	}
	int ch, cv;
	int curi = 0, curj = 0;
	vector<int> cuth;
	cuth.push_back(-1);
	vector<vector<int>> cutv(v, vector<int>()),cutv2,cutv3(v, vector<int>());
	for(int i=0; i<m.size(); ++i)
	{
		for(int j=0; j<m[0].size(); ++j)
		{
			if(m[i][j]=='@') curi++;
		}
		if( curi%(chocs/(h+1)) ==  0 and curi> 0) 
		{
			curi =0 ;
			int cnt = 0;
			for(int l=0; l<c; ++l)
			{
				for(int k=cuth.back()+1; k<=i; ++k)
				{
					if(m[k][l]=='@') cnt++;					
				}
				if(cnt % (chocs/((h+1)*(v+1)))==0 and cnt > 0 and cnt < chocs/(h+1))
				{
					cutv[cnt / (chocs/((h+1)*(v+1)))-1].push_back(l);
				}
			}
			cuth.push_back(i);
			if(cutv2.empty()) cutv2 = cutv;
			else
			{
				for(int l=0; l<v;++l)
				{
					cutv3[l].reserve(cutv2[l].size()+cutv[l].size());
  					auto it=
					  set_intersection (
						  cutv[l].begin(), cutv[l].end(),
						  cutv2[l].begin(),cutv2[l].end(),
					  	  cutv3[l].begin());
					if(it == cutv3[l].begin())
					{
						cout <<  "IMPOSSIBLE";
						return;
					}
					cutv2[l].assign(cutv3[l].begin(), it);
				}
			}
				for(int l=0; l<v;++l)
				{
					cutv3[l].clear();
					cutv[l].clear();
				}
		}
	}
	if(cuth.size()!=h+2)
	{
						cout << "IMPOSSIBLE";
						return;
	}
	cout << "POSSIBLE";
	return;
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
