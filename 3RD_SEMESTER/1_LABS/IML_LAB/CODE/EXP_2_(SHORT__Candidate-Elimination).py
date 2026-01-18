import pandas as pd
datalist =r"D:\COLLEGE\1             EXCEL FILE\1 find_s.csv"
df=pd.read_csv(datalist)
print("the orginal dataframe\n",df)
a=df.values.tolist()
s1=[]
S=["null","null","null","null","null","null"]
G=[["?","?","?","?","?","?"],["?","?","?","?","?","?"],["?","?","?","?","?","?"],["?","?","?","?","?","?"],["?","?","?","?","?","?"],["?","?","?","?","?","?"]]
for i in range(len(a)):
    if(a[i][6]=='yes'):
        s1.append(a[i])
        break
for i in range(len(a)): 
    if(a[i][6]=="yes"):
        for j in range(0,6,1):
            if(S[j]=="null"):
                S[j]=s1[i][j]
            elif(S[j]!=a[i][j]):
                S[j]="?"
                G[j][j]="?"
        print("\n")
        print("instance ",i)           
        print(S)
        print(G)
    elif(a[i][6]=="no"):
        for j in range(0,6,1):
            if(a[i][j]!=S[j]):
                G[j][j]=S[j]
            else:
                G[j][j]="?"
        print("\n")
        print("instance ",i)              
        print(S)
        print(G)
print("\n")              
print("Final Specific hypothesis is",S)
print("Final General hypothesis is",G)