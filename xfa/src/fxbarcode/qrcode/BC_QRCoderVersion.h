// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef _BC_QRCODERVERSION_H_
#define _BC_QRCODERVERSION_H_
class CBC_QRCoderECBlocks;
class CBC_CommonBitMatrix;
class CBC_QRCoderErrorCorrectionLevel;
class CBC_QRCoderVersion {
 private:
  const static int32_t VERSION_DECODE_INFO[34];
  static CFX_PtrArray* VERSION;
  int32_t m_versionNumber;
  int32_t m_totalCodeWords;
  CFX_Int32Array m_alignmentPatternCenters;
  CFX_PtrArray m_ecBlocks;

  CBC_QRCoderVersion();
  CBC_QRCoderVersion(int32_t versionNumber,
                     CBC_QRCoderECBlocks* ecBlocks1,
                     CBC_QRCoderECBlocks* ecBlocks2,
                     CBC_QRCoderECBlocks* ecBlocks3,
                     CBC_QRCoderECBlocks* ecBlocks4);

 public:
  virtual ~CBC_QRCoderVersion();
  static void Initialize();
  static void Finalize();

  int32_t GetVersionNumber();
  int32_t GetTotalCodeWords();
  int32_t GetDimensionForVersion();
  CBC_CommonBitMatrix* BuildFunctionPattern(int32_t& e);
  CFX_Int32Array* GetAlignmentPatternCenters();
  CBC_QRCoderECBlocks* GetECBlocksForLevel(
      CBC_QRCoderErrorCorrectionLevel* ecLevel);
  static CBC_QRCoderVersion* GetVersionForNumber(int32_t versionNumber,
                                                 int32_t& e);
  static CBC_QRCoderVersion* GetProvisionalVersionForDimension(
      int32_t dimension,
      int32_t& e);
  static CBC_QRCoderVersion* DecodeVersionInformation(int32_t versionBits,
                                                      int32_t& e);
  static void Destroy();
};
#endif
