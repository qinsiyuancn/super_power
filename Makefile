CC := g++
super_power:testsuperpower.o super_power.o fast_power.o
	$(CC) -o $@ $^

fast_power:testfastpower.o fast_power.o
	$(CC) -o $@ $^

testsuperpower.o:super_power.h fast_power.h
testfastpower.o:fast_power.h
super_power.o:fast_power.h
fast_power.o:fast_power.h

.PHONY : clean
clean:
	rm fast_power super_power *.o -f
