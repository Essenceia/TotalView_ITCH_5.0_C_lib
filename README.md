# TotalView ITCH 5.0 message parsing library

Small library to parse blobs of itch transactions into a structure.
Most of this code was generated, the generation code and generated content can
be found in `gen`.
Data endianness of the structures variables is the same as in the original packet.

For validation purposes we can read the binary files provided by the nasdaq exchange, 
these can be downloaded at https://emi.nasdaq.com/ITCH/Nasdaq%20ITCH/ 

## Build library 

To build the static library `libitch.a` : 

```
make lib
```

(optional) Enable debug :
```
make lib debug=1
```

(optional) Enable only the printing of the file pos on each read and none of
    the other debug informaiton.
```
make lib fpos=1
```

## Build test

To build the test case :

```
make test
```

(optional) Enable debug :
```
make test debug=1
```

To clean :
```
make clean
```

### Run test

The `test` program takes in 2 command line arguments :

`-f` path to the location of the market data itch binary file provided by nasdaq for testing purposes.

`-n` number of itch messages to decode from the binary file

Command :
```
./test -n <number_msg> -f <file_path>
```

### Configuration 

Test behavior can be configure using the following macro's :

- `LINE_CNT` : default number of lines to be analysed if no `-n` argument is provided, default `4000`


# License

This code is licensed under CC BY-NC 4.0, to obtain a commercial license
reach out to the author .
