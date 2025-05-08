import pandas as pd

# Specify the path to your CSV file
file_path = "synthetic_project_data.csv"  # Update the path if the file is located elsewhere

try:
    # Load the CSV file using pandas
    data = pd.read_csv(file_path)

    # Display a success message
    print("CSV file loaded successfully!")

    # Display the first 5 rows of the dataset
    print("Here are the first 5 rows of the data:\n")
    print(data.head())
except FileNotFoundError:
    print(f"Error: The file '{file_path}' was not found. Please check the file path and try again.")
except Exception as e:
    print(f"An error occurred while loading the CSV file: {e}")