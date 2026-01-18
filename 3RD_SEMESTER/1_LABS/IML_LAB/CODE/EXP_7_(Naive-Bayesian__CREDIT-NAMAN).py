import pandas as pd
df=pd.read_csv(r"D:\1 DO NOT CLICK  [MOHIT]\COLLEGE\1             EXCEL FILE\7     PlayTennis.csv")
a=df.values.tolist()

Outlook,Temp,Humidity,Wind,YN=[],[],[],[],[]
for i in range(len(a)):
    Outlook.append(a[i][0])
    Temp.append(a[i][1])
    Humidity.append(a[i][2])
    Wind.append(a[i][3])
    YN.append(a[i][4])

o=list(set(Outlook))
t=list(set(Temp))
h=list(set(Humidity))
w=list(set(Wind))
py=YN.count("Yes")/len(YN)
pn=YN.count("No")/len(YN)

print('p(E):\n','P(yes)=',py,'\tP(no)=',pn,'\n')

o1,t1,h1,w1=[],[],[],[]
def countyn(att,k,o1):
    for j in att:
        y,n=0,0
        for i in range(len(a)):    
            if(j==a[i][k]):
                if(a[i][4]=='Yes'):
                    y+=1
                elif(a[i][4]=='No'):
                    n+=1
        o1.append([y/YN.count("Yes"),n/YN.count("No")])
    for i in range(len(att)):
        print(att[i],'\tP(yes)=',o1[i][0],'\tP(no)=',o1[i][1])
    print()       
countyn(o,0,o1)
countyn(t,1,t1)
countyn(h,2,h1)
countyn(w,3,w1)
tp=[o,t,h,w]

c=[]
print('choice:-\n')
for i in tp:
    gg=1
    for j in i:
        print(gg,')',j)
        gg+=1
    n=int(input("enter u choice:"))
    if(n>len(j)):
        print('invalid choice....')
        break
    c.append(n-1)
    print()

cc=o1+t1+h1+w1
tt=[[py,pn]]

for i in c:
    tt.append(cc[i])

pyes,pno=1,1
for i in tt:
    pyes*=i[0]
    pno*=i[1]
    
if((pyes/(pyes+pno))>=.5):
    print('Final P(E) : yes')
else:
    print('Final P(E) : no')