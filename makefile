CC=g++ -pthread -lc

all:
	make capteur
	make buffer
	make watchdog
	make smemory
	make service
	make systeme
	make oracle
	make toto

# CAPTEUR
capteur:  Capteur_Buffer/capteur.cpp Capteur_Buffer/testcapteur.cpp
	$(CC) Capteur_Buffer/capteur.cpp  Capteur_Buffer/testcapteur.cpp -o TestsUnitaires/testC

buffer: Capteur_Buffer/circular_buffer.cpp Capteur_Buffer/testBuffer.cpp
	$(CC) Capteur_Buffer/circular_buffer.cpp  Capteur_Buffer/testBuffer.cpp -o TestsUnitaires/testB

watchdog: Watchdog/watchdog.cpp Watchdog/test_watchdog.cpp
	$(CC) Watchdog/watchdog.cpp Watchdog/test_watchdog.cpp -o TestsUnitaires/testW

smemory: SMemory/SMemory.cpp Capteur_Buffer/circular_buffer.cpp SMemory/test_SMemory.cpp
	$(CC) SMemory/SMemory.cpp SMemory/test_SMemory.cpp Capteur_Buffer/circular_buffer.cpp -o TestsUnitaires/testSM

service: Service/service.cpp Service/testservice.cpp Watchdog/watchdog.cpp SMemory/SMemory.cpp Capteur_Buffer/capteur.cpp Capteur_Buffer/circular_buffer.cpp
	$(CC) Service/service.cpp Service/testservice.cpp Watchdog/watchdog.cpp SMemory/SMemory.cpp Capteur_Buffer/capteur.cpp Capteur_Buffer/circular_buffer.cpp -o TestsUnitaires/testS

systeme: Systeme/systeme.cpp  Service/service.cpp  Watchdog/watchdog.cpp SMemory/SMemory.cpp Capteur_Buffer/capteur.cpp Capteur_Buffer/circular_buffer.cpp
	$(CC) Systeme/systeme.cpp Service/service.cpp  Watchdog/watchdog.cpp SMemory/SMemory.cpp Capteur_Buffer/capteur.cpp Capteur_Buffer/circular_buffer.cpp -o systeme

oracle: GrandOracle/oracle.cpp
	$(CC) GrandOracle/oracle.cpp -o oracle

toto: toto.cpp
	$(CC) toto.cpp -o toto

