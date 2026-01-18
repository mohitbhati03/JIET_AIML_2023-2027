import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
file_path = r"D:\COLLEGE\1             EXCEL FILE\3 Salary_Data.csv"
df = pd.read_csv(file_path)

a = df.values.tolist()
xl,yl=[],[] #sample data
xt,yt=[],[] #test data

x2=0 #x^2
xy=0 #xl*yl

n=((len(a)-1)*8)//10

#sample data
for i in range(n):
    xl.append(a[i][0])
    yl.append(a[i][1])
   
#test data 
for i in range(n,len(a)):
    xt.append(a[i][0])
    yt.append(a[i][1])

x1=sum(xl)
y1=sum(yl)

for i in range(n):
    x2+=xl[i]*xl[i] 
    xy+=xl[i]*yl[i]
    
b0=((y1*x2)-(x1*xy))/((n*x2)-x1*x1)
b1=((n*xy)-(x1*y1))/((n*x2)-x1*x1)
print('b1=',b1,'\nb0=',b0,'\n')

t=int(input('enter the years of experience:'))
t1=b1 * t + b0
print('Predicted Salary:',t1)

# Define the equation (y = mx + c)
m = b1 # slope
c = b0 # y-intercept

# Generate x values
x = np.linspace(0, 20, 100000)  # 100 points between 0 and 40

# Calculate y values using the equation
y = m * x + c

# Create the plot
plt.plot(x, y)
plt.xlabel('Years Experience')
plt.ylabel('Salary')
plt.title(f'Graph of y = {m}x + {c}')
plt.grid(True)

#  data
x =xl
y=yl

# Create the plot
plt.plot(x, y,'o')
plt.plot(t,t1,'o')
plt.plot(xt,yt,'o')

# Add labels and title
plt.title('Linear Regression')

# Show the plot
plt.show()