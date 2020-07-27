f=$1
val=$2
#echo $f,$val
cat $f|awk -v k=$val '{if ($6 > k ) print $4,$5,$6} '|wc -l
