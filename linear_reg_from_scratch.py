from sklearn.datasets import make_regression
ds = make_regression(100,2,n_targets=1)
X=ds[0]
Y=ds[1]
import numpy as np
np.savetxt("Xarr.csv",X=X,delimiter=",")
np.savetxt("Yarr.csv",X=Y,delimiter=",")
X=np.loadtxt("Xarr.csv",delimiter=",")
y=np.loadtxt("Yarr.csv",delimiter=",")
from sklearn.linear_model import LinearRegression
model = LinearRegression()
model.fit(X,y)
print(model.coef_)