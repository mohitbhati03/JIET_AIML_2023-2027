import pandas as pd
df=pd.read_csv(r"D:\COLLEGE\1             EXCEL FILE\1 find_s.csv")
datalist=df.values.tolist()
s1=[]
sol=[]
print(datalist)
for i in range(len(datalist)):
    if(datalist[i][6]=='yes'):
        s1.append(datalist[i])        
for i in range((len(s1))-1):
    for j in range(len(s1[0])-1):
        if(s1[i][j]!=s1[i+1][j]):
            s1[i+1][j]='?'
    sol=s1[i+1]  
    print(sol[:-1])