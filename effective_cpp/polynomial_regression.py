import numpy as np
import matplotlib.pyplot as plt

plt.style.use("dark_background")

# Linear regression
X= np.arange(1, 11)
Y= np.arange(1, 11)

plt.figure(figsize=(20, 9), dpi= 100)
plt.subplot(1, 2, 1)
plt.plot(X, Y, 'oy', markersize= 8, label= 'data points')

