#ifndef LLVM_LIB_TARGET_NEMESYS_MCTARGETDESC_NEMESYSMCTARGETDESC_H
#define LLVM_LIB_TARGET_NEMESYS_MCTARGETDESC_NEMESYSMCTARGETDESC_H

#include "llvm/ADT/StringRef.h"

namespace llvm {
class Target;
class Triple;
class MCInstrInfo;
class MCContext;
class MCCodeEmitter;
class MCRegisterInfo;
class MCAsmBackend;
class MCTargetOptions;
class MCObjectWriter;
class raw_pwrite_stream;

Target &getTheNemesysTarget();

MCAsmBackend *createNemesysAsmBackend(const Target &, const MCRegisterInfo &,
                                      const Triple &, StringRef,
                                      const MCTargetOptions &);

MCCodeEmitter *createNemesysMCCodeEmitter(const MCInstrInfo &,
                                          const MCRegisterInfo &, MCContext &);

std::unique_ptr<MCObjectWriter>
createNemesysELFObjectWriter(raw_pwrite_stream &, uint8_t);

} // namespace llvm

#define GET_REGINFO_ENUM
#include "NemesysGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "NemesysGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "NemesysGenSubtargetInfo.inc"

#endif
