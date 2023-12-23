import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
import numpy as np
from sklearn.datasets import make_regression
ds = make_regression(45, 2, n_targets=1, noise=1)
X = ds[0]
Y = ds[1]
# np.savetxt("Xarr.csv",X=X,delimiter=",")
# np.savetxt("Yarr.csv",X=Y,delimiter=",")
X = np.loadtxt("Xarr.csv", delimiter=",")[1:, :]
y = np.loadtxt("Yarr.csv", delimiter=",")[1:]
model = LinearRegression()
model.fit(X, y)

# plt.show()
weights = np.ones((2,))
bias = 0


def predict(X, weight, bias):
    return X.dot(weight)+bias


def cost(y, yhat):
    return np.sum((y-yhat)**2)


def gradient_descent(X, y, weight, bias):
    pred = predict(X, weight, bias)
    print(pred)
    print(cost(pred, y))
    weight = weight - (0.001/X.shape[0])*(X.T.dot(pred-y))
    bias = bias - (0.001/X.shape[0])*(np.sum(pred-y))
    return (weight, bias)


for i in range(10000):
    weights, bias = gradient_descent(X, y, weights, bias)
print(weights, bias)
print(model.coef_, model.intercept_)
plt.scatter(X[:, 0], y)
plt.show()
