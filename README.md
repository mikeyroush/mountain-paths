# mountain-paths

This project takes altitude data from dat files to form topographical maps and then uses a greedy algorithm to find the shortest path from one side to the other. It can also find the shortest path to each edge of the map from a given coordinate. The program colors the paths as follows:
- ![#FC193F](https://placehold.it/15/FC193F/000000?text=+) `#FC193F` - greedy paths from west to east edge
- ![#1FFD0D](https://placehold.it/15/1FFD0D/000000?text=+) `#1FFD0D` - shortest path
- ![#13FEFD](https://placehold.it/15/13FEFD/000000?text=+) `#13FEFD` - greedy paths to each edge from a given coordinate

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for testing purposes.

### Prerequisites

A working command line

### Installing and Running

Download the zip then link the files in the command line via the makefile and run the executable

Navigate to the correct directory and utilize the makefile

```console
foo@bar:~$ cd /path/to/directory/here
foo@bar:~$ make all
```

This will have created a few .o files and an executable. To run it, do as follows...

```console
foo@bar:~$ ./Main
```

Demo

```console
Enter number of rows: 480
Enter number of columns: 480
Enter input filename: map-input-480-480.dat
min value: 1326
max value: 4334
greediest path: 11971
enter space separated coordinates i.e. (45 56): 200 200
```

Example output
![map with greedy paths](map-input-480-480.dat.ppm)

## Authors

* **Michael Roush** - *Project completion*

## License

Copyright © 2017 Michael Roush. All rights reserved.

