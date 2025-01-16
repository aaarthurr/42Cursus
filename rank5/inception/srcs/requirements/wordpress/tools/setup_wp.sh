#!/bin/bash

sleep 10

cd /var/www/wordpress
wp core config	--dbhost=$WORDPRESS_DB_HOST \
				--dbname=$WORDPRESS_DB_NAME \
				--dbuser=$WORDPRESS_DB_USER \
				--dbpass=$WORDPRESS_DB_PASSWORD \
				--allow-root

wp core install --title=$WORDPRESS_TITLE \
				--admin_user=$WORDPRESS_ADMIN \
				--admin_password=$WORDPRESS_ADMIN_PASS \
				--admin_email=$WORDPRESS_ADMIN_MAIL \
				--url=$WP_URL \
				--allow-root

wp user create $WP_USER $WP_USER_MAIL --role=author --user_pass=$WP_USER_PASSWORD --allow-root
cd -

php-fpm7.3 -F