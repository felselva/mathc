if [ -n $CC ]
then
  if [ $CC=gcc ]
  then
    rm -f test_mathc
    gcc -std=c99 -pedantic -Werror -Wall -Wextra -o test_mathc test.c mathc.c -lm
    chmod +x test_mathc
    ./test_mathc
  elif [ $CC=clang ]
  then
    rm -f test_mathc
    clang -std=c99 -pedantic -Werror -Wall -Wextra -o test_mathc test.c mathc.c -lm
    chmod +x test_mathc
    ./test_mathc
  else
    echo -e "Failed to build test: compiler (gcc or clang) not found."
    exit
  fi
else
  echo -e "Failed to build test: CC is not defined."
fi
