# 🔀 Sessió 6: Comunicació entre Processos (Pipes i Redirecció)

Mecanismes de comunicació entre processos (IPC) en Unix:

- **Pipes amb nom (FIFOs):** Creació de canonades amb nom al sistema de fitxers (`mknod` / `mkfifo`) per comunicar processos independents en diferents terminals.
- **Pipes anònimes (`pipe()`):** Canals unidireccionals de comunicació entre processos emparentats (`sin_nombre.c`).
- **Redirecció de descriptors (`dup2()`):** Associació dels canals de lectura/escriptura de la pipe a l'entrada estàndard (`0`) o sortida estàndard (`1`).
- **Arquitectura Lector/Escriptor:** Programes `lector.c`, `escritor.c` i variants `escritor_v2.c`.
- **Introducció a Sockets:** `escritor_socket.c` i `lector_socket.c`.

