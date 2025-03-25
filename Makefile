main : main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o Createur_Bestiole.o BestioleDecorator.o Camouflage.o Carapace.o Clonable.o Gregaire.o Kamikaze.o Nageoires.o Oreilles.o PersonnalitesMultiples.o Peureuse.o Prevoyante.o SensorDecorator.o Yeux.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o Createur_Bestiole.o BestioleDecorator.o Camouflage.o Carapace.o Clonable.o Gregaire.o Kamikaze.o Nageoires.o Oreilles.o PersonnalitesMultiples.o Peureuse.o Prevoyante.o SensorDecorator.o Yeux.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp Environment.h Clonable.h Comportement.h Kamikaze.h Prevoyante.h Peureuse.h Gregaire.h
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .
IBestiole.o : 
	g++ -Wall -std=c++11  -c Bestiole.cpp Bestiole.h -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .
#Comportements
Comportement.o : Comportement.h Milieu.h Bestiole.h 
	g++ -Wall -std=c++11 -c Comportement.h Milieu.h Bestiole.h
Kamikaze.o: Kamikaze.h Kamikaze.cpp Comportement.h Bestiole.h
	g++ -g -Wall -std=c++11 -c Kamikaze.cpp Kamikaze.h -I .
Peureuse.o: Peureuse.h Peureuse.cpp Comportement.h Milieu.h Bestiole.h
	g++ -g -Wall -std=c++11 -c Peureuse.cpp Peureuse.h -I .
Gregaire.o: Gregaire.h Gregaire.cpp Comportement.h Milieu.h Bestiole.h
	g++ -g -Wall -std=c++11 -c Gregaire.cpp Gregaire.h -I .
Prevoyante.o: Prevoyante.h Prevoyante.cpp Comportement.h Bestiole.h
	g++ -g -Wall -std=c++11 -c Prevoyante.cpp Prevoyante.h -I .
PersonnalitesMultiples.o: PersonnalitesMultiples.h PersonnalitesMultiples.cpp Comportement.h Bestiole.h
	g++ -g -Wall -std=c++11 -c PersonnalitesMultiples.cpp -I .

#decorator_sensor

BestioleDecorator.o: BestioleDecorator.h BestioleDecorator.h Bestiole.h Milieu.h
	g++ -g -Wall -std=c++11 -c BestioleDecorator.h -I .

Oreilles.o: Oreilles.h Oreilles.cpp BestioleDecorator.h AccessoryDecorator.h Bestiole.h Milieu.h
	g++ -g -Wall -std=c++11 -c Oreilles.cpp -I .
Yeux.o: Yeux.h Yeux.cpp BestioleDecorator.h AccessoryDecorator.h Bestiole.h Milieu.h
	g++ -g -Wall -std=c++11 -c Yeux.cpp -I .
SensorDecorator.o: SensorDecorator.h BestioleDecorator.h Bestiole.h Milieu.h
	g++ -g -Wall -std=c++11 -c SensorDecorator.h -I .

#accessory decorate

AccessoryDecorator.o: AccessoryDecorator.h BestioleDecorator.h Bestiole.h Milieu.h
	g++ -g -Wall -std=c++11 -c SensorDecorator.h -I .
Carapace.o: AccessoryDecorator.h BestioleDecorator.h Bestiole.h Milieu.h
	g++ -g -Wall -std=c++11 -c Carapace.h Carapace.cpp -I .
Camouflage.o: AccessoryDecorator.h BestioleDecorator.h Bestiole.h Milieu.h
	g++ -g -Wall -std=c++11 -c Camouflage.h Camouflage.cpp -I .
Nageoires.o: AccessoryDecorator.h BestioleDecorator.h Bestiole.h Milieu.h
	g++ -g -Wall -std=c++11 -c Nageoires.h Nageoires.cpp -I .

#Createur

Createur_Bestiole.o: Bestiole.h Createur.h Bestiole.h Comportement.h
	g++ -g -Wall -std=c++11 -c Createur_Bestiole.h Createur_Bestiole.cpp -I .

Createur_Bestiole.o: Bestiole.h Createur.h Bestiole.h Comportement.h
	g++ -g -Wall -std=c++11 -c Createur_Bestiole.h Createur_Bestiole.cpp -I .






clean:
	rm -rf *.o main

