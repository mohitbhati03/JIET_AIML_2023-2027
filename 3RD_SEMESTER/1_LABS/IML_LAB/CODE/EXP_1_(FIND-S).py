import pandas as pd

file_path = r"D:\COLLEGE\1             EXCEL FILE\1 find_s.csv"
df = pd.read_csv(file_path)
print("Original DataFrame: \n")
print(df)

a = df.values.tolist()

num_attribute = len(a[0]) - 1
print("\n The initial hypothesis is : ")
hypothesis = ['0'] * num_attribute
print(hypothesis)

for i in range(0, len(a)):
    if a[i][num_attribute] == 'yes':
        for j in range(0, num_attribute):
            if hypothesis[j] == '0' or hypothesis[j] == a[i][j]:
                hypothesis[j] = a[i][j]
            else:
                hypothesis[j] = '?'
    print("\n s{} :".format(i + 1), hypothesis)
print("\n result : ",hypothesis)