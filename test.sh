if [ -n $CC ]
then
  if [ $CC=gcc ]
  then
    rm -f test_gcc
    gcc -std=c99 -pedantic -Werror -Wall -Wextra -o test_gcc test.c mathc.c -lm
    chmod +x test_gcc
    ./test_gcc
  elif [ $CC=clang ]
  then
    rm -f test_clang
    clang -std=c99 -pedantic -Werror -Wall -Wextra -o test_clang test.c mathc.c -lm
    chmod +x test_clang
    ./test_clang
  else
    echo -e "Failed to build test: compiler (gcc or clang) not found."
    exit
  fi
else
  echo -e "Failed to build test: CC is not defined."
fi
