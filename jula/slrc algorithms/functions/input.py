def getinputs():
    inputs=[]
    while len(inputs)!=9:
        try:
            k=raw_input('enter cell and color  ').strip().split()
            if len(k[0])>2:
                print "wrong cell"
            elif (int(k[0][0])>7 or int(k[0][1])>7):
                print "wrong cell"
            elif (int(k[1])<0 or int(k[1])>4):
                print "wrong color"        
            else:
                inputs.append(k)
        except:
            print "something wrong with the inputs"
    return inputs


print getinputs()
