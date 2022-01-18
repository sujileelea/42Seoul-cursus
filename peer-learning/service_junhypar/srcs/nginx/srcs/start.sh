#rc-status && touch /run/openrc/softlevel

echo "<h1>ft_services start</h1>" >> /var/www/index.html
#/usr/sbin/sshd
#rc-service sshd restart
#rc-service nginx restart
nginx -g "daemon off;"
