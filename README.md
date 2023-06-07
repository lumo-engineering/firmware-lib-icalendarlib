# iCalendarLib

A simple library written in C++ used for parsing iCalendar (.ics) files.

It uses only standard C/C++ libraries so it should compile on any operating
system. It has its own Date class, no OS-specific way of storing dates is used.

See main.cpp for example use.

## Build

```
mkdir build
cd build
cmake ..
make
```

## Example

```
build/example
```

Note: Please edit the timestamps in `example.c` and `calendar.ics` yourself.

## License

iCalendarLib is provided under the MIT license.
