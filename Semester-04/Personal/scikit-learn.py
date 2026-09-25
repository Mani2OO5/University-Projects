
def train(x, y):
    from sklearn.linear_model import LinearRegression

    model = LinearRegression().fit(x, y)
    return model


model = train([1, 2, 3, 4], [37.8, 39.3, 45.9, 41.3])

x_new = 23.0
y_new = model.predict([[x_new]])
print(y_new)
