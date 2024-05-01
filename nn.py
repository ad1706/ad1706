# 9 Neural Networks OR Gate
import numpy as np 
X = np.array(([0,0],[0,1],[1,0],[1,1])) 
Y = np.array(([0],[1],[1],[1])) 
X = X / np.amax(X, axis=0)    
# Sigmoid function 
def sigmoid(x): 
    return 1 / (1 + np.exp(-x)) 
# Derivative of Sigmoid function 
def derivatives_sigmoid(x): 
    return x * (1 - x) 
# Variable initialization 
epoch = 7000 
lr = 0.1 
inputlayer_neurons = 2 
hiddenlayer_neurons = 1 
output_neurons = 1 
# weight and bias initialization 
wh = np.random.uniform(size=(inputlayer_neurons, hiddenlayer_neurons)) 
bh = np.random.uniform(size=(1, hiddenlayer_neurons)) 
wout = np.random.uniform(size=(hiddenlayer_neurons, output_neurons)) 
bout = np.random.uniform(size=(1, output_neurons)) 
# draws a random range of numbers uniformly of dim x*y 
for i in range(epoch): 
    # Forward Propagation 
    hinp1 = np.dot(X, wh) 
    hinp = hinp1 + bh 
    hlayer_act = sigmoid(hinp) 
    outinp1 = np.dot(hlayer_act, wout) 
    outinp = outinp1 + bout 
    output = sigmoid(outinp) 
    # BackPropagation 
    EO = Y - output 
    outgrad = derivatives_sigmoid(output) 
    d_output = EO * outgrad 
    EH = d_output.dot(wout.T) 
    hiddengrad = derivatives_sigmoid(hlayer_act) # how much hidden layer wts c 
    d_hiddenlayer = EH * hiddengrad 
    wout += hlayer_act.T.dot(d_output) * lr 
    wh += X.T.dot(d_hiddenlayer) * lr 
print("Input: \n" + str(X)) 
print("Actual Output: \n" + str(Y)) 
print("Predicted Output: \n", output)
​
​
​
# 9 Neural Networks EX-OR Gate
import numpy as np
def sigmoid(x):
    return 1 / (1 + np.exp(-x))
def sigmoid_derivative(x):
    return x * (1 - x)
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
expected_output = np.array([[0], [1], [1], [0]])
inputLayerNeurons, hiddenLayerNeurons, outputLayerNeurons = 2, 2, 1
hidden_weights = np.random.uniform(size=(inputLayerNeurons, hiddenLayerNeurons))
hidden_bias = np.random.uniform(size=(1, hiddenLayerNeurons))
output_weights = np.random.uniform(size=(hiddenLayerNeurons, outputLayerNeurons))
output_bias = np.random.uniform(size=(1, outputLayerNeurons))
for _ in range(10000):
    hidden_layer_activation = np.dot(inputs, hidden_weights)
    hidden_layer_activation += hidden_bias
    hidden_layer_output = sigmoid(hidden_layer_activation)
    output_layer_activation = np.dot(hidden_layer_output, output_weights)
    output_layer_activation += output_bias
    predicted_output = sigmoid(output_layer_activation)
    # Backpropagation
    error = expected_output - predicted_output
    d_predicted_output = error * sigmoid_derivative(predicted_output)
    error_hidden_layer = d_predicted_output.dot(output_weights.T)
    d_hidden_layer = error_hidden_layer * sigmoid_derivative(hidden_layer_output)
    # Updating Weights and Biases
    output_weights += hidden_layer_output.T.dot(d_predicted_output) * 0.1
    output_bias += np.sum(d_predicted_output, axis=0, keepdims=True) * 0.1
    hidden_weights += inputs.T.dot(d_hidden_layer) * 0.1
    hidden_bias += np.sum(d_hidden_layer, axis=0, keepdims=True) * 0.1
print("Final hidden weights: ", end="")
print(*hidden_weights)
print("Final hidden bias: ", end="")
print(*hidden_bias)
print("Final output weights: ", end="")
print(*output_weights)
print("Final output bias: ", end="")
print(*output_bias)
print("\nOutput from neural network after 10,000 epochs: ", end="")
print(*predicted_output)
​
​
​
# 9 Neural Networks Classify flowers based on length and width
import numpy as np
answer = {0: "red", 1: "blue"}
# initializing weights and expected outputs
inputs = np.array([[3,1.5],[2,1],[4,1.5],[3,1],[3.5,0.5],[2,0.5],[5.5,1],[1,1]])
expected_output = np.array([[0],[1],[0],[1],[0],[1],[0],[1]])
inputlayerneurons, hiddenlayerneurons, outputlayerneurons = 2, 2, 1
hidden_weights = np.random.uniform(size=(inputlayerneurons, hiddenlayerneurons))
hidden_bias = np.random.uniform(size=(1, hiddenlayerneurons))
output_weights = np.random.uniform(size=(hiddenlayerneurons, outputlayerneurons))
output_bias = np.random.uniform(size=(1, outputlayerneurons))
# defining
def sigmoid(x):
    return 1 / (1 + np.exp(-x))
def sigmoid_derivative(x):
    return x * (1 - x)
lr = 0.1
for i in range(10000):
    hidden_layer_activation = np.dot(inputs, hidden_weights)
    hidden_layer_activation += hidden_bias
    hidden_layer_output = sigmoid(hidden_layer_activation)
    output_layer_activation = np.dot(hidden_layer_output, output_weights)
    output_layer_activation += output_bias
    predicted_output = sigmoid(output_layer_activation)
    # BackPropagation
    error = expected_output - predicted_output
    d_predicted_output = error * sigmoid_derivative(predicted_output)
    error_hidden_layer = d_predicted_output.dot(output_weights.T)
    d_hidden_layer = error_hidden_layer * sigmoid_derivative(hidden_layer_output)
    # updating weights & biases
    output_weights += hidden_layer_output.T.dot(d_predicted_output) * lr
    output_bias += np.sum(d_predicted_output, axis=0, keepdims=True) * lr
    hidden_weights += inputs.T.dot(d_hidden_layer) * lr
    hidden_bias += np.sum(d_hidden_layer, axis=0, keepdims=True) * lr
hidden_layer_activation = np.dot([[4.5, 1]], hidden_weights)
hidden_layer_activation += hidden_bias
hidden_layer_output = sigmoid(hidden_layer_activation)
output_layer_activation = np.dot(hidden_layer_output, output_weights)
output_layer_activation += output_bias
predicted_output = sigmoid(output_layer_activation)
print("Predicted output ", predicted_output)
if predicted_output <= 0.5:
    print("Red")
else:
    print("Blue")
