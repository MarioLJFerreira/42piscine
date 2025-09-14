#a="\'?"
#b='"\"'
#c="'"
#d='\'
#FT_NBR1=$a$b$c$d
#FT_NBR2=rcrdmddd


#exc="!"
#escquo='\"\"'
#FT_NBR1=$escquo$exc$escquo$exc$escquo$exc$escquo$exc$escquo$exc$escquo
#FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo

echo $FT_NBR1 + $FT_NBR2 | sed "s/'/0/g" | tr '\\"?!' 1234 | tr 'mrdoc' 01234 | xargs echo 'obase=13; ibase=5;' | bc | tr 0123456789ABC 'gtaio luSnemf'
