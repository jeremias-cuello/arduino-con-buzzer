const int PIN_BUZZER = 2;

// Notas musicales en frecuencia (Hz)
const int
  A = 440,
  B = 493,
  C = 261,
  D = 294,
  E = 329,
  F = 349,
  G = 391;

// Duraciones de las notas
const int
  QUARTER = 400, // Negra (???)
  HALF = 800,    // Blanca (???)
  WHOLE = 1600;  // Redonda (???)

struct Note{
  int
    frequency,
    duration;
};

// Melodia de "Estrellita donde estas?"
struct Melody { 
  const int cuantityNotes = 14;
  Note notes[14] = { // notes[cuantityNotes] syntaxis error :(
    { C, QUARTER },
    { C, QUARTER },
    { G, QUARTER },
    { G, QUARTER },
    { A, QUARTER },
    { A, QUARTER },
    { G, HALF },
    { F, QUARTER },
    { F, QUARTER },
    { E, QUARTER },
    { E, QUARTER },
    { D, QUARTER },
    { D, QUARTER },
    { C, HALF }
  };
};

const Melody song;

void executeNote(Note note) {
  /**
   * Entre notas se necesita un silencio proporcional a cada nota
   * No puede ser fijo, se ecucha mal.
  */

  tone(PIN_BUZZER, note.frequency, note.duration);
  // Silencio entre notas de un 10%
  delay(note.duration * 1.1);
}

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop() {

  Note note;

  for(int i = 0; i < song.cuantityNotes; i++){
    note = song.notes[i];
    executeNote(note);
  }

  // Pausa antes de reiniciar
  delay(500);
}
