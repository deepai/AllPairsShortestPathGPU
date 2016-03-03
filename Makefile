OBJS =  Test.o \
	host/csr_graph.o

all: apsp

apsp: $(OBJS)
	@g++ -o $@ $(OBJS)

host/%.o: host/%.cpp
	@echo [c++] $@
	@g++ -c $< -o $@

clean:
	rm -rf apsp host/*.o 