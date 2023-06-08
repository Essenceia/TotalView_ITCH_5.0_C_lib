# TotalView ITCH 5.0 message parsing library

Small library to parse blobs of itch transactions into a structure.
Most of this code was generated, the generation code and generated content can
be found in `gen`.

## Usage

To build the test case :

```
make test

```

To clean :
```
make clean
```

## Configuration 

- `ITCH_FILE` : macro pointing to location of the marketdata itch binary file provided by nasdaq for testing purposes.
        Download link : https://emi.nasdaq.com/ITCH/Nasdaq%20ITCH/

- `LINE_CNT` : Number of lines to be analysed
