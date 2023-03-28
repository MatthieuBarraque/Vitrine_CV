# Vitrine_CV

Titre du projet: stockmarket_py

Ce projet est une simple application web qui récupère les données boursières de plusieurs actions et les affiche dans une table HTML. L'application est développée en Python en utilisant le framework Flask et la bibliothèque yfinance.

Fonctionnalités :

Récupérer les données boursières en temps réel pour plusieurs actions
Afficher les données dans une table HTML avec des mises à jour automatiques toutes les 5 secondes
Outils et bibliothèques utilisés

Python: Langage de programmation utilisé pour développer l'application

Flask: Framework web léger pour développer des applications web en Python

yfinance: Bibliothèque Python pour récupérer les données boursières depuis Yahoo Finance

Bootstrap: Framework CSS pour faciliter le développement d'interfaces utilisateur responsives et modernes

Aspects techniques :

L'application se compose de deux parties principales :

Le serveur Flask (fichier app.py) qui sert de back-end et gère les requêtes HTTP pour récupérer les données boursières
Le template HTML (fichier index.html) qui sert de front-end et affiche les données boursières dans une table
Le serveur Flask utilise la bibliothèque yfinance pour récupérer les données boursières en temps réel. Une route est définie pour chaque action, permettant de récupérer les données pour une action spécifique. Le front-end utilise JavaScript et jQuery pour effectuer des requêtes AJAX vers le serveur Flask et mettre à jour les données affichées toutes les 5 secondes.