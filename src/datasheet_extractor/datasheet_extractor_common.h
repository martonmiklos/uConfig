#ifndef DATASHEET_EXTRACTOR_COMMON_H
#define DATASHEET_EXTRACTOR_COMMON_H

#include <qglobal.h>
#if defined(DATASHEET_EXTRACTOR_EXPORT_LIB)
 #define DATASHEET_EXTRACTOR_EXPORT Q_DECL_EXPORT
#else
 #define DATASHEET_EXTRACTOR_EXPORT Q_DECL_IMPORT
#endif

#endif // DATASHEET_EXTRACTOR_COMMON_H
