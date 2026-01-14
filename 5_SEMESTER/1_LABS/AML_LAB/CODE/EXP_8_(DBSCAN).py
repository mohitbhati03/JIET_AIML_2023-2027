from sklearn.datasets import make_moons
from sklearn.cluster import DBSCAN
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
import pandas as pd

X, _ = make_moons(n_samples=300, noise=0.07, random_state=42)

X_scaled = StandardScaler().fit_transform(X)

dbscan = DBSCAN(eps=0.3, min_samples=5)
labels = dbscan.fit_predict(X_scaled)

data = pd.DataFrame(X_scaled, columns=['X1', 'X2'])
data['Cluster'] = labels

print(data.head())

plt.scatter(X_scaled[:, 0], X_scaled[:, 1], c=labels, cmap='plasma')
plt.title('DBSCAN on Moon Dataset')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.show()