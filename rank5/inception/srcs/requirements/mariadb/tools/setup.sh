#!/bin/bash

set -e

# Démarrer MariaDB sans vérifier les privilèges (mode sans privilèges)
mysqld_safe --skip-grant-tables --skip-networking &

# Attendre quelques secondes pour que MariaDB démarre en mode sans privilèges
sleep 5

# Réinitialiser le mot de passe root pour toutes les entrées avec l'utilisateur root
mysql -u root -e "UPDATE mysql.user SET authentication_string=PASSWORD('${MYSQL_ROOT_PASSWORD}') WHERE User='root';"
mysql -u root -e "FLUSH PRIVILEGES;"

# Vérifier et créer l'utilisateur root pour 'arpages.42.fr' si nécessaire
mysql -u root -e "CREATE USER IF NOT EXISTS 'root'@'arpages.42.fr' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
mysql -u root -e "ALTER USER 'root'@'arpages.42.fr' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
mysql -u root -e "FLUSH PRIVILEGES;"

# Créer la base de données si elle n'existe pas
mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"

# Créer l'utilisateur avec mot de passe
mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"

# Accorder tous les privilèges à l'utilisateur pour la base de données
mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%';"

# Rafraîchir les privilèges
mysql -u root -p"${MYSQL_ROOT_PASSWORD}" -e "FLUSH PRIVILEGES;"

# Arrêter MariaDB et redémarrer normalement (pour appliquer les changements de mot de passe)
mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown

# Maintenant, démarrer MariaDB normalement
mysqld_safe &
wait $!
