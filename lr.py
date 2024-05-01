# 2 Linear Regression
import numpy as np
from sklearn.linear_model import LinearRegression
x=np.array([10,20,30,40,50]).reshape((-1,1)) #x transpose 
y=np.array([15,23,35,41,59])
model = LinearRegression()
model.fit(x,y)
r_sq=model.score(x,y)
print('coefficient of determination:', r_sq)
print('intercept w0:',model.intercept_)
print('slope w1:',model.coef_)
y_pred=model.predict(x) #y_pred=model.intercept_ + model.coef_*x
print('predicted response:', y_pred, sep='\n')
x_new=np.arange(5).reshape((-1,1))
print('x_new:',x_new)
y_new=model.predict(x_new)
print('y_new:',y_new)
​
​
​
# 2 Linear Regression Multi Class Classification
import numpy as np
from sklearn.linear_model import LinearRegression
x=[[0,1],[5,1],[15,2],[25,5],[35,11],[45,15],[55,34],[60,35]]
y=[4,5,20,14,32,22,38,43]
model=LinearRegression().fit(x,y)
r_sq=model.score(x,y)
print('coefficient of determination', r_sq)
print('intercept:', model.intercept_)
print('slope:',model.coef_)
y_pred=model.predict(x) #y_pred=model.intercept_ + np.sum(model.coef_ *x,axis=1)
print('predicted response:',y_pred,sep='\n')
x_new=np.arange(10).reshape((-1,2))
print('x_new:',x_new)
y_new=model.predict(x_new)
print('y_new:',y_new)
​
​
​
# 2 Linear Regression Salary Prediction
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split #shuffles the data randomly and then splits it into two subsets.
from sklearn.linear_model import LinearRegression
#importing the dataset
dataset=pd.read_csv('C:\College\sem 6\Machine learning\lab\exp2\Machine-Learning-Algorithms-Dataset-master\Salary_Data.csv')
X=dataset.iloc[:, :-1].values #X represents input features (independent variables)
y=dataset.iloc[:, :-1].values #y represents target variable (dependent variable)
# Splitting the dataset into the Training set and Test set 
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size=2/3,random_state=0) #2/3rd data will be used for testing
# Fitting Simple Linear Regression to the Training set 
regressor = LinearRegression().fit(X_train,y_train)
# Predicting the Test set results
y_pred=regressor.predict(X_test)
# Visualising the Training set results 
plt.scatter(X_train,y_train,color='red')
plt.plot(X_train,regressor.predict(X_train),color='blue')
plt.title('Salary vs Experience (Training set)')
plt.xlabel('Years of Experience') 
plt.ylabel('Salary')
plt.show()
# Visualising the Test set results
plt.scatter(X_test,y_test,color='red')
plt.plot(X_train,regressor.predict(X_train),color='blue')
plt.title('Salary vs Experience (Test set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()
​
​
​
# 2 Logistic Regression Multi Class
import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report
# Load Iris dataset
iris = datasets.load_iris()
#print(iris)
X = iris.data
y = iris.target
# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
# Standardize the features
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)
# Create a logistic regression model
model = LogisticRegression()
# Train the model
model.fit(X_train, y_train)
# Make predictions on the test set
predictions = model.predict(X_test)
# Evaluate the model
accuracy = accuracy_score(y_test, predictions)
report = classification_report(y_test, predictions)
# Print the results
print(f"Accuracy: {accuracy}")
print("Classification Report:\n", report)
​
​
# 2 Linear Regression Stock Market Prediction
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt
import seaborn as sns
# Download the dataset manually from Kaggle and load it using pandas
df = pd.read_csv("C:\College\sem 6\Machine learning\lab\exp2\prices for ex1\prices-split-adjusted.csv")
# Display the first few rows of the dataset
print(df.head())
# Select relevant features and target variable
features = df[['open', 'low', 'high', 'volume']]  # Adjust features as needed
target = df['close']  # Adjust target variable as needed
# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(features, target, test_size=0.2, random_state=42)
# Create and train the linear regression model
model = LinearRegression()
model.fit(X_train, y_train)
# Make predictions on the test set
y_pred = model.predict(X_test)
# Evaluate the model
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)
print(f'Mean Squared Error: {mse}')
print(f'R2 Score: {r2}')
# Visualize the predictions
plt.figure(figsize=(10, 6))
sns.scatterplot(x=y_test, y=y_pred)
plt.xlabel('Actual Prices')
plt.ylabel('Predicted Prices')
plt.title('Actual Prices vs Predicted Prices')
plt.show()
​
​
​
# 2 Logistic Regression Confusion Matrix
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix, accuracy_score
from sklearn.preprocessing import StandardScaler
# Load the Breast Cancer dataset
data = load_breast_cancer()
X = data.data
y = data.target
# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
# Scale the features
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)
# Create and fit the logistic regression model
model = LogisticRegression()
model.fit(X_train_scaled, y_train)
# Make predictions
y_pred = model.predict(X_test_scaled)
# Calculate accuracy
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy:", accuracy)
# Plot confusion matrix
cm = confusion_matrix(y_test, y_pred)
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, cmap='Blues', fmt='g', xticklabels=data.target_names, yticklabels=data.target_names)
plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix')
plt.show()
​
​
​
# 2 Linear Regression Stochastic Gradient Descent
import numpy as np
class LinearRegressionSGD:
    def __init__(self, learning_rate=0.01, n_epochs=100, batch_size=1):
        self.learning_rate = learning_rate
        self.n_epochs = n_epochs
        self.batch_size = batch_size
        self.weights = None
        self.bias = None   
    def fit(self, X, y):
        n_samples, n_features = X.shape
        self.weights = np.zeros(n_features)
        self.bias = 0   
        for _ in range(self.n_epochs):
            for i in range(0, n_samples, self.batch_size):
                X_batch = X[i:i+self.batch_size]
                y_batch = y[i:i+self.batch_size]
                self._update_weights(X_batch, y_batch)
    
    def _update_weights(self, X_batch, y_batch):
        n_samples = X_batch.shape[0]
        y_predicted = np.dot(X_batch, self.weights) + self.bias   
        # Calculate gradients
        d_weights = (-2 / n_samples) * np.dot(X_batch.T, (y_batch - y_predicted))
        d_bias = (-2 / n_samples) * np.sum(y_batch - y_predicted)        
        # Update weights and bias
        self.weights -= self.learning_rate * d_weights
        self.bias -= self.learning_rate * d_bias  
    def predict(self, X):
        return np.dot(X, self.weights) + self.bias
# Example usage
if __name__ == "__main__":
    # Sample data
    X = np.array([[1], [2], [3], [4], [5]])
    y = np.array([2, 4, 5, 4, 5])    
    # Initialize and train the model
    model = LinearRegressionSGD(learning_rate=0.01, n_epochs=100, batch_size=1)
    model.fit(X, y)  
    # Predict
    X_test = np.array([[6], [7]])
    predictions = model.predict(X_test)
    print("Predictions:", predictions)
