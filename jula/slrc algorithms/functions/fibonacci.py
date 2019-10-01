def findfib(x):
    fib=1
    prefib=0
    if x==1:
        return prefib
    if x==2:
        return fib
    else:
        for i in range(x-1):
            temp=prefib
            prefib=fib
            fib+=temp
        word_fib=str(fib)
        return map(int,[word_fib[2],word_fib[-3]])
        
