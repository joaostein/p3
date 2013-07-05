for i in *.c; do
    base=`basename $i .c`
    echo "compilando $base"

    gcc -c $base.c -o $base.o
done

echo "linkando"
gcc *.o -o executavel

rm -rf *.o