import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
df = pd.read_csv(r"D:\COLLEGE\1             EXCEL FILE\4 Position_Salaries.csv")
a = df.values.tolist()

xl,yl=[],[] #sample data


x2=0 #x^2
xy=0 #xl*yl
n=len(a)

for i in range(n):
    xl.append(a[i][1])
    yl.append(a[i][2]) 

x1=sum(xl)
y1=sum(yl)
x3,x4=0,0
yx2=0

for i in range(n):
    x2+=xl[i]*xl[i] 
    xy+=xl[i]*yl[i]
    x3+=xl[i]**3
    x4+=xl[i]**4
    yx2+=yl[i]*(xl[i]**2)

X=np.array([[x4,x3,x2],[x3,x2,x1],[x2,x1,n]])
Y=list(np.linalg.inv(X))
A=([yx2],[xy],[y1])
tt=(np.dot(Y , A))     
b0,b1,b2=int(tt[0]),int(tt[1]),int(tt[2])
print('b0=',b0,'\nb1=',b1,'\nb2=',b2)

t=int(input('enter the level:'))
t1=b0*t*t +b1*t +b2
print('Predicted Salary:',t1)

a =b0
b =b1 
c= b2

x = np.linspace(1,10, 10000)  # 100 points between 0 and 40
y = a*x*x +b*x +c
plt.plot(x, y)
plt.xlabel('Level')
plt.ylabel('Salary')
plt.grid(True)

plt.plot(xl, yl,'o')
plt.plot(t,t1,'o')
plt.legend(['Polynomial Regression','data','predicted'])
plt.show()