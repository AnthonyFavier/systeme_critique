CC=g++ -pthread -lc

all:
	make capteur
	make buffer
	make watchdog
	make smemory
	make service

# CAPTEUR
capteur:  Capteur_Buffer/capteur.h Capteur_Buffer/capteur.cpp Capteur_Buffer/testcapteur.cpp
	$(CC) Capteur_Buffer/capteur.cpp  Capteur_Buffer/testcapteur.cpp -o TestsUnitaires/testC

buffer: Capteur_Buffer/circular_buffer.h Capteur_Buffer/circular_buffer.cpp Capteur_Buffer/testBuffer.cpp
	$(CC) Capteur_Buffer/circular_buffer.cpp  Capteur_Buffer/testBuffer.cpp -o TestsUnitaires/testB

watchdog: Watchdog/watchdog.h Watchdog/watchdog.cpp Watchdog/test_watchdog.cpp
	$(CC) Watchdog/watchdog.cpp Watchdog/test_watchdog.cpp -o TestsUnitaires/testW

smemory: SMemory/SMemory.h SMemory/SMemory.cpp Capteur_Buffer/circular_buffer.cpp Capteur_Buffer/circular_buffer.h SMemory/test_SMemory.cpp
	$(CC) SMemory/SMemory.cpp SMemory/test_SMemory.cpp Capteur_Buffer/circular_buffer.cpp -o TestsUnitaires/testSM

service: service.h service.cpp testservice.cpp
	$(CC) service.cpp testservice.cpp -o TestsUnitaires/testS
