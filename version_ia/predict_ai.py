import sys
import joblib
import pandas as pd

# Charger le modèle
import os
model_path = os.path.join(os.path.dirname(__file__), 'model_duration.pkl')
if not os.path.exists(model_path):
    print('Erreur: model_duration.pkl introuvable dans', model_path, flush=True)
    exit(1)
model = joblib.load(model_path)

# Récupérer les arguments de la ligne de commande
# Usage: python predict_ai.py <titre> <complexite> <statut> <budget> <start_date> <end_date>
# Argument parsing that works even if some args are missing
args = sys.argv[1:]
titre = args[0] if len(args) > 0 else ""
complexite = args[1] if len(args) > 1 else ""
statut = args[2] if len(args) > 2 else ""
budget = args[3] if len(args) > 3 else ""
start_date = args[4] if len(args) > 4 else ""
end_date = args[5] if len(args) > 5 else ""

# Préparer l'entrée pour la prédiction
input_data = pd.DataFrame([{
    'COMPLEXITE': complexite,
    'STATUT_PR': statut,
    'BUDGET': float(budget) if budget else 0
}])
input_data = pd.get_dummies(input_data)

# Adapter les colonnes pour correspondre au modèle
model_columns = model.feature_names_in_
for col in model_columns:
    if col not in input_data:
        input_data[col] = 0
input_data = input_data[model_columns]

# Prédire la durée
predicted_duration = int(model.predict(input_data)[0])

# Debug : afficher les entrées et la prédiction
print(f"[DEBUG] Input: {input_data.to_dict()} - Prediction: {predicted_duration}", file=sys.stderr)

# Analyse avancée des stats du dataset
try:
    import joblib
    import pandas as pd
    df = pd.read_csv(os.path.join(os.path.dirname(__file__), 'export.csv'), sep='\t', encoding='latin1')
    median_duration = df['DUREE_REELLE'].median()
    mean_duration = df['DUREE_REELLE'].mean()
    max_duration = df['DUREE_REELLE'].max()
    min_duration = df['DUREE_REELLE'].min()
    median_budget = df['BUDGET'].median()
    max_budget = df['BUDGET'].max()
    min_budget = df['BUDGET'].min()
except Exception as e:
    median_duration = 20
    mean_duration = 20
    max_duration = 200
    min_duration = 0
    median_budget = 100000
    max_budget = 1000000
    min_budget = 0

# Risque de retard plus intelligent
risk_score = 0
if predicted_duration > mean_duration * 1.2:
    risk_score += 2
elif predicted_duration > mean_duration:
    risk_score += 1
if complexite.lower() in ["élevée", "elevee", "haute"]:
    risk_score += 2
elif complexite.lower() == "moyenne":
    risk_score += 1
if budget and float(budget) > median_budget:
    risk_score += 1

if risk_score >= 4:
    predicted_risk = "Très élevé"
elif risk_score >= 2:
    predicted_risk = "Élevé"
elif risk_score == 1:
    predicted_risk = "Modéré"
else:
    predicted_risk = "Faible"

# Conseil dynamique avancé
if predicted_risk == "Très élevé":
    predicted_advice = "Découpez le projet en sous-projets et ajoutez des ressources expérimentées."
elif predicted_risk == "Élevé":
    predicted_advice = "Planifiez des points de contrôle fréquents et surveillez les risques."
elif predicted_risk == "Modéré":
    predicted_advice = "Restez attentif, mais la situation est sous contrôle."
elif statut.lower() == "en attente":
    predicted_advice = "Démarrez le projet dès que possible pour éviter les retards."
elif statut.lower() == "en cours":
    predicted_advice = "Continuez sur cette lancée !"
else:
    predicted_advice = "Projet sous contrôle, continuez à monitorer."

# Debug context avancé
print(f"[DEBUG] Input: {input_data.to_dict()} | Durée prédite: {predicted_duration} | Budget: {budget} | Complexité: {complexite} | Statut: {statut} | RiskScore: {risk_score} | MedianDur: {median_duration} | MedianBud: {median_budget}", file=sys.stderr)

# Afficher le résultat au format attendu par Qt
print(f"{predicted_duration}|{predicted_risk}|{predicted_advice}")
