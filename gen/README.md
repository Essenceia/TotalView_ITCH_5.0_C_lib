# Generator

As the C code for the itch decoder is simple but repetitive.
We generate it using and xml file outlining the itch message format and a small script 
`itch_msg_to_c.py`.

Usage :
```
python itch_msg_to_rtl.py nasdaq_totalview_itch.xml
```

## ITCH message xml file

Originally found in https://github.com/doctorbigtime/itch, all credits belong to `doctorbigtime`.

Was modified to remove all none itch messages under `Structs`, diffs can be viewed in `xml_diff.patch`.
