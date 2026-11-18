# ⚙️ so-fib · Sistemes Operatius

> **Laboratoris, concurrència, gestió de processos i crides a sistema POSIX de l'assignatura Sistemes Operatius (SO) del Grau en Enginyeria Informàtica a la Facultat d'Informàtica de Barcelona (UPC · FIB).**

[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)](https://en.wikipedia.org/wiki/C_(programming_language))
[![OS](https://img.shields.io/badge/OS-Linux_POSIX-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.kernel.org)
[![University](https://img.shields.io/badge/UPC-FIB-0070BA?style=for-the-badge)](https://www.fib.upc.edu)

> [!NOTE]
> **Estat del repositori & Migració en curs:**  
> El contingut complet d'aquesta assignatura es troba actualment en procés de migració des d'un altre disc dur. Aniré afegint a poc a poc més laboratoris, exercicis i apunts quan disposi de temps lliure.  
> 
> *Aquest repositori té una finalitat secundària com a demostració del meu coneixement base en fonaments de baix nivell i sistemes (el focus primordial del meu perfil professional i desenvolupament es troba en els meus projectes d'enginyeria de programari).*

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