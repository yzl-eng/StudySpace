import math
import matplotlib.pyplot as plt
import numpy as np

NUM = 10000
npx = np.arange(1, NUM)
a = [(1 + 1 / n) ** n for n in range(1, NUM)]
npy = np.asarray(a)
plt.plot(npx, npy)
plt.show()
print(math.e)
print(max(npy))
