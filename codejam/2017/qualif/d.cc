#include <iostream>
#include <vector>
#include <set>
#include <sstream>

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

typedef vector<vector<int>> ma_t;
const int
	hm = 1<<0<<8, // horizontal mark
	dm = 1<<1<<8 , // diag mark
	bm = hm^dm; // both mark
const char o = 'o', p='+', x='x';
void flag(ma_t& s, int x, int y, char c)
{
	int n = s.size();
	for(int i=0; i<n; i++)
	{
		if(c==o or c=='x')
		{
			if(i!=y) s[x][i]|=hm;
			if(i!=x) s[i][y]|=hm;
		}
		if(c==o or c==p and i>0)
		{
			if(x-i >= 0 and y-i >= 0) s[x-i][y-i]|=dm;
			if(x-i >= 0 and y+i <  n) s[x-i][y+i]|=dm;
			if(x+i <  n and y-i >= 0) s[x+i][y-i]|=dm;
			if(x+i <  n and y+i <  n) s[x+i][y+i]|=dm;
		}
	}
}
int points(char c)
{
	switch(c)
	{
		case 'o':
		case 'O':
			return 2;
		case '+':
		case 'x':
		case 'X':
			return 1;
		default:
			return 0;
	}
}
void proc()
{
	int n, m, score = 0, changes = 0;
	cin >> n >> m;
	ma_t s(n,vector<int> (n,'.'));
	ostringstream oss;
	
	//cerr << n << " " << m  << " " << bm   << " " <<  hm   << " " <<  dm << endl;
	for(int k=0; k<m;k++)
	{
		char c;
		int x,y;
		cin >> c >> x >> y;
		x--, y--;
		flag(s, x, y, c);
		s[x][y] = c;
		//score += points(c);
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			/*
	cerr << n << " " << m << endl;
	for(auto v: s) { for(auto c: v){ cerr << char(c);} cerr << endl; }
	for(auto v: s) { for(auto c: v){ cerr << std::hex << c << "\t";} cerr << endl; }
	cerr <<  "fw " <<i
		<< " " << j 
		<< " " <<  s[i][j]
		<< " " <<  bm  
		<< " "<< (s[i][j]&!bm) 
		<< " "<< (s[i][j]^!bm) 
		<< " "<< (s[i][j]^!bm&bm) 
		<< " "<< ((s[i][j]^!bm)&bm) 
		<< endl; */
			if((s[i][j]&bm) == 0 and char(s[i][j]) != o){
				s[i][j]=o;
				flag(s,i,j,o);
				oss << o << " " << i+1 << " " << j+1 << endl;changes++;
			}
			else if((s[i][j]&hm) == 0 and char(s[i][j]) == '.'){
				s[i][j]=x;
				flag(s,i,j,x);
				oss << x << " " << i+1 << " " << j+1 << endl;changes++;
			}
			else if((s[i][j]&dm) == 0 and char(s[i][j]) == '.'){
				s[i][j]=p;
				flag(s,i,j,p);
				oss << p << " " << i+1 << " " << j+1 << endl;changes++;
			}
			score += points(s[i][j]);
			
		}
	}
	
	cerr << n << " " << m << endl;
	for(auto v: s) { for(auto c: v){ cerr << char(c) ;} cerr << endl; }
	for(auto v: s) { for(auto c: v){ cerr << std::hex << c << "\t";} cerr << endl; }
	
	cout << score << " " << changes << endl << oss.str();
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
		cerr << "Starting case " << i ;
		cout << "Case #" << i << ": ";
		
		try{
			proc();
		}catch(exception& e){ cerr << "case i failed: " << e.what() << endl; }
		 
	}
	return 0;
}
