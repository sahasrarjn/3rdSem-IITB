for (( i=1; i<=100; i++ ));
do
    # echo $i
    
    # g++ generator.cpp
    # ./a.out > input
    
    # python temp.py

    # g++ generator2.cpp
    # ./a.out 100000 1000 > input



    g++ -O2 $1
    time ./a.out < input > output

    g++ -o check check.cpp
    ./check input output
done