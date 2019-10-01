def which_of_the_three(fib,fib3,fib3m):
    ## for red coin
    order=[0,0,0]
    if fib>90 and fib<167:
        order[0]=0
    if fib>166 and fib<234:
        order[0]=1
    if fib>233 and fib<301:
        order[0]=2

    ##for green coin
    if fib3m<3:
        order[1]=0
    if fib3m>2 and fib3m<7:
        order[1]=1
    if fib3m>6 and fib3m<10:
        order[1]=2

    ##for blue coin
    if fib3<3:
        order[2]=0
    if fib3>2 and fib3<7:
        order[2]=1
    if fib3>6 and fib3<10:
        order[2]=2
    return order

