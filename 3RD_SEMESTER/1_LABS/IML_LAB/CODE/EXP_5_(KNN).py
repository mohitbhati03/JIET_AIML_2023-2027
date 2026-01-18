import pandas as pd
df = pd.read_csv(r"D:\COLLEGE\1             EXCEL FILE\5 knn.csv")
datalist = df.values.tolist()
k=5
point = [23,12]
dist = 0
for i in range(len(datalist)):
    for j in range(len(point)):
        dist += ((point[j] - datalist[i][j]) ** 2)
    datalist[i].insert(3, (dist) ** 0.5)
    dist = 0

datalist = sorted(datalist,key=lambda x: x[3])
new_data = [datalist[i] for i in range(k)]
freq = pd.DataFrame(new_data)[6].mode()[0]
print(f'{point[0]} \t {point[1]} \t {freq}')