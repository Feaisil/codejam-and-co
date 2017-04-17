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
		

def parse(cin):
	l=cin.riv()
	return l

#f tosel
#c complexity
#i index
def resolve(c, f, k, i=1):
	if c==0 or f>k:
		return i,f-1
	return resolve( c-1, f+1, k, i+(f-1)*pow(k,c-1) )
	
def do(l):
	k=l[0]
	c=l[1]
	s=l[2]
	
	r=[]
	f=0
	i=0
	end = pow(k,c)
	n=0
	while f < k and i < end and n<=s:
		n+=1
		i,f = resolve(c,f+1,k, 1)
		r+=[str(i)]
	if i>end:
		if f==k:
			r[-1]=str(end)
		else:
			cerr.write("imp1\n")
			cerr.write(" ".join(r)+"\n")
			return "IMPOSSIBLE"
	if n>s:
		cerr.write("imp2")
		return "IMPOSSIBLE"
	return " ".join(r)
	if k==s:
		s=0
		for i in range(c):
			s+=pow(k,i)
		for i in range(k):
			r+=[str(1+i*s)]
	else:
		f=0
		n=0
		while f<k:
			n+=1
			ind=1
			for i in range(c):
				ind += f*pow(k,c-i-1)
				f+=1
		
	return ' '.join(r)

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

