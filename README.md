# ⚙️ so-fib · Sistemes Operatius

> **Laboratoris, concurrència, gestió de processos, memòria i crides a sistema POSIX de l'assignatura Sistemes Operatius (SO) del Grau en Enginyeria Informàtica a la Facultat d'Informàtica de Barcelona (UPC · FIB).**

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)](https://en.wikipedia.org/wiki/C_(programming_language))
[![OS](https://img.shields.io/badge/OS-Linux_POSIX-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.kernel.org)
[![University](https://img.shields.io/badge/UPC-FIB-0070BA?style=for-the-badge)](https://www.fib.upc.edu)

---

## 📂 Estructura del Repositori i Sessions de Laboratori

El repositori inclou les **8 sessions de laboratori pràctiques completes**, cadascuna amb els seus codis font en C, Makefiles de compilació, fitxers de proves i respostes d'entrega:

| Sessió | Títol i Àmbit d'Estudi | Conceptes i Crides Clau |
| :---: | :--- | :--- |
| [**S1**](SESSIONS/S1/) | **Entorn Unix i Shell** | Comandes Linux (`ls`, `cat`, `grep`, `chmod`), permisos octals, redireccions (`<`, `>`). |
| [**S2**](SESSIONS/S2/) | **Programació en C, Punters i Makefiles** | Aritmètica de punters, pas de paràmetres (`argc`, `argv`), modularització (`.h`, `.c`) i automatització amb `make`. |
| [**S3**](SESSIONS/S3/) | **Gestió de Processos** | Jerarquia de processos amb `fork()`, canvi d'imatge amb família `exec()` (`execlp`, `execv`) i eina `myPS`. |
| [**S4**](SESSIONS/S4/) | **Senyals POSIX i Esdeveniments** | Captura i màscares de senyals amb `sigaction`, alarmes periòdiques (`alarm`, `SIGALRM`) i sincronització amb `waitpid()`. |
| [**S5**](SESSIONS/S5/) | **Gestió de Memòria i Mapa d'Adreces** | Anàlisi de regions (Text, Data, BSS, Heap, Stack), assignació dinàmica (`malloc`, `free`), projecció `mmap()` i `/proc/[pid]/maps`. |
| [**S6**](SESSIONS/S6/) | **Comunicació entre Processos (Pipes)** | Pipes amb nom / FIFOs (`mknod`), pipes anònimes (`pipe()`), redirecció de descriptors (`dup2()`) i comunicació lector/escriptor. |
| [**S7**](SESSIONS/S7/) | **Entrada/Sortida a Baix Nivell** | Operacions sobre descriptors (`open`, `read`, `write`, `close`), posicionament (`lseek`), flag `O_APPEND` i projecció de fitxers (`mmap`). |
| [**S8**](SESSIONS/S8/) | **Concurrència Avançada (Threads i Sockets)** | Threads POSIX (`pthread_create`, `pthread_join`), exclusió mútua (`pthread_mutex`), cost processos vs fils i servidors concurrents amb Sockets. |

---

## 🛠️ Compilació i Execució

Totes les sessions compten amb els seus respectius `Makefile` per compilar de forma automatitzada:

```bash
cd SESSIONS/S3
make
./myPS
```

Per netejar els executables generats:
```bash
make clean
```
