ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker_Mac $ARG
OK

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
OK

ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
	6

./visualizer ./push_swap