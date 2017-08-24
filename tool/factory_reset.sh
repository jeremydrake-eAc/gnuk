#!/bin/sh
#ensure both user and admin pins are locked
for i in `seq 1 4`; do
	gpg-connect-agent --hex "scd apdu 00 20 00 81 08 40 40 40 40 40 40 40 40" /bye
	gpg-connect-agent --hex "scd apdu 00 20 00 83 08 40 40 40 40 40 40 40 40" /bye
done

#terminate card
gpg-connect-agent --hex "scd apdu 00 e6 00 00" /bye
#reactivate card
gpg-connect-agent --hex "scd apdu 00 44 00 00" /bye


