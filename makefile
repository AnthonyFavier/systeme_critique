CC=g++ -pthread -lc

all:
	make capteur
	make buffer
	make watchdog

# CAPTEUR
capteur:  Capteur_Buffer/capteur.h Capteur_Buffer/capteur.cpp Capteur_Buffer/testcapteur.cpp
	$(CC) Capteur_Buffer/capteur.cpp  Capteur_Buffer/testcapteur.cpp -o testC

buffer: Capteur_Buffer/Circular_Buffer.h Capteur_Buffer/Circular_Buffer.cpp Capteur_Buffer/testBuffer.cpp
	$(CC) Capteur_Buffer/Circular_Buffer.cpp  Capteur_Buffer/testBuffer.cpp -o testB

watchdog: Watchdog/watchdog.h Watchdog/watchdog.cpp Watchdog/test_watchdog.cpp
	$(CC) Watchdog/watchdog.h Watchdog/watchdog.cpp Watchdog/test_watchdog.cpp -o testW

service: service.h service.cpp
	$(CC) service.h service.cpp
