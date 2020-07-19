//
// ЗАГОЛОВОК МОДУЛЯ: ENGINE.CPP
//
// НАЗНАЧЕНИЕ: средство для работы с PhoneDB
//

#ifndef engine_h_
#define engine_h_

#include "include.h"
#include <vector>

struct LPFileHeader {
	INT64 AllocatedLinks, ReservedLinks,
	      FreeLinks, FirstFreeLink,
	      RootAsSource, RootAsTarget,
	      LastFreeLink, Reserved;
};

struct LPItem {
	INT64 Source, Target,
	      LeftAsSource, RightAsSource, SizeAsSource,
	      LeftAsTarget, RightAsTarget, SizeAsTarget;
};

class LinksPlatformDB {
	public:
		LPFileHeader header;
		std::vector<LPItem> item;
		
	public:
		LinksPlatformDB();
		~LinksPlatformDB();
		
		UINT length();                // количество записей в БД
		void clear();                 // очистить БД

		bool load(LPTSTR);            // загрузить записи из файла
		void load(LinksPlatformDB&);  // загрузить записи из другой бд
};


#endif
