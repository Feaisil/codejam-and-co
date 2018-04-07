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

def flip(c):
	if c == '-': return '+'
	return '-'
def flipPancakes(s, p, l):
	for i in range(p, p+l):
		s[i]=flip(s[i])

def parse(cin):
	l=cin.rs()
	return (list(l[0]),int(l[1]))

def do(l):
	s=l[0]
	k=l[1]
	flips=0
	for i in range(len(s) - k + 1):
		if s[i] == '-':
			flipPancakes(s, i, k)
			flips+=1
	if '-' in s:
		return "IMPOSSIBLE"
	else:
		return flips

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

