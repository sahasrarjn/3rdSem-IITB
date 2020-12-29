#! /bin/bash

for i in {1..100}
do
	echo "Running on case $i"
	#valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out  < "10-100000/${i}" > "10-100000/o${i}"
	./a.out  < "20-2000/${i}" > "20-2000/o${i}"
	diff "20-2000/o${i}" "20-2000/out${i}"
done
