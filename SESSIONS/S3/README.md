# 🔄 Sessió 3: Gestió de Processos (`fork`, `exec` i `wait`)

Estudi en profunditat del cicle de vida dels processos en sistemes operatius POSIX:

- **Creació de Processos:** Crida al sistema `fork()`, duplicació de l'espai d'adreces (Copy-On-Write) i identificadors PID/PPID (`ejemplo_fork1.c` a `ejemplo_fork7.c`).
- **Canvi d'Imatge de Procés:** Família de crides `exec()` (`execlp`, `execv`) i superposició de memòria (`ejemplo_exec1.c`, `ejemplo_exec2.c`).
- **Utilitat `myPS`:** Desenvolupament incremental d'un visor de processos propi (`myPS_v0.c`, `myPS.c`, `myPS2.c`, `myPS3.c`).
- **Anàlisi d'arguments i execució:** `parsExec.c` per a la descomposició i execució de línies de comanda.
- **Respostes:** `entrega.txt` cobreix les preguntes 18 a 38.
