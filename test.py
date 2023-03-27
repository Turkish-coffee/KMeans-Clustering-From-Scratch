import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load the data into a pandas DataFrame
df = pd.read_csv("results.csv")

# Extract the features and cluster labels
X = df.iloc[:, :-1].values
y = df.iloc[:, -1].values

# Create a 3D figure
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the data points with different colors for each cluster
ax.scatter(X[:, 0], X[:, 1], X[:, 2], c=y)

# Set the labels for each axis
ax.set_xlabel('Feature1')
ax.set_ylabel('Feature2')
ax.set_zlabel('Feature3')

# Show the plot
plt.show()



# Create a 3D figure
fig = plt.figure()
bx = fig.add_subplot(111, projection='3d')

# Plot the data points with different colors for each cluster
bx.scatter(X[:, 3], X[:, 4], X[:, 5], c=y)

# Set the labels for each axis
bx.set_xlabel('Feature1')
bx.set_ylabel('Feature2')
bx.set_zlabel('Feature3')

# Show the plot
plt.show()



# Create a 3D figure
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the data points with different colors for each cluster
ax.scatter(X[:, 6], X[:, 7], X[:, 8], c=y)

# Set the labels for each axis
ax.set_xlabel('Feature1')
ax.set_ylabel('Feature2')
ax.set_zlabel('Feature3')

# Show the plot
plt.show()


# Create a 3D figure
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the data points with different colors for each cluster
ax.scatter(X[:, 9], X[:, 10], X[:, 11], c=y)

# Set the labels for each axis
ax.set_xlabel('Feature1')
ax.set_ylabel('Feature2')
ax.set_zlabel('Feature3')

# Show the plot
plt.show()
