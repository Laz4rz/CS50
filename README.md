# CS50

### Additional requirements
Requires the installation of the cs50 library for C.

1. Install the libcs50:
```
$ curl -s https://packagecloud.io/install/repositories/cs50/repo/script.deb.sh | sudo bash
$ sudo apt install libcs50
```

2. Update the .bashrc file, by adding the following lines anywhere:
```
export CC="clang"
export CFLAGS="-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow"
export LDLIBS="-lcrypt -lcs50 -lm"
```

After that it is good to execute .bashrc again with `source .bashrc`.

3. Install clang:
```
$  sudo apt-get install clang 
```

### Running files

Each .c file can be built with `make filename`, notice that you do not want to write .c at the end. If you already have the binary, just run `./filename`.

