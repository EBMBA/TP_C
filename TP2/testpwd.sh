#!/bin/bash
PSWD="123+aze"
read -sp 'Entre le mot de passe : ' SAISI

if [ x$PSWD = x$SAISI ]; then
	echo "C'est bon"
else
	echo "C'est pas bon"
fi
