#!/bin/bash

# Wait for the database service to be available
sleep 10

# Move to the WordPress directory
cd /var/www/wordpress

# Generate the wp-config.php file
wp core config --dbhost="$WORDPRESS_DB_HOST" \
               --dbname="$WORDPRESS_DB_NAME" \
               --dbuser="$WORDPRESS_DB_USER" \
               --dbpass="$WORDPRESS_DB_PASSWORD" \
               --allow-root

# Go back to the original directory
cd -

# Start PHP-FPM in the foreground
php-fpm7.3 -F
