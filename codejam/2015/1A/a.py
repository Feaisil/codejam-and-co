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
		

def parse(cin):
	l=[cin.ri(),cin.riv()]
	return l

def do(l):
	n=l[0]
	m=l[1]

	desm=0
	for i in range(n-1):
		d=m[i] - m[i+1]
		if d>0:
			if d>desm:
				desm=d
		printr(i, d,desm)
	r1=0
	r2=0
	for i in range(n-1):
		d=m[i] - m[i+1]
		if d>0:
			r1+=d
		if desm>m[i]:
			r2+=m[i]
		else:
			r2+=desm
		printr(i, d, desm, r1, r2)
	return str(r1) + " " + str(r2)

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

