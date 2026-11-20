# 🔔 Sessió 4: Senyals POSIX i Gestió d'Esdeveniments

Manipulació de senyals asíncrons i sincronització de processos fills:

- **Instal·lació de rutines de tractament:** Ús de `sigaction` per capturar senyals (`SIGINT`, `SIGALRM`, `SIGCHLD`).
- **Temporització amb alarmes:** Crida `alarm()` per llançar alertes temporals periòdiques (`ejemplo_alarm1.c` a `ejemplo_alarm4.c`).
- **Sincronització amb fills:** Ús de `waitpid()` amb opcions bloquejants i no bloquejants (`WNOHANG`) (`ejemplo_waitpid.c`, `ejemplo_waitpid2.c`).
- **Senyals pendents i pèrdua de senyals:** Demostració del caràcter no encoaat dels senyals estàndard a `signalPerdido.c`.
- **Respostes:** `entrega.txt` cobreix les preguntes 39 a 45.
