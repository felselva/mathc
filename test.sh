if [ -n $CC ]
then
  if [ $CC=gcc ]
  then
    gcc -std=c99 -Wall -Wextra -o test_gcc test.c mathc.c -I. -lm && chmod +x test_gcc
    ./test_gcc
  elif [ $CC=clang ]
  then
    clang test.c -include mathc.h -c mathc.c && clang -o test_clang test.o mathc.o -lm && chmod +x test_clang
    ./test_clang
  else
    echo -e "Failed to build test: compiler (gcc or clang) not found."
    exit
  fi
else
  echo -e "Failed to build test: CC is not defined."
fi
