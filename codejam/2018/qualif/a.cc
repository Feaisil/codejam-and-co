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
	int d;
	string p;
	
	cin >> d >> p;
	int str = 1;
	int dmg = 0;
	int min_dmg = 0;
	for(char c: p)
	{
		if(c=='C')
		{
			str *= 2;
		}
		else
		{
			min_dmg++;
			dmg += str;
		}
	}
	
	if(min_dmg > d)
	{
		cout << "IMPOSSIBLE";
		return;
	}
	int res = 0;
	while(dmg > d)
	{
		int c_str = str/2;
		//cerr << p << " " << d << " " << dmg << endl;
		for(auto it=p.rbegin(); it!= p.rend()-1; ++it)
		{
			if(*it == 'C')  c_str/=2;
			if(*it == 'S' and *(it+1) == 'C')
			{
				swap(*it, *(it+1));
				break;
			}
		}
		res += 1;
		dmg -= c_str;
	}
	//cerr << p << " " << d << " " << dmg << endl;
	cout << res;
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
