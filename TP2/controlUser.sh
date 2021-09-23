#!/bin/bash

function is_user {
    userExist=0
    for user in $(cut -d: -f1 /etc/passwd | sort -r); do
        if [ x$user = x$1 ]; then
            echo 'Utilisateur existe'
            userExist=1
        fi
    done
    return $userExist
}

if [ $# -ge 1 ]; then
    is_user $1
    if [ $? -ne 1 ]; then
        echo 'Utilisateur inconnu'
    fi
else
    echo "Utilisation $0 nom_utilisateur"
fi

