
MAKE = make

TARGETS = seq omp mpi


all: $(TARGETS)

seq:
	$(MAKE) -C $@

omp:
	$(MAKE) -C $@

mpi:
	$(MAKE) -C $@

clean:
	$(MAKE) -C seq clean
	$(MAKE) -C omp clean
	$(MAKE) -C mpi clean

.PHONY: all clean $(TARGETS)
