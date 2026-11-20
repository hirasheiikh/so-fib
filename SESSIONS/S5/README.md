# 🧠 Sessió 5: Gestió de Memòria i Mapa d'Adreces

Anàlisi del mapa de memòria virtual d'un procés en Linux:

- **Regions de memòria:** Text (codi), Data/BSS (variables globals/estàtiques), Heap (dinàmica) i Stack (pila d'execució).
- **Assignació estàtica vs dinàmica:** Ús de `malloc()` i `free()`, fuites de memòria (`mem1.c`, `mem1_v2.c`, `mem1_v3.c`).
- **Memòria compartida amb `mmap`:** Projecció anònima compartida (`MAP_SHARED` vs `MAP_PRIVATE`) entre pare i fill (`mem2.c`, `mem2_v2.c`).
- **Inspecció del sistema de fitxers `/proc`:** Lectura de `/proc/[pid]/maps` per observar les zones de memòria en temps real.
- **Respostes:** `entrega.txt` cobreix les preguntes 46 a 55.
