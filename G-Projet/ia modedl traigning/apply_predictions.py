import pandas as pd

# Load the cleaned CSV file
file_path = "synthetic_project_data.csv"
data = pd.read_csv(file_path)

# Define a mock AI prediction function
def predict_duration(row):
    """
    Mock AI prediction function to predict project duration in days.
    Logic:
    - Faible (Low complexity): 30 days
    - Moyenne (Medium complexity): 60 days
    - Élevée (High complexity): 90 days
    """
    if row['Complexité'] == 'Faible':
        return 30
    elif row['Complexité'] == 'Moyenne':
        return 60
    elif row['Complexité'] == 'Élevée':
        return 90
    else:
        return None  # Undefined complexity

# Apply the prediction function to each row in the dataset
data['Predicted_Duration'] = data.apply(predict_duration, axis=1)

# Display the updated dataset with predictions
print("Dataset with predicted durations:")
print(data[['Nom-Projet', 'Complexité', 'Predicted_Duration']])

# Save the updated dataset to a new CSV file
output_file = "predictions_output.csv"
data.to_csv(output_file, index=False)
print(f"\nPredictions saved to: {output_file}")