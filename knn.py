# 4 KNN Visualize Training Dataset + Classifier + Add new points
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, accuracy_score
from matplotlib.colors import ListedColormap
import warnings
warnings.filterwarnings("ignore")
data = {'X1': [0.8, 1, 1.2, 0.8, 1.2, 4, 3.8, 4.2, 3.8, 4.2, 4.4, 4.4, 3.2, 3.2, 3.8, 3.5, 4, 4],
        'X2': [0.8, 1, 0.8, 1.2, 1.2, 3, 2.8, 2.8, 3.2, 3.2, 2.8, 3.2, 0.4, 0.7, 0.5, 1, 1, 0.7],
        'Class': ['A', 'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'C', 'C', 'C', 'C', 'C', 'C']}
df = pd.DataFrame(data)
print(df)
class_counts = df['Class'].value_counts()
min_class_count = class_counts.min()
if min_class_count == 1:
    min_class = class_counts.idxmin()
    df = df[df['Class'] != min_class]
plt.scatter(df.X1, df.X2, c=pd.factorize(df['Class'])[0])
plt.xlabel("X1")
plt.ylabel("X2")
plt.title("Training data")
plt.show()
scaler = StandardScaler()
stdData = scaler.fit_transform(df[['X1', 'X2']])
print(stdData)
X_train, X_test, y_train, y_test = train_test_split(stdData, df['Class'], test_size=1/3, random_state=42, stratify=df['Class'])
model = KNeighborsClassifier(n_neighbors=3, metric='minkowski', p=2)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Confusion matrix:\n", confusion_matrix(y_test, y_pred))
print("Accuracy:", accuracy_score(y_test, y_pred))
test_points = np.array([[3, 2], [4.2, 1.8]])
predicted_classes = model.predict(scaler.transform(test_points))
for i, point in enumerate(test_points):
    print(f"Predicted class for point {i+1}: {predicted_classes[i]}")
# Plotting the testing data points along with their predicted classes
#plt.scatter(X_test[:, 0], X_test[:, 1], c=pd.factorize(y_pred)[0], marker='x', label='Predicted Class')
#plt.scatter(test_points[:, 0], test_points[:, 1], c='red', marker='o', label='Test Points')
#plt.xlabel("X1")
#plt.ylabel("X2")
#plt.title("Testing data and Predicted classes")
#plt.legend()
#plt.show()
​
​
​
# 4 KNN Prediction Iris Dataset
import warnings
warnings.filterwarnings("ignore", category=FutureWarning)
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix,accuracy_score
from matplotlib.colors import ListedColormap
df = pd.read_csv('https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data')
x = df.iloc[:,[0,1]].values
y = df.iloc[:, -1].values
X_train, X_test, y_train, y_test = train_test_split(x, y, test_size = 1/3, random_state = 0)
model = KNeighborsClassifier(n_neighbors=3, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
cm= confusion_matrix(y_test, y_pred)
accuracy = accuracy_score(y_test,y_pred)
values = []
for x in y_train:
 if(x=="Iris-setosa"):
    values.append(0)
 elif(x=="Iris-versicolor"):
    values.append(1)
 else:
    values.append(2)
scatter = plt.scatter(X_train[:,0],X_train[:,1],c=values,cmap=ListedColormap(["red","blue","green"]))
plt.legend(handles=scatter.legend_elements()[0],labels=["Iris-setosa","Iris-versicolor","Iris-virginica"],title="Class")
plt.xlabel("Sepal-width")
plt.ylabel("Sepal-length")
plt.title("Training data")
plt.show()
values = []
for x in y_test:
 if(x=="Iris-setosa"):
    values.append(0)
 elif(x=="Iris-versicolor"):
    values.append(1)
 else:
    values.append(2)
scatter = plt.scatter(X_test[:,0],X_test[:,1],c=values,cmap=ListedColormap(["red","blue","green"]))
plt.legend(handles=scatter.legend_elements()[0],labels=["Iris-setosa","Iris-versicolor","Iris-virginica"],title="Class")
plt.xlabel("Sepal-width")
plt.ylabel("Sepal-length")
plt.title("Testing data")
plt.show()
values = []
for x in y_pred:
 if(x=="Iris-setosa"):
    values.append(0)
 elif(x=="Iris-versicolor"):
    values.append(1)
 else:
    values.append(2)
scatter = plt.scatter(X_test[:,0],X_test[:,1],c=values,cmap=ListedColormap(["red","blue","green"]))
plt.legend(handles=scatter.legend_elements()[0],labels=["Iris-setosa","Iris-versicolor","Iris-virginica"],title="Class")
plt.xlabel("Sepal-width")
plt.ylabel("Sepal-length")
plt.title("Predicted data")
plt.show()
print(f"Error rate for k = 3 is {1-accuracy}")
model = KNeighborsClassifier(n_neighbors=5, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print(f"Error rate for k = 5 is {1-accuracy}")
model = KNeighborsClassifier(n_neighbors=9, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print(f"Error rate for k = 9 is {1-accuracy}")
model = KNeighborsClassifier(n_neighbors=15, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print(f"Error rate for k = 15 is {1-accuracy}")
​
​
​
# 4 KNN Prediction Iris Dataset (different features)
# Post lab Exercise
import warnings
warnings.filterwarnings("ignore", category=FutureWarning)
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix,accuracy_score
from matplotlib.colors import ListedColormap
df = pd.read_csv('https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data')
x = df.iloc[:,[2,3]].values
y = df.iloc[:, -1].values
X_train, X_test, y_train, y_test = train_test_split(x, y, test_size = 1/3, random_state = 0)
model = KNeighborsClassifier(n_neighbors=3, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
cm= confusion_matrix(y_test, y_pred)
accuracy = accuracy_score(y_test,y_pred)
values = []
for x in y_train:
 if(x=="Iris-setosa"):
    values.append(0)
 elif(x=="Iris-versicolor"):
    values.append(1)
 else:
    values.append(2)
scatter = plt.scatter(X_train[:,0],X_train[:,1],c=values,cmap=ListedColormap(["red","blue","green"]))
plt.legend(handles=scatter.legend_elements()[0],labels=["Iris-setosa","Iris-versicolor","Iris-virginica"],title="Class")
plt.xlabel("Petal-width")
plt.ylabel("Petal-length")
plt.title("Training data")
plt.show()
values = []
for x in y_test:
 if(x=="Iris-setosa"):
    values.append(0)
 elif(x=="Iris-versicolor"):
    values.append(1)
 else:
    values.append(2)
scatter = plt.scatter(X_test[:,0],X_test[:,1],c=values,cmap=ListedColormap(["red","blue","green"]))
plt.legend(handles=scatter.legend_elements()[0],labels=["Iris-setosa","Iris-versicolor","Iris-virginica"],title="Class")
plt.xlabel("Petal-width")
plt.ylabel("Petal-length")
plt.title("Testing data")
plt.show()
model = KNeighborsClassifier(n_neighbors=9, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print(f"Error rate for k = 9 is {1-accuracy}")
model = KNeighborsClassifier(n_neighbors=15, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print(f"Error rate for k = 15 is {1-accuracy}")
values = []
for x in y_pred:
 if(x=="Iris-setosa"):
    values.append(0)
 elif(x=="Iris-versicolor"):
    values.append(1)
 else:
    values.append(2)
scatter = plt.scatter(X_test[:,0],X_test[:,1],c=values,cmap=ListedColormap(["red","blue","green"]))
plt.legend(handles=scatter.legend_elements()[0],labels=["Iris-setosa","Iris-versicolor","Iris-virginica"],title="Class")
plt.xlabel("Petal-width")
plt.ylabel("Petal-length")
plt.title("Predicted data")
plt.show()
print(f"Error rate for k = 3 is {1-accuracy}")
model = KNeighborsClassifier(n_neighbors=5, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print(f"Error rate for k = 5 is {1-accuracy}")
model = KNeighborsClassifier(n_neighbors=9, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print(f"Error rate for k = 9 is {1-accuracy}")
model = KNeighborsClassifier(n_neighbors=15, metric='minkowski', p=2)
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print(f"Error rate for k = 15 is {1-accuracy}")
