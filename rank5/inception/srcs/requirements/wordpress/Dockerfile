FROM debian:buster

RUN apt update && \
    apt upgrade -y && \
    apt-get -y install wget && \
    apt-get install -y php7.3 \
                       php7.3-fpm \
                       php7.3-mysql \
                       mariadb-client && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www && \
    tar -xzf /var/www/wordpress-6.0-fr_FR.tar.gz -C /var/www && \
    rm /var/www/wordpress-6.0-fr_FR.tar.gz && \
    chown -R www-data:www-data /var/www/wordpress && \
    chmod -R 755 /var/www/wordpress 

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php && \
    mkdir -p /home/root/data/wordpress

COPY conf/php-fpm.conf /etc/php/7.3/fpm/pool.d

COPY tools/setup_wp.sh /setup_wp.sh

RUN chmod +x setup_wp.sh

EXPOSE 9000

CMD ["/setup_wp.sh"]