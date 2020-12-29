g++ -O2 $1; 
./a.out < $2 > temp
time ./b.out < $2 > temp2
diff temp temp2 | wc