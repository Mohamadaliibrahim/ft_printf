# go to project
pushd "/home/fbicandy/42Beirut/core/push_swap/" || exit


clear

# Compile
make fclean && make all && make clean
clear

./push_swap "42 8 1 5 18 6"