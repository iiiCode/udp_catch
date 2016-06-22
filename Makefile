all:
	gcc udp_catch.c -o udp_catch -g -Wall
clean:
	rm -rf udp_catch
