import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error
import joblib

# Load the dataset
data = pd.read_csv("filtered_predictions.csv")

# Handle Date columns: Convert dates to numeric (number of days since a reference date)
reference_date = pd.Timestamp("2000-01-01")  # Reference date
data["Date-Début"] = (pd.to_datetime(data["Date-Début"]) - reference_date).dt.days
data["Date-Fin"] = (pd.to_datetime(data["Date-Fin"]) - reference_date).dt.days

# Handle categorical variables: Convert to numeric using one-hot encoding
data = pd.get_dummies(data, columns=["Complexité", "Statue", "Nom-Client"], drop_first=True)

# Define features (X) and target (y)
X = data.drop(columns=["Nom-Projet", "Predicted_Duration"])
y = data["Predicted_Duration"]

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train a Random Forest Regressor
model = RandomForestRegressor(n_estimators=100, random_state=42)
model.fit(X_train, y_train)

# Evaluate the model
y_pred = model.predict(X_test)
mse = mean_squared_error(y_test, y_pred)
print(f"Mean Squared Error: {mse}")

# Save the trained model to a file
joblib.dump(model, "project_duration_model.pkl")
print("Model has been saved as 'project_duration_model.pkl'")