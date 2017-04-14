f = open('input','r')
o = open('output','w')

import time
start = time.time()
N = int(f.readline()[:-1])

for Ni in range(N):
        #parse args
        x,r,c = [int(i) for i in f.readline().strip('\n').split(' ')]

        #logic
        result = not( (r < x and c < x) or (r*c)%x >0 or x > 6 )
        result = result and not ((r+1<x or c+1<x))
        
        #report
        if result:
                result = "GABRIEL"
        else:
                result = "RICHARD"
        o.write("case #{0}: {1}\n".format(Ni+1, result))
        print("case #{0}: {1}\n".format(Ni+1, result))
#conclude
o.close()
print("duration {0}".format(time.time()-start))
