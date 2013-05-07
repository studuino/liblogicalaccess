#include <string>
#include <boost/shared_ptr.hpp>
#include "logicalaccess/ReaderProviders/ReaderProvider.h"
#include "MifareUltralightCChip.h"
#include "MifareUltralightChip.h"

#ifdef _MSC_VER
#include "logicalaccess/msliblogicalaccess.h"
#else
#ifndef LIBLOGICALACCESS_API
#define LIBLOGICALACCESS_API
#endif
#ifndef DISABLE_PRAGMA_WARNING
#define DISABLE_PRAGMA_WARNING /**< \brief winsmcrd.h was modified to support this macro, to avoid MSVC specific warnings pragma */
#endif
#endif

extern "C"
{
	LIBLOGICALACCESS_API char *getLibraryName()
	{
		return (char *)"MifareUltralight";
	}
	
	LIBLOGICALACCESS_API void getMifareUltralightCChip(boost::shared_ptr<LOGICALACCESS::Chip>* chip)
	{
		if (chip != NULL)
		{
			*chip = boost::shared_ptr<LOGICALACCESS::MifareUltralightCChip>(new LOGICALACCESS::MifareUltralightCChip());
		}
	}
	
	LIBLOGICALACCESS_API void getMifareUltralightChip(boost::shared_ptr<LOGICALACCESS::Chip>* chip)
	{
		if (chip != NULL)
		{
			*chip = boost::shared_ptr<LOGICALACCESS::MifareUltralightChip>(new LOGICALACCESS::MifareUltralightChip());
		}
	}

	LIBLOGICALACCESS_API bool getChipInfoAt(unsigned int index, char* chipname, size_t chipnamelen, void** getterfct)
	{
		bool ret = false;
		if (chipname != NULL && chipnamelen == PLUGINOBJECT_MAXLEN && getterfct != NULL)
		{
			switch (index)
			{
			case 0:
				{
					*getterfct = &getMifareUltralightChip;
					sprintf(chipname, CHIP_MIFAREULTRALIGHT);
					ret = true;
					break;
				}
			case 1:
				{
					*getterfct = &getMifareUltralightCChip;
					sprintf(chipname, CHIP_MIFAREULTRALIGHTC);
					ret = true;
					break;
				}
			}
		}

		return ret;
	}
}