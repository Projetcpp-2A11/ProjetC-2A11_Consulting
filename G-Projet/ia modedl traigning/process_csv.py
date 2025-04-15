import pandas as pd

# Load the CSV file
file_path = "synthetic_project_data.csv"
data = pd.read_csv(file_path)

# 1. Display the column names
print("Columns in the dataset:")
print(data.columns)

# 2. Check for missing values
print("\nChecking for missing values:")
print(data.isnull().sum())

# 3. Drop rows with missing values (optional, depends on your data)
data = data.dropna()
print("\nDataset after dropping missing values:")
print(data.head())

# 4. Display basic statistics about numeric data
print("\nBasic statistics:")
print(data.describe())