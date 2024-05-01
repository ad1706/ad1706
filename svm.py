# 7 SVM Predict Ads
import numpy as np 
import matplotlib.pyplot as plt 
import pandas as pd 
import warnings
# Ignore warnings
warnings.filterwarnings("ignore")
dataset = pd.read_csv('https://raw.githubusercontent.com/stavanR/Machine-Learning-Algorithms-Dataset/master/Social_Network_Ads.csv') 
x = dataset.iloc[:, [2, 3]].values 
y = dataset.iloc[:, 4].values 
from sklearn.model_selection import train_test_split 
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.25, random_state=0) 
from sklearn.preprocessing import StandardScaler 
sc = StandardScaler() 
x_train = sc.fit_transform(x_train) 
x_test = sc.transform(x_test) 
from sklearn.svm import SVC 
classifier = SVC(kernel='linear', random_state=0) 
classifier.fit(x_train, y_train) 
y_pred = classifier.predict(x_test) 
from sklearn.metrics import confusion_matrix 
cm = confusion_matrix(y_test, y_pred) 
x_set, y_set = x_train, y_train 
x1, x2 = np.meshgrid(np.arange(start=x_set[:, 0].min() - 1, stop=x_set[:, 0].max() + 1, step=0.01),   
                     np.arange(start=x_set[:, 1].min() - 1, stop=x_set[:, 1].max() + 1, step=0.01))   
plt.contourf(x1, x2, classifier.predict(np.array([x1.ravel(), x2.ravel()]).T).reshape(x1.shape),   
             alpha=0.75, cmap=ListedColormap(('red', 'green')))   
plt.xlim(x1.min(), x1.max()) 
plt.ylim(x2.min(), x2.max()) 
for i, j in enumerate(np.unique(y_set)): 
    plt.scatter(x_set[y_set == j, 0], x_set[y_set == j, 1], c=['red', 'green'][i], label=j) 
plt.title('SVM (Training set)') 
plt.xlabel('Age') 
plt.ylabel('Estimated Salary') 
plt.legend() 
plt.show() 
x_set, y_set = x_test, y_test 
x1, x2 = np.meshgrid(np.arange(start=x_set[:, 0].min() - 1, stop=x_set[:, 0].max() + 1, step=0.01),   
                     np.arange(start=x_set[:, 1].min() - 1, stop=x_set[:, 1].max() + 1, step=0.01))   
plt.contourf(x1, x2, classifier.predict(np.array([x1.ravel(), x2.ravel()]).T).reshape(x1.shape),   
             alpha=0.75, cmap=ListedColormap(('red', 'green')))   
plt.xlim(x1.min(), x1.max()) 
plt.ylim(x2.min(), x2.max()) 
for i, j in enumerate(np.unique(y_set)): 
    plt.scatter(x_set[y_set == j, 0], x_set[y_set == j, 1], c=['red', 'green'][i], label=j) 
plt.title('SVM (Testing set)') 
plt.xlabel('Age') 
plt.ylabel('Estimated Salary') 
plt.legend() 
plt.show() 
​
​
​
# 7 SVM Classify and Predict Traffic
import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt 
from sklearn.svm import SVC 
from sklearn.preprocessing import StandardScaler 
from sklearn.model_selection import train_test_split 
from sklearn.metrics import confusion_matrix, accuracy_score
from matplotlib.colors import ListedColormap 
# Getting the dataset 
data = pd.read_csv('C:\College\sem 6\Machine learning\lab\exp7\dataset\Dodgers.data', header=None, encoding='unicode_escape') 
print('Raw Data: \n', data.head())
# Pre-processing the data 
data.columns = ['date_time', 'Cars'] 
data['date_time'] = pd.to_datetime(data['date_time'], errors='coerce') 
data.dropna(inplace=True)  # Dropping rows with NaN values
data['Date'] = data['date_time'].dt.date 
data['Time'] = data['date_time'].dt.time 
data.drop(columns=['date_time'], inplace=True)  # Drop the original datetime column
data['Date'] = data['Date'].apply(lambda x: x.strftime('%Y%m%d'))  # Simplified date formatting
data['Time'] = data['Time'].apply(lambda x: x.strftime('%H%M%S'))  # Simplified time formatting
# Creating traffic labels
data['Traffic'] = pd.cut(data['Cars'], bins=[-np.inf, 9, 27, np.inf], labels=['light', 'medium', 'heavy'])
traffic_map = {"light": 0, "medium": 1, "heavy": 2} 
data['Traffic'] = data['Traffic'].map(traffic_map)
# Splitting data into features (X) and labels (y) 
X = data[['Date', 'Time']].values.astype(float)  # Converting to float for SVC
y = data['Traffic'].values 
# Splitting dataset into test and train. Visualize. 
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.10, random_state=101) 
# Standardizing the data 
sc = StandardScaler() 
X_train = sc.fit_transform(X_train) 
X_test = sc.transform(X_test) 
# Training via SVC 
classifier = SVC(kernel='linear', random_state=26) 
classifier.fit(X_train, y_train) 
# Predicting traffic level 
y_pred = classifier.predict(X_test) 
# Confusion matrix 
cm = confusion_matrix(y_test, y_pred) 
print("Confusion Matrix:\n", cm) 
# Visualize output (trained set) 
X_set, y_set = X_train, y_train 
X1, X2 = np.meshgrid(np.arange(start=X_set[:, 0].min() - 1, stop=X_set[:, 0].max() + 1, step=1),
                     np.arange(start=X_set[:, 1].min() - 1, stop=X_set[:, 1].max() + 1, step=0.5)) 
plt.contourf(X1, X2, classifier.predict(np.array([X1.ravel(), X2.ravel()]).T).reshape(X1.shape), alpha=0.68,
             cmap=ListedColormap(('red', 'green', 'blue'))) 
plt.xlim(X1.min(), X1.max()) 
plt.ylim(X2.min(), X2.max()) 
for i, j in enumerate(np.unique(y_set)):
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1], color=ListedColormap(('red', 'green', 'blue'))(i),
                label=f'Traffic Level {j}')  # Updated legend label
plt.title('SVM (Training Set)') 
plt.xlabel('Date') 
plt.ylabel('Time') 
plt.legend() 
plt.show() 
# Visualize test results (prediction) 
X_set, y_set = X_test, y_test 
plt.contourf(X1, X2, classifier.predict(np.array([X1.ravel(), X2.ravel()]).T).reshape(X1.shape), alpha=0.68,
             cmap=ListedColormap(('red', 'green', 'blue'))) 
plt.xlim(X1.min(), X1.max()) 
plt.ylim(X2.min(), X2.max()) 
for i, j in enumerate(np.unique(y_set)): 
    plt.scatter(X_set[y_set == j, 0], X_set[y_set == j, 1], color=ListedColormap(('red', 'green', 'blue'))(i),
                label=f'Traffic Level {j}')  # Updated legend label
plt.title('SVM (Test Set)') 
plt.xlabel('Date') 
plt.ylabel('Time') 
plt.legend() 
plt.show() 
# Calculate and print accuracy 
accuracy = accuracy_score(y_test, y_pred) 
print("Accuracy:", accuracy)
​
