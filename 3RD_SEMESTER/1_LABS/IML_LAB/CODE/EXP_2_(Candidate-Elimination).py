import numpy as np
import pandas as pd

data = pd.read_csv(r"D:\COLLEGE\1             EXCEL FILE\1 find_s.csv")
concepts = np.array(data.iloc[:,0:-1])
print("Original DataFrame:\n",concepts)
target = np.array(data.iloc[:,-1])

def learn(concepts, target): 
    specific_h = concepts[0].copy()
    general_h = [["?" for i in range(len(specific_h))] for i in range(len(specific_h))]

    for i, h in enumerate(concepts):
        if target[i] == "yes":
            for x in range(len(specific_h)): 
                if h[x]!= specific_h[x]:                    
                    specific_h[x] ='?'                     
                    general_h[x][x] ='?'
                   
        if target[i] == "no":            
            for x in range(len(specific_h)): 
                if h[x]!= specific_h[x]:                    
                    general_h[x][x] = specific_h[x]                
                else:                    
                    general_h[x][x] = '?'        
        
        print("S", i+1, ":", specific_h)         
        print("G", i+1, ":", general_h)
        print("\n")

    indices = [i for i, val in enumerate(general_h) if val == ['?' for i in range(len(specific_h))]]    
    for i in sorted(indices, reverse=True):
        del general_h[i]
    return specific_h, general_h 

s_final, g_final = learn(concepts, target)

print("Final S:", s_final)
print("Final G:", g_final)