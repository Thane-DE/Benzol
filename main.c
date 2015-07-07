#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct Frage {
	char* frage;
	char* antwort;
};

struct Frage fragenArray[18];
int bereitsGezogen[18] = { 0 }; //Array f�r schon vorgekommene Fragen

int random = 0; //Zufallswert f�r die Fragenauswahl
time_t t;

int x = 1; //FragenAnzahl, global
int z = 0; //Korrekte Fragen

char konkret_antwort[256]; //FragenAntwort

char Kurz[10] = "Kurz";
char Mittel[10] = "Mittel";
char Lang[10] = "Lang";

int random_lim(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void stelleFrage() {
	random = random_lim(0, 17); //Neuer Zufallswert

	if (bereitsGezogen[random] == 1) {
		//Die Frage gabs schon
		random = 0;
		stelleFrage();
		return;
	} else {
		//Setzt den Flag
		bereitsGezogen[random] = 1;

		//Stellt die Frage
		printf("\nFRAGE %i:\n", x);
		printf("%s\n", fragenArray[random].frage);
		printf("Deine Antwort: ");

		//Nimmt die Antwort an und gleicht sie ab
		fgets(konkret_antwort, 256, stdin);
		if (strcmp(konkret_antwort, fragenArray[random].antwort) == 0) {
			z++;
			printf("RICHTIG!\n");
			printf("----------------------------\n");
			random = 0;
			return;
		} else {
			printf("LEIDER FALSCH - Die korrekte Antwort lautet: %s\n",
					fragenArray[random].antwort);
			printf("----------------------------\n");
			random = 0;
			return;
		}
	}
}

int main(void) {

	//Gets the random seed for rand to use
	srand((unsigned) time(&t));

	//Initialisierung der Fragen
	fragenArray[0].frage =
			"Wie viele Ecken hat ein normaler Benzolring?\na=4, b=6, c=8, d=5";
	fragenArray[0].antwort = "b\n";
	fragenArray[1].frage =
			"Wer hat die Struktur des Benzols zuerst erkannt?\na=Keule, b=Kaeuler, c=Kekule d=Kuekule";
	fragenArray[1].antwort = "c\n";
	fragenArray[2].frage =
			"Wer war der Namensgeber des Benzols?\na=Justus von Liebig, b=Jakob von Haeuser, c=Johann Wolfgang Doebereiner,\nd=Dmitri Mendelejew";
	fragenArray[2].antwort = "a\n";
	fragenArray[3].frage =
			"Der Sidepunkt von Benzol betraegt (in Grad Celsius):";
	fragenArray[3].antwort = "80\n";
	fragenArray[4].frage =
			"Der Schmelzpunkt von Benzol betraegt (in Grad Celsius):";
	fragenArray[4].antwort = "5,5\n";
	fragenArray[5].frage =
			"Die Molekuelformel von Benzol lautet?\na=C6H6, b=C8H6, c=C6, d=AgNO3";
	fragenArray[5].antwort = "a\n";
	fragenArray[6].frage =
			"Was war nie ein Kriterium fuer die Bestimmung von aromatischen Verbindungen?\na=Wohlgeruch, b=Elektronensextett,\nc=Farblosigkeit, d=Hoeckel-Regel";
	fragenArray[6].antwort = "c\n";
	fragenArray[7].frage =
			"Was kann aus Benzol NICHT hergestellt werden? \na=Polystyrol, b=Polyamide, c=Glas d=Waschmittel";
	fragenArray[7].antwort = "c\n";
	fragenArray[8].frage =
			"Bei welcher Formel handelt es sich um ein Devirat des Benzols? a=C6H6OH, b=C4H6OH, c=H2SO4, d=AgNO3";
	fragenArray[8].antwort = "a\n";
	fragenArray[9].frage =
			"Wie viel Benzol darf maximal in Benzin enthalten sein, dass an deutschen Tankstellen verkauft wird (in \% Vol)?";
	fragenArray[9].antwort = "1\n";
	fragenArray[10].frage =
			"Wann wurde die heute gueltige Molekuelformel fuer Benzol akzeptiert?";
	fragenArray[10].antwort = "1860\n";
	fragenArray[11].frage =
			"Was unterscheidet ein gesaettigtes Molekuel von einem ungesaetitigten?\na=Es ist kein Fett,\nb=es gibt nur Mehrfachbindungen, c=Es gibt eine oder mehr Mehrfachbindungen";
	fragenArray[11].antwort = "c\n";
	fragenArray[12].frage =
			"Was ist kein Merkmal des Benzols?\na=Fuer den Menschen giftig, b=Fablos, c=Wasserstoff-Kohlenstoff Verhaeltnis von 2:1, d=ungesaettigt";
	fragenArray[12].antwort = "c\n";
	fragenArray[13].frage =
			"Sind die Elektronen im Benzol delokalisiert? \nj=Ja, n=Nein";
	fragenArray[13].antwort = "j\n";
	fragenArray[14].frage =
			"Kann man Benzol vollstaendig mit einer Lewis-Formel beschreiben?\nj=Ja, n=Nein";
	fragenArray[14].antwort = "n\n";
	fragenArray[15].frage =
			"Welches Aromat besteht aus zwei anliegenden Benzolringen?";
	fragenArray[15].antwort = "Naphthalin\n";
	fragenArray[16].frage =
			"Was ist kein Aromat?\na=Pyren, b=Bipen, c=Phenantren, d=Biphenyl";
	fragenArray[16].antwort = "b\n";
	fragenArray[17].frage =
			"Vervollstaendige: \"Benzol reagiert am liebsten mit elektro________\" ";
	fragenArray[17].antwort = "philen\n";
	random = 0;
	//Ende der Initialisierung

	printf("----------------------------\n");
	printf("WILKOMMEN BEIM BENZOL-QUIZ!\n");
	printf("----------------------------\n\n");
	printf("Bitte tippe die Rundenlaenge ein (Zahl zwischen 1 und 18): \n");

	char rundenLaenge_tmp[10];
	fgets(rundenLaenge_tmp, 10, stdin);
	int rundenLaenge = atoi(rundenLaenge_tmp);

	if (rundenLaenge > 18 || rundenLaenge < 1) {
		printf("FEHLER! Ungueltige Zahl!\n");
		printf("Druecke ENTER um das Spiel zu verlassen: ");
		getchar();
		exit(1);
	}

	for (x = 1; x <= rundenLaenge; x++) {
		stelleFrage();
	}
	z++;
	printf("FERTIG: Du hast %i von %i Fragen richtig beantwortet!\n", z-1, x-1);
	printf("Druecke ENTER um das Spiel zu verlassen: ");
	getchar();
	random = 0;
	exit(0);
}

