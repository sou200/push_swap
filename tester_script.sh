for i in {1..500}
do
  ARG=$(seq 0 $i | sort -R | tr "\n" " ");
  ./push_swap $ARG | ./checker_Mac $ARG
done

