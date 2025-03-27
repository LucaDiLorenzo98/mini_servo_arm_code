# 🤖 Braccio Robotico con Arduino

Questo codice controlla un piccolo **braccio robotico** con 4 servomotori, scritto in **Arduino C++**. Il braccio è in grado di **prendere un oggetto da una posizione (slide)** e **rilasciarlo in un'altra posizione**.

## ⚙️ Componenti usati

- 1 x Arduino (Uno o compatibile)
- 4 x Servo motori:
  - **servoBase**: ruota la base (360°)
  - **servoFirstArm**: primo braccio (movimento verticale)
  - **servoSecondArm**: secondo braccio (movimento verticale)
  - **servoGripper**: pinza per afferrare

## 🪛 Collegamenti pin

| Servo           | Pin Arduino |
|-----------------|-------------|
| Base            | 3           |
| Primo braccio   | 2           |
| Secondo braccio | 4           |
| Pinza (Gripper) | 5           |

## 🧠 Come funziona

1. All'accensione, i servo si portano in posizione iniziale.
2. La funzione `takeCubeOnSlide()` esegue questi passaggi:
   - Apre la pinza.
   - Abbassa il primo braccio per prendere un cubo.
   - Chiude la pinza per afferrare.
   - Riporta il braccio in posizione iniziale.
   - Ruota la base verso destra.
   - Muove il secondo braccio per posizionare l'oggetto.
   - Apre la pinza per rilasciare il cubo.
   - Torna nella posizione di riposo.

3. Alla fine della funzione, c'è un **ritardo infinito** (`delay(1000000000)`) per fermare il ciclo.

## ▶️ Come usare il codice

1. Collega i servomotori come indicato sopra.
2. Carica lo sketch su Arduino.
3. Il braccio inizierà automaticamente a muoversi per eseguire l'azione.
