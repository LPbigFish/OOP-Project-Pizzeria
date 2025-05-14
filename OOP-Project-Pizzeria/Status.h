#pragma once

enum STATUS
{
	PRIJATO,
	PRIPRAVUJEME,
	DORUCOVANI,
	DORUCENO,
	HOTOVO,
	ZRUSENO,
	ERROR
};

// Funkce pro pøevod statusu na string
inline const char* statusToString(STATUS status) {
	switch (status) {
		case PRIJATO: return "PRIJATO";
		case PRIPRAVUJEME: return "PRIPRAVUJEME";
		case DORUCOVANI: return "DORUCOVANI";
		case DORUCENO: return "DORUCENO";
		case HOTOVO: return "HOTOVO";
		case ZRUSENO: return "ZRUSENO";
		default: return "ERROR";
	}
}