#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(x) Sleep((x) / 1000)
#define sleep(x) Sleep((x) * 1000)
#else
#include <unistd.h>
#endif

// Funktionsdeklarationen
void files_suchen();
void drucken();
void vorheizen();
void spule_wechseln();

// Hauptfunktion mit Menü
int main() {
    int auswahl;

    while (1) {
        printf("\n=== 3D DRUCKER MENÜ ===\n");
        printf("1 - Files suchen\n");
        printf("2 - Drucken\n");
        printf("3 - Vorheizen\n");
        printf("4 - Spule wechseln\n");
        printf("0 - Beenden\n");
        printf("Auswahl: ");
        scanf("%d", &auswahl);

        switch (auswahl) {
            case 1: files_suchen(); break;
            case 2: drucken(); break;
            case 3: vorheizen(); break;
            case 4: spule_wechseln(); break;
            case 0: return 0;
            default: printf("Ungültige Eingabe.\n");
        }
    }
}

// Funktionsdefinitionen

void files_suchen() {
    printf("Funktion: files_suchen\n");
}

void drucken() {
    printf("Funktion: drucken\n");

    int zielTemp = 240; // Beispielwert
    int dauer = 30;     // Beispiel: 30 Sekunden

    printf("Datei gelesen: Zieltemperatur = %d°C, Druckdauer = %ds\n", zielTemp, dauer);

    int temp = 0;
    while (temp < zielTemp) {
        temp += 5;
        printf("Temperatur: %d°C\n", temp);
        usleep(100000);
    }

    printf("Spule dreht (Filament wird eingezogen)...\n");
    sleep(2);

    printf("Druckvorgang läuft...\n");
    sleep(2);

    printf("Druck abgeschlossen!\n");
}

void vorheizen() {
    int ziel;
    printf("VORHEIZEN\nGewünschte Temperatur (°C): ");
    scanf("%d", &ziel);

    int temp = 0;
    while (temp < ziel) {
        temp++;
        printf("Temperatur: %d°C\n", temp);
        usleep(100000);
    }

    printf("Vorheizen abgeschlossen.\n");
}

void spule_wechseln() {
    char ok;
    printf("SPULENWECHSEL\nDeckel öffnen und OK drücken (Taste o): ");
    scanf(" %c", &ok);

    int temp = 0;
    while (temp < 240) {
        temp += 5;
        printf("Temperatur: %d°C\n", temp);
        usleep(100000);
    }

    printf("Filament wird entfernt (gegen Uhrzeigersinn)...\n");
    sleep(4);

    printf("Neue Spule einsetzen und OK drücken (Taste o): ");
    scanf(" %c", &ok);

    printf("Filament wird geladen (Uhrzeigersinn)...\n");
    sleep(2);

    while (temp > 0) {
        temp -= 10;
        if (temp < 0) temp = 0;
        printf("Abkühlen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Spulenwechsel abgeschlossen.\n");
}