clear
g++ -w -O2 190050102_9.cpp
# g++ -O2 -w copy.cpp
rm log.txt
touch log.txt

echo "done"

for f in *.in;
do
    ./a.out < $f > temp;
    echo $f;
    echo $f >> log.txt;
    # head -1 temp >> log.txt
    cat temp | tail -1 >> log.txt
    diff -w temp ${f%.*}.ans | wc >> log.txt 
done

rm temp