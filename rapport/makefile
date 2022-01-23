####MAKEFILE POUR LE RAPPORT#####
TEX=pdflatex
PDF_DIR=PDF
TAD_DIR=TAD
CON_DIR=Conception
TEX_CONCEPTION=$(CON_DIR)/C_ArbreDeHuffman.tex $(CON_DIR)/C_CodeBinaire.tex $(CON_DIR)/C_FileDePriorite.tex $(CON_DIR)/C_Octet.tex $(CON_DIR)/C_Statistiques.tex $(CON_DIR)/C_TableDeCodage.tex
TAD_PDF=$(TAD_DIR)/TAD_ArbreDeHuffman.pdf $(TAD_DIR)/TAD_CodeBinaire.pdf $(TAD_DIR)/TAD_FileDePriorite.pdf $(TAD_DIR)/TAD_Octet.pdf $(TAD_DIR)/TAD_Statistiques.pdf $(TAD_DIR)/TAD_TableDeCodage.pdf
.PHONY : all proper tad clean cleanPDF cleanTEX conception #Pour ne pas confondre commandes & fichiers

#Faire le rapport & supprime les residus de compilation
all : rapport.tex cleanPDF $(PDF_DIR)/rapport.pdf proper cleanTEX

#2e passe sur le rapport, pour faire le sommaire
proper : rapport.tex metier.tex  $(TAD_PDF) $(TEX_CONCEPTION)
	$(TEX) -output-directory=$(PDF_DIR) rapport.tex

#Seulement les TAD & supprime les residus de compilation
tad : $(PDF_DIR)/tad.pdf cleanTEX

#Seulement la conception & supprime les residus de compilation
conception : $(PDF_DIR)/conception.pdf cleanTEX

#TAD: tex -> pdf
$(TAD_DIR)/%.pdf : $(TAD_DIR)/%.tex
	$(TEX) -output-directory=$(TAD_DIR) $<

#Conception: tex -> pdf
$(CON_DIR)/%.pdf : $(CON_DIR)/%.tex
	$(TEX) -output-directory=$(CON_DIR) $<

#Commande pour les TAD
$(PDF_DIR)/tad.pdf : tad.tex $(TAD_PDF)
	$(TEX) -output-directory=$(PDF_DIR) tad.tex

#Commande pour la conception
$(PDF_DIR)/conception.pdf : conception.tex $(TEX_CONCEPTION)
	$(TEX) -output-directory=$(PDF_DIR) conception.tex

#Commande pour le rapport
$(PDF_DIR)/rapport.pdf : rapport.tex metier.tex  $(TAD_PDF) $(TEX_CONCEPTION)
	$(TEX) -output-directory=$(PDF_DIR) rapport.tex

#Supprime les résidus latex
cleanTEX :
	find . -type f -name "*.log" -delete
	find . -type f -name "*.out" -delete
	find . -type f -name "*.aux" -delete
	find . -type f -name "*.toc" -delete

#Supprime les PDF
cleanPDF :
	rm -rf PDF/*.pdf
	rm -rf TAD/*.pdf
	rm -rf Conception/*.pdf

#Supprime tout
clean : cleanTEX cleanPDF
