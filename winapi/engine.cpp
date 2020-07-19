//
// ÌÎÄÓËÜ: ENGINE.CPP
//
// ÎÏÈÑÀÍÈÅ: ðåàëèçàöèÿ ìîäåëè äëÿ ðàáîòû ñ LinksPlatformDB file format
//
#include "engine.h"


LinksPlatformDB::LinksPlatformDB() {
	item.clear();
}


LinksPlatformDB::~LinksPlatformDB() {
	item.~vector();
}


UINT LinksPlatformDB::length() {
	return item.size();
}


void LinksPlatformDB::clear() {
	item.clear();
}


bool LinksPlatformDB::load(LPTSTR path) {
	FILE *f = fopen(path, "rb");
	if (f) {
		fread(&header, sizeof(LPFileHeader), 1, f);
		item.clear();
		LPItem x;
		while (fread(&x, sizeof(LPItem), 1, f)) {
			item.insert(item.end(), x);
		}
		fclose(f);
		return true;
	}
	return false;
}


void LinksPlatformDB::load(LinksPlatformDB& db) {
	this->item = db.item;
}

