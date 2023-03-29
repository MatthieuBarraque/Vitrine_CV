# Utiliser une image de base
FROM ubuntu:20.04

# Créer un répertoire de travail
WORKDIR /app

# Copier le script dans le conteneur
COPY . /app/

# Rendre le script exécutable
RUN chmod +x /app/epitech_env.sh

# Exécuter le script
CMD ["/app/epitech_env.sh"]
