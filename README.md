# MiniLaska

> Progetto universitario di "Introduzione alla Programmazione"
> 
> Università Ca' Foscari Venezia – A.A. 2020/2021
> 
> Professori: Claudio Lucchese, Alvise Spanò

## 📌 Descrizione

**miniLaska** è una variante semplificata del gioco da tavolo **Laska** ([www.lasca.org](http://www.lasca.org)), sviluppata in linguaggio **ANSI C**.

Differenze rispetto al gioco originale:
- Ogni mossa può includere **una sola cattura**.
- Le **torri** possono avere al massimo **3 pedine**; se questo limite viene superato, la pedina più in basso viene rimossa dalla scacchiera.

Il progetto è stato realizzato nell’ambito del corso "Introduzione alla Programmazione" e ha come obiettivo la corretta implementazione delle regole del gioco e una struttura del codice chiara, modulare e documentata.

## 🎮 Modalità di Gioco

- 👥 **Due giocatori**: modalità base con inserimento delle mosse da tastiera.
- 🤖 **Giocatore vs Computer** *(opzionale)*: è possibile implementare una strategia automatica per il computer, semplice o ricorsiva.

## 📁 Struttura del Progetto
```
miniLaska/
├── src/ # Codice sorgente
│ ├── main.c # Entry point
│ ├── board.c/.h # Gestione scacchiera e regole
│ ├── player.c/.h # Logica dei turni
│ └── ai.c/.h # (Opzionale) Intelligenza artificiale
├── include/ # File header comuni
├── docs/ # Documentazione Doxygen
├── report/ # Relazione scritta
├── Makefile # Compilazione automatica
└── README.md # Questo file
```
## 🧪 Compilazione ed Esecuzione

Per compilare il progetto, posizionarsi nella directory principale e digitare:

```bash
make
```

Per eseguire il programma:

```bash
./miniLaska
```

## 📚 Documentazione

La documentazione del codice è generata con Doxygen. Per rigenerarla:

```bash
doxygen Doxyfile
```
Contiene:

- Descrizione di tutte le funzioni e moduli
- Diagrammi delle dipendenze tra file
- Commenti strutturati e leggibili

## ✅ Funzionalità Implementate

| Funzionalità                            | Stato           |
| --------------------------------------- | --------------- |
| Modalità 2 giocatori                    | ✅ Completata    |
| Implementazione delle regole base       | ✅ Completata    |
| Rimozione pedina in eccesso nella torre | ✅ Completata    |
| Modalità Giocatore vs Computer          | 🔲 Facoltativa  |
| Strategia ricorsiva per AI              | 🔲 Facoltativa  |
| Interfaccia grafica                     | 🔲 Non prevista |

## 📦 Contenuti della Consegna

La cartella compressa da consegnare include:

✅ Codice sorgente (ANSI C)
✅ Relazione PDF (max 3 pagine)
✅ Documentazione Doxygen
✅ Makefile

## 📅 Scadenze

Consegna finale: almeno una settimana prima dell’appello scelto per la discussione.
Presentazione preliminare (facoltativa): 3–5 slide da mostrare durante la lezione del 9/12/2020.

## 🎓 Valutazione

La valutazione si basa su:

- 📖 **Qualità della relazione** (chiarezza, completezza)
- 🧩 **Struttura e documentazione del codice**
- ⚙️ **Funzionalità richieste e/o aggiuntive implementate**
- 🗣️ **Discussione orale** individuale e di gruppo (sul progetto e sul linguaggio C)

> ⚠️ **Ogni membro del gruppo deve conoscere il codice e sostenere l’interrogazione singolarmente.**

---

## 🚀 Estensioni Possibili

- Interfaccia grafica (es. con `ncurses` o `SDL`)
- Modalità **Giocatore vs Giocatore remoto**
- Strategia AI avanzata (es. algoritmo **Minimax**)
- Implementazione del gioco **Laska completo**


