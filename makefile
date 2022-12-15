.SILENT:
	
CLASSES=Classes/
OBJS=$(CLASSES)Personne.o $(CLASSES)Intervenant.o $(CLASSES)Client.o $(CLASSES)Employe.o $(CLASSES)Modele.o $(CLASSES)Voiture.o $(CLASSES)Option.o $(CLASSES)Exception.o $(CLASSES)OptionException.o $(CLASSES)PasswordException.o
CO=g++ -I $(CLASSES) -D DEBUG
PROGRAMS=Test5


Test5:	Test5.cpp Personne.o Intervenant.o Client.o Employe.o Modele.o Voiture.o Option.o Exception.o OptionException.o PasswordException.o
	$(CO) Test5.cpp $(OBJS) -o Test5
	echo "Creation de Test5"

Personne.o:	$(CLASSES)Personne.h $(CLASSES)Personne.cpp
	$(CO) $(CLASSES)Personne.cpp -c -o $(CLASSES)Personne.o
	echo "Creation de Personne.o"

Intervenant.o:	$(CLASSES)Intervenant.h $(CLASSES)Intervenant.cpp
	$(CO) $(CLASSES)Intervenant.cpp -c -o $(CLASSES)Intervenant.o
	echo "Creation de Intervenant.o"

Client.o:	$(CLASSES)Client.h $(CLASSES)Client.cpp
	$(CO) $(CLASSES)Client.cpp -c -o $(CLASSES)Client.o
	echo "Creation de Client.o"

Employe.o:	$(CLASSES)Employe.h $(CLASSES)Employe.cpp
	$(CO) $(CLASSES)Employe.cpp -c -o $(CLASSES)Employe.o
	echo "Creation de Employe.o"

Modele.o:	$(CLASSES)Modele.h $(CLASSES)Modele.cpp
	$(CO) $(CLASSES)Modele.cpp -c -o $(CLASSES)Modele.o
	echo "Création de Modele.o"

Voiture.o:	$(CLASSES)Voiture.h $(CLASSES)Voiture.cpp
	$(CO) $(CLASSES)Voiture.cpp -c -o $(CLASSES)Voiture.o
	echo "Création de Voiture.o"

Option.o:	$(CLASSES)Option.h $(CLASSES)Option.cpp
	$(CO) $(CLASSES)Option.cpp -c -o $(CLASSES)Option.o
	echo "Création de Option.o"

Exception.o:	$(CLASSES)Exception.h $(CLASSES)Exception.cpp
	$(CO) $(CLASSES)Exception.cpp -c -o $(CLASSES)Exception.o
	echo "Creation de Exception.o"

OptionException.o:	$(CLASSES)OptionException.h $(CLASSES)OptionException.o
	$(CO) $(CLASSES)OptionException.cpp -c -o $(CLASSES)OptionException.o
	echo "Creation de OptionException.o"

PasswordException.o:	$(CLASSES)PasswordException.h $(CLASSES)PasswordException.o
	$(CO) $(CLASSES)PasswordException.cpp -c -o $(CLASSES)PasswordException.o
	echo "Creation de PasswordException.o"

clean:	
	rm $(CLASSES)*.o

clobber:
	clean
	rm -f $(PROGRAMS)
