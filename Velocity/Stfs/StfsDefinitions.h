#ifndef STFSDEFINITIONS_H
#define STFSDEFINITIONS_H

#include "winnames.h"
#include "StfsConstants.h"
#include "FileIO.h"
#include <iostream>

using std::string;

struct LicenseEntry
{
    UINT64 licenseID;
    DWORD bits;
    DWORD flags;
};

struct VolumeDescriptor
{
    BYTE size;
    BYTE reserved;
    BYTE blockSeperation;
    WORD fileTableBlockCount;
    INT24 fileTableBlockNum;
    BYTE topHashTableHash[0x14];
    DWORD allocatedBlockCount;
    DWORD unallocatedBlockCount;
};

struct Certificate
{
    WORD publicKeyCertificateSize;
    BYTE ownerConsoleID[5];
    string ownerConsolePartNumber;
    ConsoleType ownerConsoleType;
    string dateGeneration;
    DWORD publicExponent;
    BYTE publicModulus[0x80];
    BYTE certificateSignature[0x100];
    BYTE signature[0x80];
};

void ReadVolumeDescriptorEx(VolumeDescriptor *descriptor, FileIO *io, DWORD address);

void WriteVolumeDescriptorEx(VolumeDescriptor *descriptor, FileIO *io, DWORD address);

void ReadCertificateEx(Certificate *cert, FileIO *io, DWORD address);

void WriteCertificateEx(Certificate *cert, FileIO *io, DWORD address);

string MagicToString(Magic magic);

string ContentTypeToString(ContentType type);

string ConsoleTypeToString(ConsoleType type);

#endif // STFSDEFINITIONS_H