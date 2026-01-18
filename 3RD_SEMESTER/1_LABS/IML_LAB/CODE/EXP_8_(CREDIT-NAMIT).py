import pandas as pd
import numpy as np

d = pd.read_csv(r"D:\1 DO NOT CLICK  [MOHIT]\COLLEGE\1             EXCEL FILE\8  NBdocument.csv")
a = np.array(d)
ab = a[:, 1:]
a1 = []; b1 = []; a2 = []; a3 = []; a4 = []
a11 = []; a21 = []; a31 = []; a41 = []; b11 = []
b = ab

ay = sum(b[:, -1] == "Electrical Engineering") / len(b)
an = sum(b[:, -1] == "Computer Science & Engineering") / len(b)

val, col = np.unique(b, return_counts=True)

x = len(val)
print('Keywords in whole document are =', val, 'x =', x)

print('Test data i.e., any row from dataset')
O = ab[7]

for i in range(len(b)):
    if b[i, -1] == "Electrical Engineering":
        b1.append(len(b[i, :-1]))
        f12 = np.sum(b1)

        a1.append(b[i, :] == O[0])
        f1 = (1 + np.sum(a1)) / (f12 + x)
        a2.append(b[i, :] == O[1])
        f2 = (1 + np.sum(a2)) / (f12 + x)
        a3.append(b[i, :] == O[2])
        f3 = (1 + np.sum(a3)) / (f12 + x)
        a4.append(b[i, :] == O[3])
        f4 = (1 + np.sum(a4)) / (f12 + x)

    else:
        b11.append(len(b[i, :-1]))
        f121 = np.sum(b11)

        a11.append(b[i, :] == O[0])
        f11 = (1 + np.sum(a11)) / (f121 + x)
        a21.append(b[i, :] == O[1])
        f21 = (1 + np.sum(a21)) / (f121 + x)
        a31.append(b[i, :] == O[2])
        f31 = (1 + np.sum(a31)) / (f121 + x)
        a41.append(b[i, :] == O[3])
        f41 = (1 + np.sum(a41)) / (f121 + x)

p_ee = ay * f1 * f2 * f3 * f4

p_cse = an * f11 * f21 * f31 * f41

print('\np_ee =', p_ee, '\np_cse =', p_cse)
if p_ee > p_cse:
    print('\nDocument belongs to Electrical Engineering')
else:
    print('\nDocument belongs to Computer Science & Engineering')