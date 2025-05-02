import pandas as pd
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
import joblib

# Charger les données (adapter le chemin si besoin)
df = pd.read_csv('export.csv', sep='\t', encoding='latin1')

# Nettoyage des caractères spéciaux (optionnel)
df['COMPLEXITE'] = df['COMPLEXITE'].str.replace('�', 'é')
df['STATUT_PR'] = df['STATUT_PR'].str.replace('�', 'é')

# Préparation des features et de la cible
X = df[['COMPLEXITE', 'STATUT_PR', 'BUDGET']]
X = pd.get_dummies(X)
y = df['DUREE_REELLE']

# Séparation train/test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Entraînement du modèle
model = RandomForestRegressor()
model.fit(X_train, y_train)

# Sauvegarde du modèle
joblib.dump(model, 'model_duration.pkl')

# Évaluation rapide
score = model.score(X_test, y_test)
print(f"Score R2 sur le test : {score:.2f}")