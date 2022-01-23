SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99 -I$(INCLUDEDIR)
LDFLAGS=-lTableDeCodage -lArbreDeHuffman -lOctet -lFileDePriorite -lStatistiques -lCodeBinaire -lErreur -lm -lcurses
EXEC=huffman
LIBRARY=$(LIBDIR)/libTableDeCodage.a $(LIBDIR)/libArbreDeHuffman.a $(LIBDIR)/libOctet.a $(LIBDIR)/libFileDePriorite.a $(LIBDIR)/libStatistiques.a $(LIBDIR)/libCodeBinaire.a $(LIBDIR)/libErreur.a
HUFFMAN=$(SRCDIR)/calculerStats.o $(SRCDIR)/fichier.o $(SRCDIR)/FichierOriginal.o $(SRCDIR)/genererArbre.o $(SRCDIR)/genererFichier.o $(SRCDIR)/genererTable.o $(SRCDIR)/huffman.o 

all :  $(BINDIR)/$(EXEC)

doc : .PHONY
	doxygen Doxyfile
	
proper : clean all

tests : $(TESTDIR)/tests

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBRARY) $(HUFFMAN)
	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIBDIR)

$(TESTDIR)/tests : $(SRCDIR)/tests.o $(LIBRARY)
	$(CC) -o $@ $^ $(LDFLAGS) -L $(LIBDIR) -lcunit

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(LIBDIR)/libTableDeCodage.a : $(SRCDIR)/tableDeCodage.o
	$(AR) -r $@ $^

$(LIBDIR)/libArbreDeHuffman.a : $(SRCDIR)/ArbreDeHuffman.o
	$(AR) -r $@ $^

$(LIBDIR)/libOctet.a : $(SRCDIR)/octet.o
	$(AR) -r $@ $^

$(LIBDIR)/libFileDePriorite.a : $(SRCDIR)/fileDePriorite.o
	$(AR) -r $@ $^

$(LIBDIR)/libStatistiques.a : $(SRCDIR)/Statistiques.o
	$(AR) -r $@ $^

$(LIBDIR)/libCodeBinaire.a : $(SRCDIR)/CodeBinaire.o
	$(AR) -r $@ $^

$(LIBDIR)/libErreur.a : $(SRCDIR)/erreur.o
	$(AR) -r $@ $^
	
clean clear :
	rm -rf $(BINDIR)/huffman
	touch $(BINDIR)/.gitkeep
	
	rm -rf $(LIBDIR)/*
	touch $(LIBDIR)/.gitkeep
	
	rm -rf $(SRCDIR)/*.o
	
	rm -rf $(TESTDIR)/*
	touch $(TESTDIR)/.gitkeep

cleanO :
	rm -rf $(SRCDIR)/*.o
	rm -rf $(LIBDIR)/*.a

.PHONY :
