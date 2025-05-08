import pandas as pd

# Load the dataset with predictions
file_path = "predictions_output.csv"
data = pd.read_csv(file_path)

# Filter for projects with high complexity ("Élevée") or long predicted durations (> 60 days)
filtered_data = data[(data['Complexité'] == 'Élevée') | (data['Predicted_Duration'] > 60)]

# Display the filtered results
print("Filtered Projects:")
print(filtered_data[['Nom-Projet', 'Complexité', 'Predicted_Duration']])

# Save the filtered results to a new CSV file
output_file = "filtered_predictions.csv"
filtered_data.to_csv(output_file, index=False)
print(f"\nFiltered predictions saved to: {output_file}")