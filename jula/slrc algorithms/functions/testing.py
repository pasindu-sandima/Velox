big1=[]
for j in range(7):
    rownum=str(j+1)
    maze=[]
    for i in range(7):
        maze.append(rownum)
        maze[i]=maze[i]+str(i+1)+' '
        maze[i]=maze[i]+'0'
    big1+=maze
#print big1

big2=[]
for j in range(7):
    rownum=7*j
    maze=[]
    for i in range(7):
        if len(str(rownum+1+i))==2:
            maze.append(str(rownum+1+i))
        else:
            maze.append('0'+str(rownum+1+i))
            
    if j%2!=0:
        maze=maze[::-1]
    big2+=maze
#print big2

for i in range(49):
    big1[i]=big1[i]+' '+big2[i]

big1=['11 0 01', '12 0 02', '13 0 03', '14 0 04', '15 0 05', '16 0 06', '17 0 07',
      '21 0 14', '22 0 13', '23 0 12', '24 0 11', '25 0 10', '26 0 09', '27 0 08',
      '31 0 15', '32 0 16', '33 0 17', '34 0 18', '35 0 19', '36 0 20', '37 0 21',
      '41 0 28', '42 0 27', '43 0 26', '44 0 25', '45 0 24', '46 0 23', '47 0 22',
      '51 0 29', '52 0 30', '53 0 31', '54 0 32', '55 0 33', '56 0 34', '57 0 35',
      '61 0 42', '62 0 41', '63 0 40', '64 0 39', '65 0 38', '66 0 37', '67 0 36',
      '71 0 43', '72 0 44', '73 0 45', '74 0 46', '75 0 47', '76 0 48', '77 0 49']

for k in range(7):
    print big1[7*k:7*(k+1)]

