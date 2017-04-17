#!/usr/bin/env python3

import sys,time, math
cin=sys.stdin
cerr=sys.stderr
cout=sys.stdout

def rl(cin):
	"""readline and remove \n"""
	return cin.readline()[:-1]
cin.rl=lambda:rl(cin)
def rs(cin):
	return cin.rl().split()
cin.rs=lambda:rs(cin)
def ri(cin):
	return int(cin.rl())
cin.ri=lambda:ri(cin)
def riv(cin):
	return [int(x) for x in rs(cin)]
cin.riv=lambda:riv(cin)
def rf(cin):
	return float(cin.rl())
cin.rf=lambda:rf(cin)
def rfv(cin):
	return [float(x) for x in rs(cin)]
cin.rfv=lambda:rfv(cin)
def rev(i):
	o=[]	
	for x in range(1,1+len(i)): o+=[i[-x]]
	return o
def revs(s):
	return ''.join(rev(s))	
def isPrime(n):
	for i in range(2, int(math.sqrt(n))):
		if not i%n:
			return true
		
def printr(*args):
	cerr.write(', '.join([repr(x) for x in args])+'\n')
		
class bin_base:
	def __init__(self):
		pass
	def up(self):
		pass
	def lo(self):
		pass
	def cont(self):
		pass
class bin_int:
	def __init__(self, m=0, M=10):
		self.m=m-1
		self.M=M+1
		self.c=int((self.M+self.m)/2)
	def up(self):
		self.m=self.c+1
		self.c=int((self.M+self.m)/2)
		return self.c
	def lo(self):
		self.M=self.c
		self.c=int((self.m+self.M)/2)
		return self.c
	def cont(self):
		return self.m < self.M

def search(r, k, pred):
	while r.cont():
		pre=pred(r.c)
		if pre < k:
			r.up()
		else:
			r.lo()
	return r.m

def parse(cin):
	n=cin.ri()
	x=[]
	y=[]
	for i in range(n):
		v=cin.riv()
		x+=[v[0]]
		y+=[v[1]]
	return [n,x,y]
eps = pow(10,-16)

from math import *

def get_func(a):
	def sort_ang(x):
		s=1
		if x[1] < a[1]: s=-1
		print(a,x,s*acos( ( x[0] - a[0] ) / ( sqrt( pow( a[0] - x[0] ,2) + pow( a[1] - x[1] ,2) ) ) )/pi)
		return (s*acos( ( x[0] - a[0] ) / ( sqrt( pow( a[0] - x[0] ,2) + pow( a[1] - x[1] ,2) ) ) ) / pi) %2
	return sort_ang

def search(lb, i, v):
	for k in range(len(v)):
		printr(k+i, (k+i)%len(v), v[(k+i)%len(v)], lb, lb-eps)
		if v[(k+i)%len(v)]>lb - eps:
			return k
	return i
def do(l):
	n=l[0]
	x=l[1]
	y=l[2]
	v=[]
	for i in range(n):
		v+=[(x[i],y[i])]
	r=[]
	for i in range(n):
		m=3000
		vec=[get_func(v[i])(x) for x in  v[:i]+v[i+1:]]
		vec.sort()
		printr(v[i], vec)
		j=0
		for k in range(n-1):
			a0=vec[k]
			j=search((a0+1)%(2),j,vec)
			if j==k:
				m=0
				break
			m=min((j-k-1)%len(vec), m)
			if vec[j%len(vec)] < (a0+1)%2-eps:
				m=min((k-j+1)%len(vec),m)
			else:
				m=min((k-j)%len(vec),m)
			printr(j-k,j-k, m)
			if j>=n or j==k:
				break
	
		#for k in range(n):
		#	if i==k: continue
		#	eq=x[i]==x[k]
		#	a=0
		#	b=0
		#	lo=0
		#	mo=0
		#	if not eq:
		#		a=(y[k]-y[i])/(x[k]-x[i])
		#		b=y[i]-a*x[i]
		#	for j in range(n):
		#		if i==j or j==k: continue
		#		if eq: 
		#			if x[j] < x[k]: lo+=1
		#			if x[j] > x[k]: mo+=1
		#		else:
		#			if y[j] < a*x[j]+b -eps: lo+=1
		#			if y[j] > a*x[j]+b +eps: mo+=1
		#	m=min(lo,mo,m)
		if m==3000:
			m=0
		r+=[m]
	return '\n'.join(['']+[str(x) for x in r])

def main():
	start = time.time()
	T=cin.ri()
	cerr.write("Going to process {} cases\n".format(T))
	k=0
	for Ti in range(1,T+1):
		if math.log(100*Ti/T) > k:
			cerr.write("case {}...".format(Ti))
		print("case #{0}: {1}".format(Ti, do(parse(sys.stdin))))
		if math.log(100*Ti/T) > k:
			k+=1
			cerr.write("duration {}\n".format(time.time()-start))
	cerr.write("duration {0}\n".format(time.time()-start))

if __name__=="__main__":
	main()

