import numpy
import matplotlib
import cv2

a=218922995834555169026
b=354224848179261915075
fib=0
list1=[]
list2=[]

list1.append(int(str(b)[len(str(fib))-3]))
list2.append(int(str(b)[2]))
             

for i in range(200):
    fib=a+b
    #print(str(fib)[len(str(fib))-3])
    print(str(fib)[2])
    list1.append(int(str(fib)[len(str(fib))-3]))
    list2.append(int(str(fib)[2]))
    a=b
    b=fib


    
    
