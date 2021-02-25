from scipy.optimize import curve_fit
from matplotlib import pyplot
import numpy


x_val = [128.00,256.00,512.00,1024.00,2048.00,4096.00,8192.00,16384.00,32768.00,65536.00,131072.00]
y_val2 = [7.581495,10.678034,14.967085,21.056606,29.551414,41.910149,58.824887,83.197649,117.469283,166.030158,234.722987]
y_val3 = [17.638308,26.778301,43.494598,67.954180,108.381274,169.063714,267.816380,422.902674,669.288376,1057.961546,1676.857439]

y_val4 = [28.336720,47.782247,79.674215,130.806892,216.083849,362.054314,604.511032,1008.647550,1687.631838,2825.539945,4741.760704]

def objective2(x, a,c):
    return a*numpy.power(x,0.75)+c

popt, _=curve_fit(objective2, x_val, y_val4)

print(popt) 
print("this is 2")

# def objective3(x, a,c):
#     return a*numpy.power(x,2/3)+c

# popt3, _=curve_fit(objective3, x_val, y_val3)

# print(popt3) 
# print("this is 3")
