ifconfig -a | grep -o 'ether [[:xdigit:]:]*' | sed 's/ether //'
