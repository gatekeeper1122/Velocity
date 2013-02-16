#ifndef FATXIO_H
#define FATXIO_H

#include "DeviceIO.h"
#include "../FileIO.h"
#include "../Fatx/FatxConstants.h"

class XBOXINTERNALSSHARED_EXPORT FatxIO : public BaseIO
{
public:
    FatxIO(DeviceIO *device, FatxFileEntry *entry);

    FatxFileEntry GetFatxFileEntry();

    void SetPosition(DWORD position);

    void ReadBytes(BYTE *outBuffer, DWORD len);

    void WriteBytes(BYTE *buffer, DWORD len);

    void SaveFile(std::string savePath, void(*progress)(void*, DWORD, DWORD) = NULL, void *arg = NULL);

private:
    DeviceIO *device;
    FatxFileEntry *entry;
    DWORD pos;
    DWORD maxReadConsecutive;
};

#endif // FATXIO_H
