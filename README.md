Number Chains
=============

Number Chains is inspired by [this video](https://www.youtube.com/watch?v=LYKn0yUTIU4 "Four has Four Letters").

### Running

Run the executable passing one or two arguments.
The first argument is the maximum number to check to (in decimal format). 
The second argument is whether or not to include the 'and's in the count (1 or 0), i.e. 'One hundred **and** one'.

```sh
./numberChains <maximum number> [uses and]
```

### Building

This project uses CMake to build.

* Create a `build` and `bin` directory in the root directory.

* In the build directory run `cmake ..` then make.

