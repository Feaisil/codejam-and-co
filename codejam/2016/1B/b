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
	l=cin.rs()
	return l

def dist(r,ab=False):
	a=r[0]
	b=r[1]
	r=0
	for i in range(len(a)):
		r=10*r
		r+=int(a[i]) - int(b[i])
	printr("dist",a,b,r%pow(10,len(a)))
	if ab:
		return abs(r)
	return r%pow(10,len(a))

def sub_do(cr,jr, c_b=False, l_b=False):
	for k in range(len(cr)):
		printr(">>>>",cr,jr, c_b, l_b, k)
		if cr[k] == '?':
			if jr[k] == '?':
				if l_b:
					cr[k] = '9'
					jr[k] = '0'
				elif c_b:
					jr[k] = '9'
					cr[k] = '0'
				else:
					r1=dist(sub_do(cr[k+1:],jr[k+1:], True, False))
					r2=pow(10,len(cr[k+1:])) - dist(sub_do(cr[k+1:],jr[k+1:], False, True))
					r3=dist(sub_do(cr[k+1:],jr[k+1:]),True)
					printr(r1,r2,r3)
					if r3<=r2 and r3<=r1 or k==len(cr)-1:
						cr[k] = '0'
						jr[k] = '0'
					elif r2<r1:
						jr[k] = '1'
						cr[k] = '0'
						l_b = True
					else:
						jr[k] = '0'
						cr[k] = '1'
						c_b = True

			else:
				if l_b:
					cr[k] = '9'
				elif c_b:
					cr[k] = '0'
				# elif k==len(c)-1:
				# 	cr[k] = str(int(jr[k])-1)
				else:
					r1=dist(sub_do(cr[k+1:],jr[k+1:], True, False))
					r2 = pow(10, len(cr[k + 1:])) - dist(sub_do(cr[k + 1:], jr[k + 1:], False, True))
					r3=dist(sub_do(cr[k+1:],jr[k+1:]),True)
					if r3<=r2 and r3<=r1 or k==len(cr)-1:
						cr[k] = jr[k]
					elif r2<r1:
						if jr[k] == '0':
							cr[k]  = '9'
						else:
							cr[k] = str(int(jr[k])-1)
						l_b = True
					else:
						if jr[k] == '9':
							cr[k]  = '0'
						else:
							cr[k] = str(int(jr[k])+1)
						c_b = True
					cr[k] = jr[k]
		elif jr[k] == '?':
			if c_b:
				jr[k] = '9'
			elif l_b:
				jr[k] = '0'
			# elif k==len(c)-1:
			# 	jr[k] = str(int(cr[k])-1)
			else:
				r1=dist(sub_do(cr[k+1:],jr[k+1:], True, False))
				r2 = pow(10, len(cr[k + 1:])) - dist(sub_do(cr[k + 1:], jr[k + 1:], False, True))
				r3=dist(sub_do(cr[k+1:],jr[k+1:]),True)
				if r3<=r2 and r3<=r1 or k==len(cr)-1:
					jr[k] = cr[k]
					printr("la")
				elif r2>r1:
					if cr[k] == '0':
						jr[k]  = '9'
					else:
						jr[k] = str(int(cr[k])-1)
					c_b = True
				else:
					if cr[k] == '9':
						jr[k]  = '1'
					else:
						jr[k] = str(int(cr[k])+1)
					l_b = True
		elif cr[k] > jr[k] and not l_b:
			c_b = True
			l_b = False
		elif cr[k] < jr[k] and not c_b:
			c_b = False
			l_b = True
		printr("<<<<<",cr,jr, c_b, l_b, k)
	return cr, jr


def do(l):
	c=l[0]
	j=l[1]
    #
	# c_b=False
	# l_b=False
	# cr=[x for x in c]
	# jr=[x for x in j]
	# for k in range(len(c)):
	# 	printr(k, cr, jr, c , j)
	# 	if c[k] == '?':
	# 		if j[k] == '?':
	# 			if l_b:
	# 				cr[k] = '9'
	# 				jr[k] = '0'
	# 			elif c_b:
	# 				jr[k] = '9'
	# 				cr[k] = '0'
	# 			else:
	# 				cr[k]='0'
	# 				jr[k]='0'
	# 		else:
	# 			if l_b:
	# 				cr[k] = '9'
	# 			elif c_b:
	# 				cr[k] = '0'
	# 			# elif k==len(c)-1:
	# 			# 	cr[k] = str(int(jr[k])-1)
	# 			else:
	# 				cr[k] = jr[k]
    #
	# 	elif j[k] == '?':
	# 		if c_b:
	# 			jr[k] = '9'
	# 		elif l_b:
	# 			jr[k] = '0'
	# 		# elif k==len(c)-1:
	# 		# 	jr[k] = str(int(cr[k])-1)
	# 		else:
	# 			jr[k] = cr[k]
    #
	# 	elif c[k] > j[k] and not l_b:
	# 		c_b=True
	# 		l_b=False
	# 	elif c[k] < j[k] and not c_b:
	# 		c_b = False
	# 		l_b = True
	cr,jr = sub_do([x for x in c],[x for x in j])
	return ''.join(cr) + ' ' + ''.join(jr)

def main():
	start = time.time()
	T=cin.ri()
	cerr.write("Going to process {} cases\n".format(T))
	k=0
	for Ti in range(1,T+1):
		if math.log(100*Ti/T) > k:
			cerr.write("case {}...".format(Ti))
		print("Case #{0}: {1}".format(Ti, do(parse(sys.stdin))))
		if math.log(100*Ti/T) > k:
			k+=1
			cerr.write("duration {}\n".format(time.time()-start))
	cerr.write("duration {0}\n".format(time.time()-start))

if __name__=="__main__":
	main()

