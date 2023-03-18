for i in {1..100}
do
  ARG=$(seq 0 $i | sort -R | tr "\n" " ");
  ./a.out $ARG | ./checker_Mac $ARG
done

