# 3 K Means Clustering for K=2 on 2D Data
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
# csv = [
    ['Subject', 'A', 'B'],
    [1, 1.0, 1.0],
    [2, 1.5, 2.0],
    [3, 3.0, 4.0],
    [4, 5.0, 7.0],
    [5, 3.5, 5.0],
    [6, 4.5, 5.0],
    [7, 3.5, 4.5]
# ]
import pandas as pd
df = pd.read_csv("C:\\College\\sem 6\\Machine learning\\lab\\exp3\\task1_dataset.csv")
print(df)
X = df.values
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)
kmeans = KMeans(n_clusters=2)  
kmeans.fit(X_scaled)  # Use X_scaled if you standardized the data
cluster_assignments = kmeans.labels_
centroids = kmeans.cluster_centers_
plt.scatter(X[:, 0], X[:, 1], c=cluster_assignments, cmap='viridis')
plt.scatter(centroids[:, 0], centroids[:, 1], marker='X', s=200, linewidths=3, color='red', label='Centroids')
plt.xlabel('A')
plt.ylabel('B')
plt.legend()
plt.title('K-means Clustering with k=2')
plt.show()
​
​
​
# 3 K-Means Clustering on Mall Dataset
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import os
os.environ['OMP_NUM_THREADS'] = '1'
# Load the dataset
dataset = pd.read_csv("C:\\College\\sem 6\\Machine learning\\lab\\exp3\\Mall_Customers.csv")
# Select different features for clustering
# For example, let's select 'Age' and 'Spending Score'
X = dataset.iloc[:, [2, 4]].values
#  For annual income and spending score [:, [3, 4]]
# Perform K-means clustering
from sklearn.cluster import KMeans
wcss = []
for i in range(1, 11):
    kmeans = KMeans(n_clusters=i, init='k-means++', random_state=42)
    kmeans.fit(X)
    wcss.append(kmeans.inertia_)
# Plot the Elbow Method to find the optimal number of clusters
plt.plot(range(1, 11), wcss)
plt.title('The Elbow Method')
plt.xlabel('Number of clusters')
plt.ylabel('WCSS')
plt.show()
# Apply K-means clustering with the optimal number of clusters
kmeans = KMeans(n_clusters=5, init='k-means++', random_state=42)
y_kmeans = kmeans.fit_predict(X)
# Visualize the clustered data
plt.scatter(X[y_kmeans == 0, 0], X[y_kmeans == 0, 1], s=100, c='red', label='Cluster 1')
plt.scatter(X[y_kmeans == 1, 0], X[y_kmeans == 1, 1], s=100, c='blue', label='Cluster 2')
plt.scatter(X[y_kmeans == 2, 0], X[y_kmeans == 2, 1], s=100, c='green', label='Cluster 3')
plt.scatter(X[y_kmeans == 3, 0], X[y_kmeans == 3, 1], s=100, c='cyan', label='Cluster 4')
plt.scatter(X[y_kmeans == 4, 0], X[y_kmeans == 4, 1], s=100, c='magenta', label='Cluster 5')
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], s=300, c='yellow', label='Centroids')
plt.title('Clusters of customers')
plt.xlabel('Age')
plt.ylabel('Spending Score (1-100)')
plt.legend()
plt.show()
​
​
​
# 3 K-Means Clustering with make_blobs on own dataset + elbow method
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
X, y = make_blobs(n_samples=30, centers=7, random_state=42, cluster_std=0.5)
print("Features (X):")
print(X)  
print("\nLabels (y):")
print(y) 
wcss = []
for i in range(1, 11):
    kmeans = KMeans(n_clusters=i, init='k-means++', random_state=42)
    kmeans.fit(X)
    wcss.append(kmeans.inertia_)
plt.plot(range(1, 11), wcss, marker='o')
plt.title('Elbow Method')
plt.xlabel('Number of Clusters')
plt.ylabel('WCSS (Within-Cluster Sum of Squares)')
plt.show()
optimal_clusters = 7  
kmeans = KMeans(n_clusters=optimal_clusters, init='k-means++', random_state=42)
y_kmeans = kmeans.fit_predict(X)
plt.scatter(X[:, 0], X[:, 1], c=y_kmeans, cmap='viridis', edgecolors='k')
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], s=300, c='red', marker='X', label='Centroids')
plt.title('Clusters of Data Points')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.legend()
plt.show()
