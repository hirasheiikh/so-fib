# 🧵 Sessió 8: Concurrència Avançada (Threads POSIX i Sockets)

Programació multithread, sincronització de fils i comunicació client/servidor:

- **Cost de creació:** Comparativa de rendiment entre Processos (`fork`) i Fils (`pthread_create`) a `costeProcesos.c` i `costeThreads.c`.
- **Sincronització i condicions de carrera:**
  - `suma_paralela.c`: Versió bàsica amb concurrència.
  - `suma_paralela_v2.c`: Exclusió mútua amb mutex global (`pthread_mutex_lock` / `unlock`).
  - `suma_paralela_v3.c`: Optimització amb variables locals i suma acumulada final.
- **Servidors Concurrents amb Sockets:**
  - `server.c`: Servidor seqüencial.
  - `server_thread.c`: Servidor concurrent multithread on cada petició és atesa per un nou fil.
  - `cliente.c`: Client de prova per connexions concurrents.
  - `socketMng.c` / `socketMng.h`: Mòdul de gestió de sockets d'interfície neta.
- **Respostes:** `entrega.txt` cobreix les preguntes 70 a 72.
