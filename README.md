# TotalView ITCH 5.0 message parsing library

Small library to parse blobs of itch transactions into a structure.
Most of this code was generated, the generation code and generated content can
be found in `gen`.

For validation purposes we can read the binary files provided by the nasdaq exchange, 
these can be downloaded at https://emi.nasdaq.com/ITCH/Nasdaq%20ITCH/ 

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

## Usage

The `test` program takes in 2 command line argumets :

`-f` path to the location of the marketdata itch binary file provided by nasdaq for testing purposes.

`-n` number of itch messages to decode from the binary file

Command :
```
./test -n <number_msg> -f <file_path>
```

## Configuration 

Behavior can be configure using the following macro's :

- `LINE_CNT` : default number of lines to be analysed if no `-n` argument is provided, default `4000`
