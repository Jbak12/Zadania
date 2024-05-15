# Potoki nienazwane
## Zawartosc folderu i uruchomienie programu
Folder zawiera trzy pliki: zad4.c, dane_do skonsumowania.txt oraz plik makefile. Aby uruchomic program nalezy uzyc polecenia `make run4`. Utworzony program zad4.x przyjmuje trzy argumenty: nazwa pliku  z danymi do skonsumowania oraz nazwa pliku do ktorego nalezy zapisac skonsumowane dane.
## Dzialanie programu
Za pomocą funkcji fork tworzony jkest proces potomny.Odczyt i zapis danych odbywa sie odpowiednio w procesie macierzystym i potomnym. Daner zapisywane są tymczasowo do tablicy dwuelemendowej fds. dane zapisujemy w `fds[1]` a odczytujemy w `fds[0]`. Odczyt odbywa sie za pomoca funkcji `produce` a zapis za pomoca funkcji `consume`.
