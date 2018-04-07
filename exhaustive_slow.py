#!/usr/bin/env python3

# dumb solution

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
	l=cin.riv()
	return l
# count ingredients returns number of T and M in a slice
def cnting(p,r,c,m,n):
	t = 0
	k = 0
	for i in range(r,m+1):
		for j in range(c,n+1):
			if p[i][j] == 'T': t+=1
			else: k+=1
			#printr(i,j,p[i][j])
	return (t,k)
def isValid(p,r,c,m,n,l,h):
	(t,k) = cnting(p,r,c,m,n)
	#printr(r,c,m,n,t,k,l,h,t>=l and t<=h and k>=l and k<=h) 
	return t>=l and t<=h and k>=l and k<=h
def isOlap(a,b):
	return (a[2] < b[0] or a[0] > b[2] or a[3] < b[1] or a[1] > b[3])
def score(cl):
	k = 0
	for e in cl:
		k+=(e[2]-e[0]+1)*(e[3]-e[1]+1)
	return k

def walk(sl,cl=[],i=-1):
	import copy
	res = []
	if i == -1:
		for j in range(len(sl)):
			res += [walk(sl, copy.deepcopy(cl), j)]
	else:
		cl += [sl[i]]
		for j in range(i+1,len(sl)):
			a=True
			for e in cl:
				if not isOlap(e, sl[j]):
					a=False
			if a:
				res += [walk(sl, copy.deepcopy(cl), j)]
	#printr("Walk: ",cl,i,res, score(cl))
	if not res: return cl
	c = 0
	maxres = []
	for e in res:
		ci = score(e)
		if ci > c:
			maxres = e
			c = ci
	#printr("walks: ",maxres, c)
	return maxres

		
def do(l):
	(r,c,l,h)=l
	#printr (r,c,l,h)
	p = []
	for i in range(r):
		p += [cin.rl()]
	#printr(p,p[2:3])
	sl = []
	for i in range(r):
		for j in range(c):
			for m in range(i,r):
				for n in range(j,c):
					if isValid(p,i,j,m,n,l,h):
						sl += [(i,j,m,n)]
	#printr(sl, len(sl))
	res = walk(sl)
	resscore = score(res)
	print(resscore)
	for e in res: print(' '.join([str(x) for x in e]))
	return l

def main():
	start = time.time()
	T=1 #cin.ri()
	cerr.write("Going to process {} cases\n".format(T))
	k=0
	for Ti in range(1,T+1):
		if math.log(100*Ti/T) > k:
			cerr.write("case {}...".format(Ti))
		#print("case #{0}: {1}".format(Ti,
		do(parse(sys.stdin))
		if math.log(100*Ti/T) > k:
			k+=1
			cerr.write("duration {}\n".format(time.time()-start))
	cerr.write("duration {0}\n".format(time.time()-start))

if __name__=="__main__":
	main()

