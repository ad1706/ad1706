# 8 Random Forest Classifier To Classify Ads
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import confusion_matrix, plot_confusion_matrix, accuracy_score
from matplotlib.colors import ListedColormap
import warnings
# Suppress warnings
warnings.filterwarnings("ignore")
# Load dataset
dataset = pd.read_csv('https://raw.githubusercontent.com/stavanR/Machine-Learning-Algorithms-Dataset/master/Social_Network_Ads.csv')
X = dataset.iloc[:, [2, 3]].values
y = dataset.iloc[:, 4].values
# Split dataset into train and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=0)
# Feature scaling
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)
# Create and train Random Forest classifier
classifier = RandomForestClassifier(n_estimators=10, criterion='entropy', random_state=0)
classifier.fit(X_train, y_train)
# Predict test set results
y_pred = classifier.predict(X_test)
# Confusion matrix
cm = confusion_matrix(y_test, y_pred)
print(cm)
# Plot Confusion Matrix
plot_confusion_matrix(classifier, X_test, y_test)
plt.title('Confusion Matrix')
plt.show()
# Visualize the training set results
X_set, y_set = X_train, y_train
X1, X2 = np.meshgrid(np.arange(start=X_set[:, 0].min() - 1, stop=X_set[:, 0].max() + 1, step=0.01),
                     np.arange(start=X_set[:, 1].min() - 1, stop=X_set[:, 1].max() + 1, step=0.01))
plt.contourf(X1, X2, classifier.predict(np.array([X1.ravel(), X2.ravel()]).T).reshape(X1.shape),
             alpha=0.75, cmap=ListedColormap(('red', 'green')))
plt.xlim(X1.min(), X1.max())
plt.ylim(X2.min(), X2.max())
for i, j in enumerate(np.unique(y_set)):
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1],
                color=ListedColormap(('red', 'green'))(i), label=j)
plt.title('Random Forest Classification (Training set)')
plt.xlabel('Age')
plt.ylabel('Estimated Salary')
plt.legend()
plt.show()
# Visualize the test set results
X_set, y_set = X_test, y_test
X1, X2 = np.meshgrid(np.arange(start=X_set[:, 0].min() - 1, stop=X_set[:, 0].max() + 1, step=0.01),
                     np.arange(start=X_set[:, 1].min() - 1, stop=X_set[:, 1].max() + 1, step=0.01))
plt.contourf(X1, X2, classifier.predict(np.array([X1.ravel(), X2.ravel()]).T).reshape(X1.shape),
             alpha=0.75, cmap=ListedColormap(('red', 'green')))
plt.xlim(X1.min(), X1.max())
plt.ylim(X2.min(), X2.max())
for i, j in enumerate(np.unique(y_set)):
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1],
                color=ListedColormap(('red', 'green'))(i), label=j)
plt.title('Random Forest Classification (Test set)')
plt.xlabel('Age')
plt.ylabel('Estimated Salary')
plt.legend()
plt.show()
# List to store the average accuracies for each value of n_estimators
accuracies = []
# We will try n_estimators ranging from 1 to 100
n_estimators = list(range(1, 101))
for n in n_estimators:
    # Train the model
    classifier = RandomForestClassifier(n_estimators=n, criterion='entropy', random_state=0)
    classifier.fit(X_train, y_train)   
    # Make predictions on the test set
    y_pred = classifier.predict(X_test)    
    # Compute the accuracy and append to accuracies list
    accuracies.append(accuracy_score(y_test, y_pred))
# Plot the results
plt.figure(figsize=(6, 4))
plt.plot(n_estimators, accuracies, marker='o')
plt.title('Accuracy vs. Number of Decision Trees')
plt.xlabel('Number of Decision Trees')
plt.ylabel('Accuracy')
plt.grid(True, color="grey")
plt.show()
​
​
​
# 8 Random Forest Classifier To Predict Office Building Energy
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import confusion_matrix, plot_confusion_matrix, accuracy_score
from matplotlib.colors import ListedColormap
import warnings
# Suppress warnings
warnings.filterwarnings("ignore")
# Load dataset
dataset = pd.read_csv('C:\College\sem 6\Machine learning\lab\exp8\data.csv')
X = dataset.iloc[:, [2, 3]].values
y = dataset.iloc[:, 4].values
# Split dataset into train and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=0)
# Feature scaling
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)
# Create and train Random Forest classifier
classifier = RandomForestClassifier(n_estimators=10, criterion='entropy', random_state=0)
classifier.fit(X_train, y_train)
# Predict test set results
y_pred = classifier.predict(X_test)
# Confusion matrix
cm = confusion_matrix(y_test, y_pred)
print(cm)
# Plot Confusion Matrix
plot_confusion_matrix(classifier, X_test, y_test)
plt.title('Confusion Matrix')
plt.show()
# Visualize the training set results
X_set, y_set = X_train, y_train
X1, X2 = np.meshgrid(np.arange(start=X_set[:, 0].min() - 1, stop=X_set[:, 0].max() + 1, step=0.01),
                     np.arange(start=X_set[:, 1].min() - 1, stop=X_set[:, 1].max() + 1, step=0.01))
plt.contourf(X1, X2, classifier.predict(np.array([X1.ravel(), X2.ravel()]).T).reshape(X1.shape),
             alpha=0.75, cmap=ListedColormap(('red', 'green')))
plt.xlim(X1.min(), X1.max())
plt.ylim(X2.min(), X2.max())
for i, j in enumerate(np.unique(y_set)):
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1],
                color=ListedColormap(('red', 'green'))(i), label=j)
plt.title('Random Forest Classification (Training set)')
plt.xlabel('Age')
plt.ylabel('Estimated Salary')
plt.legend()
plt.show()
# Visualize the test set results
X_set, y_set = X_test, y_test
X1, X2 = np.meshgrid(np.arange(start=X_set[:, 0].min() - 1, stop=X_set[:, 0].max() + 1, step=0.01),
                     np.arange(start=X_set[:, 1].min() - 1, stop=X_set[:, 1].max() + 1, step=0.01))
plt.contourf(X1, X2, classifier.predict(np.array([X1.ravel(), X2.ravel()]).T).reshape(X1.shape),
             alpha=0.75, cmap=ListedColormap(('red', 'green')))
plt.xlim(X1.min(), X1.max())
plt.ylim(X2.min(), X2.max())
for i, j in enumerate(np.unique(y_set)):
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1],
                color=ListedColormap(('red', 'green'))(i), label=j)
plt.title('Random Forest Classification (Test set)')
plt.xlabel('Age')
plt.ylabel('Estimated Salary')
plt.legend()
plt.show()
# List to store the average accuracies for each value of n_estimators
accuracies = []
# We will try n_estimators ranging from 1 to 100
n_estimators = list(range(1, 101))
for n in n_estimators:
    # Train the model
    classifier = RandomForestClassifier(n_estimators=n, criterion='entropy', random_state=0)
    classifier.fit(X_train, y_train)   
    # Make predictions on the test set
    y_pred = classifier.predict(X_test)  
    # Compute the accuracy and append to accuracies list
    accuracies.append(accuracy_score(y_test, y_pred))
# Plot the results
plt.figure(figsize=(6, 4))
plt.plot(n_estimators, accuracies, marker='o')
plt.title('Accuracy vs. Number of Decision Trees')
plt.xlabel('Number of Decision Trees')
plt.ylabel('Accuracy')
plt.grid(True, color="grey")
plt.show()
# y_pred = classifier.predict(X_test) to display  
