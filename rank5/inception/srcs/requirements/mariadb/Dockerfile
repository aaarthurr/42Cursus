FROM debian:buster

# Installer MariaDB et les utilitaires nécessaires
RUN apt update -y && apt upgrade -y \
    && apt-get install -y mariadb-server procps \
    && rm -rf /var/lib/apt/lists/*

# Créer les répertoires nécessaires pour le bon fonctionnement de MySQL
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld
RUN mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql

# Copier la configuration de MariaDB
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copier le script d'initialisation
COPY ./tools/setup.sh /setup.sh

# Donner les permissions nécessaires au script
RUN chmod +x /setup.sh

# Exposer le port MariaDB
EXPOSE 3306

# Exécuter le script d'initialisation au démarrage du conteneur
ENTRYPOINT ["/setup.sh"]

# Garder MariaDB en fonctionnement une fois configuré
CMD ["mysqld"]
