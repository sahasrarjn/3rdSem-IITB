clear
g++ -O2 -w testcases/copy.cpp
# g++ -O2 -w copy.cpp
rm log.txt

for f in testcases/*.in;
do
    time testcases/./a.out < $f > temp;
    echo $f;
    echo $f >> log.txt;
    # head -1 temp >> log.txt
    cat temp | grep "impossible" >> log.txt
    # diff -w temp ${f%.*}.ans >> log.txt 
done 

rm temp