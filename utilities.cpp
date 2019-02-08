#include "std_lib_facilities.h"
#include "utilities.h"


int randomWithLimits(int nedre, int ovre) {
	int heltTilfeldigTall = rand();
	ovre = ovre - nedre + 1;
	int tilfeldigMedGenser = (heltTilfeldigTall % ovre) + nedre;
	return tilfeldigMedGenser;
}