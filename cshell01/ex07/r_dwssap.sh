grep -v '^#' /etc/passwd | sed -n '2~2p' | cut -d: -f1 | rev | sort -r | sed -n "${FT_LINE1:-1},${FT_LINE2:-\$}p"| tr '\n' ' '   | sed 's+ +, +g' | sed 's+, $+.+g' | tr -d '\n'
