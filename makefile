CC=g++ -pthread -lc

all:
	make capteur
	make buffer

# CAPTEUR
capteur:  Capteur_Buffer/capteur.h Capteur_Buffer/capteur.cpp Capteur_Buffer/testcapteur.cpp
	$(CC) Capteur_Buffer/capteur.cpp  Capteur_Buffer/testcapteur.cpp -o testC

buffer: Capteur_Buffer/Circular_Buffer.h Capteur_Buffer/Circular_Buffer.cpp Capteur_Buffer/testBuffer.cpp
	$(CC) Capteur_Buffer/Circular_Buffer.cpp  Capteur_Buffer/testBuffer.cpp -o testB
