# 6 PCA Standardize 2D Data
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
X_values = np.array([[1.4, 1.65], [1.6, 1.975], [-1.4, -1.775], [-2, -2.525], [-3, -3.95], [2.4,
3.075], [1.5, 2.025], [2.3, 2.75], [-3.2, -4.05], [-4.1, -4.85], [1.4, 1.65]])
Scaler = StandardScaler()
X_values = Scaler.fit_transform(X_values)
pca = PCA(n_components = 2)
X_values = pca.fit_transform(X_values)
explained_variance = pca.explained_variance_
explained_variance_ratio = pca.explained_variance_ratio_
print(f"Expained Variance: {explained_variance}")
print(f"Expained Variance Ratio: {explained_variance_ratio}")
​
​
​
# 6 PCA Dimension Reduction
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
dataset = pd.read_csv(r'https://raw.githubusercontent.com/stavanR/Machine-Learning-Algorithms-Dataset/master/Wine.csv')
X_values = dataset.iloc[:, 0:13].values
Scaler = StandardScaler()
X_values = Scaler.fit_transform(X_values)
pca = PCA(n_components = 3)
X_values = pca.fit_transform(X_values)
explained_variance = pca.explained_variance_
explained_variance_ratio = pca.explained_variance_ratio_
print(f"Expained Variance: {explained_variance}")
print(f"Expained Variance Ratio: {explained_variance_ratio}")
​
​
​
# 6 PCA Dimension Reduction with 2 PC and Visualization
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
dataset = pd.read_csv('https://gist.githubusercontent.com/curran/a08a1080b88344b0c8a7/raw/0e7a9b0a5d22642a06d3d5b9bcbad9890c8ee534/iris.csv')
X_values = dataset.iloc[:,:-1].values
Scaler = StandardScaler()
X_values = Scaler.fit_transform(X_values)
pca = PCA(n_components = 2)
X_values = pca.fit_transform(X_values)
explained_variance = pca.explained_variance_
explained_variance_ratio = pca.explained_variance_ratio_
print(f"Expained Variance: {explained_variance}")
print(f"Expained Variance Ratio: {explained_variance_ratio}\n\n")
print(X_values[:10,:])
​
​
​
# 6 PCA with sklearn
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
dataset = pd.read_csv('https://gist.githubusercontent.com/curran/a08a1080b88344b0c8a7/raw/0e7a9b0a5d22642a06d3d5b9bcbad9890c8ee534/iris.csv')
X_values = dataset.iloc[:,:-1].values
Scaler = StandardScaler()
X_values = Scaler.fit_transform(X_values)
pca = PCA(n_components = 2)
X_values = pca.fit_transform(X_values)
explained_variance = pca.explained_variance_
explained_variance_ratio = pca.explained_variance_ratio_
print(f"Expained Variance: {explained_variance}")
print(f"Expained Variance Ratio: {explained_variance_ratio}\n\n")
print(X_values[:10,:])
​
​
​
# 6 PCA without libraries
import numpy as np
# Step 1: Standardization
X_values = np.array([[1.4, 1.65], [1.6, 1.975], [-1.4, -1.775], [-2, -2.525], [-3, -3.95], [2.4, 3.075], [1.5, 2.025], [2.3, 2.75], [-3.2, -4.05], [-4.1, -4.85], [1.4, 1.65]])
mean = np.mean(X_values, axis=0)
std_dev = np.std(X_values, axis=0)
X_values_standardized = (X_values - mean) / std_dev
# Step 2: Covariance Matrix Computation
cov_matrix = np.cov(X_values_standardized.T)
# Step 3: Compute Eigenvalues and Eigenvectors of Covariance Matrix
eigenvalues, eigenvectors = np.linalg.eig(cov_matrix)
# Sort eigenvalues and eigenvectors in descending order
sorted_indices = np.argsort(eigenvalues)[::-1]
eigenvalues = eigenvalues[sorted_indices]
eigenvectors = eigenvectors[:, sorted_indices]
# Select top k eigenvectors based on explained variance ratio or desired number of components
n_components = 2
top_eigenvectors = eigenvectors[:, :n_components]
# Transform the standardized data to obtain principal components
X_pca = np.dot(X_values_standardized, top_eigenvectors)
# Calculate explained variance and explained variance ratio
explained_variance = eigenvalues[:n_components]
explained_variance_ratio = explained_variance / np.sum(eigenvalues)
print(f"Explained Variance: {explained_variance}")
print(f"Explained Variance Ratio: {explained_variance_ratio}")
