# Quiz

Realizzare un quiz da linea di comando e mantenerlo nel tempo, aggiornandolo e riarchitetturandolo secondo le nozioni apprese durante le lezioni.

## Specifiche lato utente

### Strictly necessary

- minimo 5 domande
- domande variabili di volta in volta
- feedback sulle domande durante il quiz o alla fine
- punteggio finale

### nice to have

- domande di diverso tipo nello stesso quiz (vero-falso, risposta multipla, risposta aperta, etc)
- salvataggio di quiz su db o su file. modalità edit del programma che dia la possibilità di aprire e modificare un quiz o di eseguirlo

### architettura e scalabilità

- possibilità di aggiungere facilmente e in maniera non invasiva nuovi tipi di domande
- possibilità di aggiungere facilmente e in maniera non invasiva nuove domande

### To-Do List

Scalability

- [] In function ParseQuestion better handle of the question type
- [] Handle the static_cast in _Quiz::CreateQuestionList()_ (put it into a different function)

Edit mode

- [] Add a question
- [] Delete a question