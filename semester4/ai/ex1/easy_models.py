import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import numpy as np


def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

def normalize(arr):
    return (arr - np.min(arr)) / (np.max(arr) - np.min(arr))

class EasyRegressionModel:

    def __init__(self, csv_path):
        #Set up training / test data
        self.data = pd.read_csv(csv_path)
        self.x_train, self.x_test , self.y_train, self.y_test = train_test_split(self.data[["Age","YearsWorked"]], self.data["Income"], test_size=0.2, random_state=1)
        self.train_pred = None
        self.test_pred = None

        #Set up linear regression model
        self.lr = LinearRegression()
        self.lr.fit(self.x_train, self.y_train)

    def limit_test(self, N):
        self.x_test = self.x_test[:N]
        self.y_test = self.y_test[:N]

    def predict(self):
        self.train_pred = self.lr.predict(self.x_train)
        self.test_pred = self.lr.predict(self.x_test)

    def plot(self):
        try:
            plt.plot(self.x_test["Age"], self.y_test, 'bo', alpha=0.1)
            plt.plot(self.x_test["Age"], self.test_pred, 'ro', markersize=5)
            plt.show()
        except:
            raise ValueError ("Model must be predicted first.")

    def calculate_mse(self):
        try:
            mse_trained = mean_squared_error(self.y_train, self.train_pred)
            mse_tested = mean_squared_error(self.y_test, self.test_pred)
            print("Trained Mean Squared Error = ", mse_trained)
            print("Tested Mean Squared Error = ", mse_tested)
        except:
            raise ValueError("Model must be predicted first.")

class EasyNNClassifierModel:
    def __init__(self, csv_path):
        # Set up synaptic weights
        np.random.seed(1)
        self.synaptic_weights = 2 * np.random.random((3, 1)) - 1

        #Set up training / test data
        self.data = pd.read_csv(csv_path)
        self.x_train, self.x_test , self.y_train, self.y_test = train_test_split(self.data[["Age","YearsWorked","Income"]], self.data["Credible"], test_size=0.2, random_state=1)

        #Reformatting....
        self.x_train = self.x_train.to_numpy().astype(float)
        self.x_test = self.x_test.to_numpy().astype(float)
        self.x_train[:, 0] = normalize(self.x_train[:, 0])
        self.x_test[:, 0] = normalize(self.x_test[:, 0])
        self.x_train[:, 1] = normalize(self.x_train[:, 1])
        self.x_test[:, 1] = normalize(self.x_test[:, 1])
        self.x_train[:, 2] = normalize(self.x_train[:, 2])
        self.x_test[:, 2] = normalize(self.x_test[:, 2])

        #Transpose y-values
        self.y_train = self.y_train.to_numpy().astype(float).reshape(-1, 1)
        self.y_test = self.y_test.to_numpy().astype(float).reshape(-1, 1)


    def limit_test(self, N):
        self.x_test = self.x_test[:N]
        self.y_test = self.y_test[:N]


    def train(self):
        learning_rate = 0.005
        for i in range(10000):

            output = sigmoid(np.dot(self.x_train, self.synaptic_weights))

            # calculate error
            error = self.y_train - output

            # calculate which weights have to be adjusted the most
            adjustments = error * sigmoid_derivative(output)

            # update weights
            self.synaptic_weights = self.synaptic_weights + learning_rate * np.dot(self.x_train.T, adjustments)


    def predict(self, x):
        return np.round(sigmoid(np.dot(x, self.synaptic_weights)))


    def predict_test(self):
        predictions = []
        for x in self.x_test:
            predictions.append(self.predict(x))

        return predictions, self.y_test


    def predict_train(self):
        predictions = []
        for x in self.x_train:
            predictions.append(self.predict(x))

        return predictions, self.y_train


    def calculate_error_ratio(self):
        #Das ratio ist nicht ganz richtig, da der Code für die Confusion Matrix sonst schon hier drin stehen würde
        test_prediction, y_test = self.predict_test()
        train_prediction, y_train = self.predict_train()

        test_out_sum = np.sum(y_test).astype(int)
        train_out_sum = np.sum(y_train).astype(int)

        test_ratio = sum(test_prediction)/test_out_sum
        train_ratio = sum(train_prediction)/train_out_sum
        print("Test Error Ratio = ", test_ratio)
        print("Train Error Ratio = ", train_ratio)


if __name__ == "__main__":
    test = EasyNNClassifierModel("age_income_years_worked.csv")
    test.limit_test(10000)
    test.train()
    test.calculate_error_ratio()
