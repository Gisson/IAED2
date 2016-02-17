
CFlags=-o
outputName=Project
destination=./

all: aux.c funcoes.c funcoes.h proj.c
	gcc aux.c funcoes.c proj.c $(CFlags) $(outputName) 

run: $(outputName)
	$(destination)$(outputName)

zip: 
	zip $(outputName) aux.c funcoes.c funcoes.h proj.c

clean: $(outputName)
	rm $(outputName)


