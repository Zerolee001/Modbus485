CC=arm-linux-gnueabihf-gcc-4.9.1

CFLAGS=-I./library/json/inc\
       -I./library/libmodbus/inc\

TARGET=./library/json/libjson-c.so.2\
       ./library/libmodbus/libmodbus.so.5

OBJ = Rescource.o\
      DeviceScan.o\
      Ch0process.o\
      Ch1process.o\
      Ch2process.o\
      Ch3process.o\
      Ch4process.o\
      Ch5process.o\
      adModbus_def.o\
      adMudbus.o\
      main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(TARGET) $(CFLAGS) -lpthread

clean:
	-rm -f main *.o
