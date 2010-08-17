/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2010 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef GDCMTRANSFERSYNTAX__H
#define GDCMTRANSFERSYNTAX__H

#include "gdcmTypes.h"
#include "gdcmTransferSyntax.h"
#include "gdcmUIDs.h"

namespace gdcm
{

namespace network
{

/**
Table 9-15
TRANSFER SYNTAX SUB-ITEM FIELDS


TODO what is the goal of :

Table 9-19
TRANSFER SYNTAX SUB-ITEM FIELDS
 */
class TransferSyntax_
{
public:
  TransferSyntax_();
  void SetName( const char *name );
  const char *GetName() const { return Name.c_str(); }

  // accept a gdcm::UIDs::TSType also... 
  void SetNameFromUID( gdcm::UIDs::TSName tsname );

  std::istream &Read(std::istream &is);
  const std::ostream &Write(std::ostream &os) const;
  size_t Size() const;
private:
  void UpdateName( const char *name );

  static const uint8_t ItemType;
  static const uint8_t Reserved2;
  uint16_t ItemLength; // len of
  std::string /*TransferSyntax_*/ Name; // UID
};

} // end namespace network

} // end namespace gdcm

#endif //GDCMTRANSFERSYNTAX__H