import sys
import json
import joblib
import pandas as pd
import numpy as np
from datetime import datetime

def prepare_input(project_data):
    """Prepare input data for prediction"""
    # Create a DataFrame with one row
    df = pd.DataFrame([project_data])
    
    # Convert dates to numeric (days since reference date)
    reference_date = pd.Timestamp("2000-01-01")
    df["Date-Début"] = (pd.to_datetime(df["Date-Début"]) - reference_date).dt.days
    df["Date-Fin"] = (pd.to_datetime(df["Date-Fin"]) - reference_date).dt.days
    
    # One-hot encode categorical variables
    df = pd.get_dummies(df, columns=["Complexité", "Statue", "Nom-Client"], drop_first=True)
    
    # Make sure all columns used during training are present
    # You may need to adjust this based on your actual model's expected features
    expected_columns = model.feature_names_in_
    for col in expected_columns:
        if col not in df.columns:
            df[col] = 0
            
    # Select only the columns the model was trained on
    df = df[expected_columns]
    
    return df

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python predict_duration.py <input_json_file>")
        sys.exit(1)
    
    # Load the model
    model = joblib.load("project_duration_model.pkl")
    
    # Load input data
    with open(sys.argv[1], 'r') as f:
        project_data = json.load(f)
    
    # Prepare input
    X = prepare_input(project_data)
    
    # Make prediction
    predicted_duration = model.predict(X)[0]
    
    # Output the result (rounded to nearest integer)
    print(int(round(predicted_duration)))