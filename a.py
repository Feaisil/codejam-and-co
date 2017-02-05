f = open('input','r')
O = open('output','w')

import time
from math import atan2, pi

start = time.time()
T= int(f.readline()[:-1])
eps=1e-16
tanT=0
jobT=0
sortT=0
count=0
def getEndId(ang, begId, endId):
        for i in range(len(ang)):
                if (ang[(endId + i)%len(ang)]%2 - ang[begId]%2)%2  > 1 - eps:
                        return (endId + i - 1)%len(ang)
                if (endId+i)%len(ang) == begId:
                        return begId
                global count
                count+=1
        return begId
                
                
for Ti in range(T):
        print(Ti)
        O.write("case #{0}:\n".format(Ti+1))
        #parse args
        N = int(f.readline().strip('\n'))

        xy=[]
        for k in range(N):
                xy+=[[float(i) for i in f.readline().strip('\n').split(' ')]]

        #logic
        for t in xy:
                k=6000
                ang = []
                tanT -= time.time() 
                for o in xy:
                        if o == t:
                                continue
                        ang += [(atan2(o[0]-t[0], o[1]-t[1])) / pi]
                tanT += time.time() 

                sortT -= time.time() 
                ang.sort()
                sortT += time.time()
                
                jobT -= time.time() 
                eid = 1
                for eib in range(len(ang)):
                        eid = getEndId(ang, eib,eib+1)
                        eid = eid % len(ang)
                        
                        k=min(k,max(0,min((eib-eid)%len(ang), (eid + len(ang) - eib)%len(ang))))
                        
                jobT += time.time()
                O.write(str(k)+'\n')

#conclude
O.close()

print(tanT, sortT, jobT , count)
