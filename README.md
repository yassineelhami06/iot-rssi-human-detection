# Détection de présence humaine par analyse RSSI des signaux Wi-Fi

## 📌 Description du projet

Ce projet IoT a pour objectif de détecter la présence ou le mouvement d'une personne en analysant les variations du signal Wi-Fi (RSSI).

Le système exploite le fait que le corps humain, riche en eau, absorbe et perturbe les ondes électromagnétiques Wi-Fi (2.4 GHz), provoquant ainsi une diminution de la puissance du signal reçu.

Le projet a été développé et simulé avec un ESP32 sur la plateforme Wokwi, avec visualisation temps réel via MQTT et ThingsBoard.

---

## 🎯 Objectifs

- Mesurer le RSSI en temps réel avec un ESP32
- Filtrer les fluctuations instables du signal
- Simuler l'atténuation causée par le corps humain
- Détecter une présence humaine à partir des variations RSSI
- Afficher les données sur un dashboard IoT
- Générer des alertes de détection

---

## 🧠 Concept scientifique

Le projet repose sur le modèle suivant :

```
RSSI = A − 10n log₁₀(d) − Lh
```

Où :
- **RSSI** : puissance du signal reçu
- **d** : distance entre l'émetteur et le récepteur
- **Lh** : atténuation causée par le corps humain

Le corps humain agit comme un obstacle électromagnétique capable d'absorber et de diffuser une partie du signal Wi-Fi.

---

## ⚙️ Architecture du système

```
WiFi → ESP32 → Analyse RSSI → Filtrage → Détection → MQTT → ThingsBoard Dashboard
```

---

## 🧩 Technologies utilisées

- ESP32
- Wi-Fi RSSI
- MQTT
- ThingsBoard
- Wokwi
- Arduino / C++
- Potentiomètre (simulation d'atténuation humaine)

---

## 📡 Fonctionnalités principales

✔ Mesure RSSI en temps réel  
✔ Filtrage du signal  
✔ Détection de présence humaine  
✔ Simulation interactive d'atténuation  
✔ Dashboard IoT temps réel  
✔ Génération d'alertes  
✔ Monitoring à distance

---

## 🔧 Composants utilisés

| Composant | Description |
|-----------|-------------|
| ESP32 | Microcontrôleur principal |
| Wi-Fi | Acquisition RSSI |
| Potentiomètre | Simulation d'atténuation humaine |
| MQTT | Transmission des données |
| ThingsBoard | Visualisation et dashboard |

---

## 🚀 Instructions d'exécution

### 1. Ouvrir le projet Wokwi

Importer :
- [`main.cpp`](./main.cpp)
- [`diagram.json`](./diagram.json)

### 2. Lancer la simulation

Cliquer sur :
- "Start Simulation"

### 3. Observer les données

Le Serial Monitor affiche :
- RSSI réel
- RSSI filtré
- Atténuation
- État de détection

### 4. Tester la détection

Tourner le potentiomètre afin de simuler :
- présence humaine
- obstruction du signal Wi-Fi

Le système déclenche alors :
- une alerte
- une variation du RSSI
- une mise à jour du dashboard

---

## 📊 Dashboard IoT

Le dashboard ThingsBoard permet de visualiser :
- RSSI en temps réel
- état de présence
- alertes
- variations du signal

---

## 🔗 Liens du projet

### Wokwi
[lien Wokwi](https://wokwi.com/projects/463202493294010369) 

### GitHub
[lien GitHub](https://github.com/yassineelhami06/iot-rssi-human-detection)

### ⚠️ Troubleshooting

If you encounter connection delays or dashboard loading issues with ThingsBoard, simply refresh the page and wait a few seconds.

The public/demo ThingsBoard server may occasionally experience reloads or temporary latency.

To improve development stability, the project was compiled locally using VSCode + PlatformIO instead of relying entirely on online compilation.

---

## 📷 Captures



-[`screenshots`](./screenshots)

---

## 🏆 Valeur ajoutée du projet

Contrairement aux projets IoT classiques utilisant des capteurs PIR ou ultrasoniques, ce système exploite directement les propriétés physiques des signaux Wi-Fi afin d'estimer une présence humaine.

Cette approche offre une solution plus innovante, orientée recherche et traitement du signal, tout en restant compatible avec des architectures IoT modernes.

---

## 👨‍💻 Auteurs

- Yassine El Hami
- Yahya EL-khoulati
- Barae Belfaida
