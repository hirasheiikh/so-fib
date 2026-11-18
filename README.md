# ⚙️ so-fib · Sistemes Operatius

> **Laboratoris, concurrència, gestió de processos i crides a sistema POSIX de l'assignatura Sistemes Operatius (SO) del Grau en Enginyeria Informàtica a la Facultat d'Informàtica de Barcelona (UPC · FIB).**

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)](https://en.wikipedia.org/wiki/C_(programming_language))
[![OS](https://img.shields.io/badge/OS-Linux_POSIX-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.kernel.org)
[![University](https://img.shields.io/badge/UPC-FIB-0070BA?style=for-the-badge)](https://www.fib.upc.edu)

---

## 📚 Temari i Conceptes Clau

- **Gestió de Processos:** Jerarquia de processos amb crides `fork()`, `exit()` i sincronització amb `wait()` / `waitpid()`.
- **Canvi d'Imatge de Procés:** Execució de programes amb la família de funcions `exec()` (`execlp`, `execv`).
- **Senyals POSIX:** Captura, bloqueig i gestió asíncrona de senyals (`sigaction`, `sigprocmask`, `SIGINT`, `SIGALRM`).
- **Canals de Comunicació (Pipes):** Comunicació unidireccional i bidireccional entre processos amb `pipe()` i redirecció de descriptors de fitxer (`dup2()`).
- **Entrada/Sortida a Baix Nivell:** Lectura i escriptura directa al sistema de fitxers (`open`, `read`, `write`, `close`).

---

## 🛠️ Compilació

```bash
gcc -Wall -Wextra programa.c -o programa
./programa
```
