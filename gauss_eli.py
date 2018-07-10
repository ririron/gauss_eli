import numpy as np



def gauss_eli(a, b):
    for i, s in enumerate(a):
        ###forward###
        for x in a[i+1:]:
            x = x + x[i]/s[i]




a = [[1, 2, -2],[1, -1, 3], [2, 3, -5]]

b = [3, 4, 1]

print(str(a[0]) + " = " + str(b[0]))
print(str(a[1]) + " = " + str(b[1]))
print(str(a[2]) + " = " + str(b[2]))

gauss_eli(a, b)
