def get_inputs_pillars():
    pillars=[]
    ## if left==1
    ## if right==2
    ## if both==3
    while len(pillars)!=4:
        pillars=[]
        for i in range(4):
            k=raw_input('input pillar'+' '+str(i+1)+' ').strip()
            if len(k)!=1:
                print "wrong input"
                break
            else:
                pillars.append(int(k)*(i+1)*10)
        return sum(pillars)
print get_inputs_pillars()
