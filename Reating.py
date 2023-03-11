import numpy as np
import json
import requests
import matplotlib.pyplot as plt

# The User
WHO = 'ayush_malviya'
# The size of the graph (1x, 2x, 3x of the original contests)
PERIOD = 2


def estimate_coef(x, y):
    fit = np.polyfit(np.log2(x), y, 1)
    return fit


def plot_regression_line(x, y, b):
    # plotting the actual points as scatter plot
    plt.scatter(x, y, color="m",
                marker="o", s=30)
    x = range(1, len(y) * PERIOD)
    # predicted response vector
    y_pred = []
    for e in x:
        y_pred.append(b[1] + b[0]*np.log2(e))
    # plotting the regression function
    plt.plot(range(1, len(y) * PERIOD), y_pred, color="g")
    # putting labels
    plt.xlabel('Contests')
    plt.ylabel('Rating')
    plt.title(WHO)
    # function to show plot
    plt.show()


def get_user_rating():
    # GET request to Codeforces API to get rating history for user
    response = requests.get(
        'https://codeforces.com/api/user.rating?handle='+WHO).text
    return json.loads(response)


def main():
    # GET user rating history
    data = get_user_rating()
    y = [i['newRating'] for i in data['result']]
    x = np.array(range(1, len(y)+1))
    # estimating coefficients
    b = estimate_coef(x, y)
    # plotting regression function
    plot_regression_line(x, y, b)


if __name__ == "__main__":
    main()