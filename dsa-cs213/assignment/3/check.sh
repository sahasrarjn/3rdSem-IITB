# g++ -w -o my.out -O2 main.cpp;
# g++ -w -o gen.out test6.cpp;

for i in {0..30};
do
    ./gen.out 20 200 > temp.in;
    time ./my.out < temp.in > temp.out
    # ./c.out < temp.in > temp2.out
    # diff temp.out temp2.out | wc
done
