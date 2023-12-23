import numpy as np
from sklearn.datasets import make_regression
ds = make_regression(6,2,n_targets=1)
X=ds[0]
Y=ds[1]
# np.savetxt("Xarr.csv",X=X,delimiter=",")
# np.savetxt("Yarr.csv",X=Y,delimiter=",")
X=np.loadtxt("Xarr.csv",delimiter=",")[1:,:]
y=np.loadtxt("Yarr.csv",delimiter=",")[1:]
from sklearn.linear_model import LinearRegression
model = LinearRegression()
model.fit(X,y)
print(model.coef_)