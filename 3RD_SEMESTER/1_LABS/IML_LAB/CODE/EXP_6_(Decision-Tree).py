import pandas as pd
import numpy as np
from collections import Counter
import math

train_data = pd.read_csv(r"D:\COLLEGE\1             EXCEL FILE\6        PlayTennis.csv")

target_val = train_data.iloc[:, -1]

total_counts = Counter(target_val)
total_yes = total_counts['Yes']
total_no = total_counts['No']
print("Total 'Yes' targets:", total_yes)
print("Total 'No' targets:", total_no)

def entropy(p):
    return -p * math.log2(p) if p > 0 else 0

a1 = total_yes / len(target_val)
b1 = total_no / len(target_val)
total_entropy = entropy(a1) + entropy(b1)
print("Total Entropy:", total_entropy)

total_gain_columns = []
for i in range(len(train_data.columns) - 1):
    gain = total_entropy
    attribute_current = train_data.iloc[:, i]
    unique_val = np.unique(attribute_current)
    for val in unique_val:
        indices = attribute_current[attribute_current == val].index
        count_yes = sum(target_val.iloc[indices] == 'Yes')
        count_no = sum(target_val.iloc[indices] == 'No')
        p_yes = count_yes / (count_yes + count_no) 
        p_no = count_no / (count_yes + count_no) 
        entropy_current = entropy(p_yes) + entropy(p_no)
        gain -= (len(indices) / len(target_val)) * entropy_current
    total_gain_columns.append(gain)
    print(f"Gain of {train_data.columns[i]} is: {gain}")

max_gain = max(total_gain_columns)
index_max = total_gain_columns.index(max_gain)
print("Maximum gain:", max_gain, "of", train_data.columns[index_max])

attribute_name_max = train_data.columns[index_max]
print("Attribute with maximum gain:", attribute_name_max)