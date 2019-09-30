def printmaze():
    big1=[['11', '0', '01'], ['12', '0', '02'], ['13', '0', '03'], ['14', '0', '04'], ['15', '0', '05'], ['16', '0', '06'], ['17', '0', '07'],
          ['21', '0', '14'], ['22', '0', '13'], ['23', '0', '12'], ['24', '0', '11'], ['25', '0', '10'], ['26', '0', '09'], ['27', '0', '08'],
          ['31', '0', '15'], ['32', '0', '16'], ['33', '0', '17'], ['34', '0', '18'], ['35', '0', '19'], ['36', '0', '20'], ['37', '0', '21'],
          ['41', '0', '28'], ['42', '0', '27'], ['43', '0', '26'], ['44', '0', '25'], ['45', '0', '24'], ['46', '0', '23'], ['47', '0', '22'],
          ['51', '0', '29'], ['52', '0', '30'], ['53', '0', '31'], ['54', '0', '32'], ['55', '0', '33'], ['56', '0', '34'], ['57', '0', '35'],
          ['61', '0', '42'], ['62', '0', '41'], ['63', '0', '40'], ['64', '0', '39'], ['65', '0', '38'], ['66', '0', '37'], ['67', '0', '36'],
          ['71', '0', '43'], ['72', '0', '44'], ['73', '0', '45'], ['74', '0', '46'], ['75', '0', '47'], ['76', '0', '48'], ['77', '0', '49']]
    for i in range(len(big1)):
        big1[i].append(0)

    print big1
    rc=[]
    for k in range(7):
        rc.append(big1[7*k:7*(k+1)])
    for i in range(7):
        print rc[i]
    return rc
#c=printmaze()

newmaze=[]
for i in range(8):
    for j in range(8):
        newmaze.append(map(int,[str(i+1)+str(j+1),0]))

tempmaze=[]
for k in range(8):
    if k%2==0:
        tempmaze.extend(newmaze[8*k:8*(k+1)])
    else:
        temp=newmaze[8*k:8*(k+1)]
        tempmaze.extend(temp[::-1])

for i in range(len(tempmaze)):
    tempmaze[i].append(i+1)
    tempmaze[i].append(0)

for k in range(8):
    ##print tempmaze[8*k:8*(k+1)]

    big1=[[11, 0, 1, 0], [12, 0, 2, 0], [13, 0, 3, 0], [14, 0, 4, 0], [15, 0, 5, 0], [16, 0, 6, 0], [17, 0, 7, 0], [18, 0, 8, 0]
[28, 0, 9, 0], [27, 0, 10, 0], [26, 0, 11, 0], [25, 0, 12, 0], [24, 0, 13, 0], [23, 0, 14, 0], [22, 0, 15, 0], [21, 0, 16, 0]
          [31, 0, 17, 0], [32, 0, 18, 0], [33, 0, 19, 0], [34, 0, 20, 0], [35, 0, 21, 0], [36, 0, 22, 0], [37, 0, 23, 0], [38, 0, 24, 0]
          [48, 0, 25, 0], [47, 0, 26, 0], [46, 0, 27, 0], [45, 0, 28, 0], [44, 0, 29, 0], [43, 0, 30, 0], [42, 0, 31, 0], [41, 0, 32, 0]
          [51, 0, 33, 0], [52, 0, 34, 0], [53, 0, 35, 0], [54, 0, 36, 0], [55, 0, 37, 0], [56, 0, 38, 0], [57, 0, 39, 0], [58, 0, 40, 0]
          [68, 0, 41, 0], [67, 0, 42, 0], [66, 0, 43, 0], [65, 0, 44, 0], [64, 0, 45, 0], [63, 0, 46, 0], [62, 0, 47, 0], [61, 0, 48, 0]
          [71, 0, 49, 0], [72, 0, 50, 0], [73, 0, 51, 0], [74, 0, 52, 0], [75, 0, 53, 0], [76, 0, 54, 0], [77, 0, 55, 0], [78, 0, 56, 0]
          [88, 0, 57, 0], [87, 0, 58, 0], [86, 0, 59, 0], [85, 0, 60, 0], [84, 0, 61, 0], [83, 0, 62, 0], [82, 0, 63, 0], [81, 0, 64, 0]]
    return big1

