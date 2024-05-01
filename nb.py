# 5 Naive Bayes Classifier Gaussian
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
import seaborn as sns
df = pd.read_csv('C:\\College\\sem 6\\Machine learning\\lab\\exp5\\Naive-Bayes-Classification-Data.csv')
print(df)
x=df.iloc[:, :-1].values
y=df.iloc[:, 2].values
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.25,random_state=42)
model=GaussianNB()
model.fit(x_train,y_train)
GaussianNB(priors=None, var_smoothing=1e-09)
y_pred=model.predict(x_test)
print(y_pred)
accuracy=accuracy_score(y_test,y_pred)*100
accuracy
​
​
​
# 5 Naive Bayes Binary Classification
from sklearn import preprocessing
from sklearn.naive_bayes import GaussianNB
weather=['Sunny','Sunny','Overcast','Rainy','Rainy','Rainy','Overcast','Sunny','Sunny','Rainy','Sunny','Overcast','Overcast','Rainy']
temp=['Hot','Hot','Hot','Mild','Cool','Cool','Cool','Mild','Cool','Mild','Mild','Mild','Hot','Mild']
play=['No','No','Yes','Yes','Yes','No','Yes','No','Yes','Yes','Yes','Yes','Yes','No']
print(weather)
print(temp)
print(play)
le = preprocessing.LabelEncoder()
weather_encoded = le.fit_transform(weather)
temp_encoded = le.fit_transform(temp)
label = le.fit_transform(play)
print("Weather Encoded:", weather_encoded)
print("Temp Encoded:", temp_encoded)
print("Play Encoded:", label)
features = list(zip(weather_encoded, temp_encoded))
print("Features:", features)
model = GaussianNB()
model.fit(features, label)
predicted = model.predict([[0, 2]]) 
print("Predicted Value:", predicted)
​
​
​
# 5 Naive Bayes Multi Class Classification
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn import metrics
wine = datasets.load_wine()
print("Features:", wine.feature_names)
print("Labels: ", wine.target_names)
print("Shape of the data:", wine.data.shape)
print(wine.data[0:5])
print(wine.target)
x_train, x_test, y_train, y_test = train_test_split(wine.data, wine.target, test_size=0.3, random_state=109)
gnb = GaussianNB()
gnb.fit(x_train, y_train)
y_pred = gnb.predict(x_test)
print("Accuracy:", metrics.accuracy_score(y_test, y_pred))
​
​
​
# 5 Naive Bayes Classifier and Prediction on Iris Dataset
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
import seaborn as sns
import matplotlib.pyplot as plt
df = pd.read_csv("C:\\College\\sem 6\\Machine learning\\lab\\exp5\\iris\\iris.data")
print("top 10 features and their labels")
print(df.iloc[:10,:].values)
X = df.iloc[:,:-1].values
y = df.iloc[:,-1].values
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size = 1/3, random_state = 42)
model = GaussianNB()
model.fit(X_train,y_train)
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test,y_pred)
print("Accuracy : ",accuracy)
