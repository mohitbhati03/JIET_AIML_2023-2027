import pandas as pd
df = pd.read_csv("D:\\COLLEGE\\1             EXCEL FILE\\5 knn.csv")
a = df.values.tolist()
x1=[]
for i in a:
    x2=[i[1],i[2],i[3],i[4]]
    x1.append(x2)
y1=float(input('Sepal Length in Cm:'))
y2=float(input('Sepal Width in Cm:'))
y3=float(input('Petal Length in Cm:'))
y4=float(input('Petal Width in Cm:'))
k=[y1,y2,y3,y4]   
for i in range(len(x1)):
    for j in range(4):
        x1[i][j]-=k[j]    
dis=[]
for i in x1:
    d=0
    for j in i:
        d+=j*j
    dis.append(d)
i=dis.index(min(dis))
print('Species:',a[i][5])