#!/bin/bash

function is_number()
{
	re='^[+-]?[0-9]+([.][0-9]+)?$'

	if ! [[ $1 =~ $re ]] ; then
		return 1
	else
		return 0
	fi
}

is_number $1
nbr=$?

if [ $nbr -eq 0 ]; then
	echo "C'est un reel"
else
	echo "Erreur"
fi
