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
	l=cin.riv()
	return l

def opp(c):
	if c == 'R': return 'G'
	if c== 'Y': return 'V'
	if c== 'B': return 'O'
	if c == 'G': return 'R'
	if c== 'V': return 'Y'
	if c== 'O': return 'B'
def try_before(res):
	c = res[-1]
	for i in range(0,len(res) - 1):
		printr(opp(c), c)
		if (res[i] in ['R','Y','B'] or res[i] == opp(c)) and res[i] != c and (res[i+1] in ['R','Y','B'] or res[i] == opp(c)) and res[i+1] != c:
				res = res[:i+1] + [c] + res[i+1:]
				return res
	return False

def do(l):
	[n,r,o,y,g,b,v] = l
	
	n-=1
	if r>0:
		res = ["R"]
		r-=1
	elif b > 0:
		res = ["B"]
		b-=1
	elif y > 0:
		res = ["Y"]
		y-=1
	for i in range(n):
		printr(res)
		if res[-1] == "R":
			if g:
				res+=["G"]
				g-=1
			elif b:
				res+=["B"]
				b-=1
			elif y:
				res+=["Y"]
				y-=1		
			else:
				res = try_before(res)
				r-=1
				if not res:
					return "IMPOSSIBLE"
		elif res[-1] == "Y":
			if v:
				res+=["V"]
				v-=1
			elif b:
				res+=["B"]
				b-=1
			elif r:
				res+=["R"]
				r-=1		
			else:
				res = try_before(res)
				y-=1
				if not res:
					return "IMPOSSIBLE"
		elif res[-1] == "B":
			if o:
				res+=["O"]
				o-=1
			elif r:
				res+=["R"]
				r-=1
			elif y:
				res+=["Y"]
				y-=1
			else:
				res = try_before(res)
				b-=1
				if not res:
					return "IMPOSSIBLE"
		elif res[-1] == "G":
			if r:
				res+=["R"]
				r-=1		
			else:
				return "IMPOSSIBLE"
		elif res[-1] == "O":
			if b:
				res+=["B"]
				b-=1		
			else:
				return "IMPOSSIBLE"
		elif res[-1] == "V":
			if y:
				res+=["Y"]
				y-=1		
			else:
				return "IMPOSSIBLE"
	
	if r or y or b or g or o or v:
		return "IMPOSSIBLE"
	if res[-1] == 'O' and res[0] != 'B':
		return "IMPOSSIBLE"
	if res[-1] == 'G' and res[0] != 'R':
		return "IMPOSSIBLE"
	if res[-1] == 'V' and res[0] != 'Y':
		return "IMPOSSIBLE"
	if res[-1] == res[0]:
		return "IMPOSSIBLE"
	return  ''.join(res)

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

