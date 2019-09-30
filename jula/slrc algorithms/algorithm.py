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

def get_colored_list(big1,order):
    reds=[]
    greens=[]
    blues=[]
    for i in big1:
        if i[1]==1:
            reds.append(i)
        if i[1]==2:
            greens.append(i)
        if i[1]==3:
            blues.append(i)

    reds.append(reds[0][3]**3+reds[1][3]**2+reds[2][3]**1)
    greens.append(greens[0][3]**3+greens[1][3]**2+greens[2][3]**1)
    blues.append(blues[0][3]**3+blues[1][3]**2+blues[2][3]**1)

    ##order [r,g,b]
    ##for high 2
    ##for medium 1
    ##for low 0
    
    cell_list=[[reds[order[0]],reds[3]],[greens[order[1]],greens[3]],[blues[order[2]],blues[3]]]
    ## sorting for order
    swapped=1
    while swapped==1:
        swapped=0
        for i in range(len(cell_list)-1):
            if cell_list[i][1]>cell_list[i+1][1]:
                temp=cell_list[i+1]
                cell_list[i+1]=cell_list[i]
                cell_list[i]=temp
                swapped=1

    return cell_list

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
    
def get_inputs_cells():
    inputs=[]
    while len(inputs)!=9:
        try:
            k=raw_input('enter cell and color  ').strip().split()
            if len(k[0])>2:
                print "wrong cell"
            elif (int(k[0][0])>8 or int(k[0][1])>8):
                print "wrong cell"
            elif (int(k[1])<0 or int(k[1])>3):
                print "wrong color"        
            else:
                inputs.append(k)
        except:
            print "something wrong with the inputs"
    return inputs

def printmaze():
    big1=[[11, 0, 1, 1], [12, 0, 2, 0], [13, 0, 3, 0], [14, 0, 4, 0], [15, 0, 5, 0], [16, 0, 6, 0], [17, 0, 7, 0], [18, 0, 8, 0],
          [28, 0, 9, 0], [27, 0, 10, 0], [26, 0, 11, 0], [25, 0, 12, 0], [24, 0, 13, 0], [23, 0, 14, 0], [22, 0, 15, 0], [21, 0, 16, 0],
          [31, 0, 17, 0], [32, 0, 18, 0], [33, 0, 19, 0], [34, 0, 20, 0], [35, 0, 21, 0], [36, 0, 22, 0], [37, 0, 23, 0], [38, 0, 24, 0],
          [48, 0, 25, 0], [47, 0, 26, 0], [46, 0, 27, 0], [45, 0, 28, 0], [44, 0, 29, 0], [43, 0, 30, 0], [42, 0, 31, 0], [41, 0, 32, 0],
          [51, 0, 33, 0], [52, 0, 34, 0], [53, 0, 35, 0], [54, 0, 36, 0], [55, 0, 37, 0], [56, 0, 38, 0], [57, 0, 39, 0], [58, 0, 40, 0],
          [68, 0, 41, 0], [67, 0, 42, 0], [66, 0, 43, 0], [65, 0, 44, 0], [64, 0, 45, 0], [63, 0, 46, 0], [62, 0, 47, 0], [61, 0, 48, 0],
          [71, 0, 49, 0], [72, 0, 50, 0], [73, 0, 51, 0], [74, 0, 52, 0], [75, 0, 53, 0], [76, 0, 54, 0], [77, 0, 55, 0], [78, 0, 56, 0],
          [88, 0, 57, 0], [87, 0, 58, 0], [86, 0, 59, 0], [85, 0, 60, 0], [84, 0, 61, 0], [83, 0, 62, 0], [82, 0, 63, 0], [81, 0, 64, 0]]
    return big1

while(1):
    inputs=get_inputs_cells()
    big1=printmaze()
    pillarsum=get_inputs_pillars()
    fib_numbers=findfib(pillarsum)


    ##updating cells with colors

    for i in range(len(inputs)):
        for j in range(len(big1)):
            if int(inputs[i][0])==big1[j][0]:
                big1[j][1]=int(inputs[i][1])



    ##updating cell numbers
    ## red=1
    ## green=2
    ## blue=3
                
    increment=1
    for i in range(1,len(big1)): 
        if big1[i-1][1]==1:
            increment=2
        elif big1[i-1][1]==2:
            increment=3
        elif big1[i-1][1]==3:
            increment=4
        big1[i][3]=big1[i-1][3]+increment

    order=which_of_the_three(pillarsum,fib_numbers[0],fib_numbers[1])
    cell_list=get_colored_list(big1,order)





    ## printing the output
    outmaze=[]
    for k in range(8):
        if k%2==0:
            outmaze.extend(big1[8*k:8*(k+1)])
            ##print big1[8*k:8*(k+1)]
        else:
            temp=big1[8*k:8*(k+1)]
            outmaze.extend(temp[::-1])
            ##print temp[::-1]

    distances=[]
    for i in outmaze:
        if (len(str(i[3]))==1):
            distances.append('00'+str(i[3]))
        elif (len(str(i[3]))==2):
            distances.append('0'+str(i[3]))
        else:
            distances.append(str(i[3]))


            
    ##for i in range(8):
      ##  for j in range(8):
            ##print distances[i*8+j],
        ##print ''

    ##print big1
    ##print outmaze

    print cell_list

