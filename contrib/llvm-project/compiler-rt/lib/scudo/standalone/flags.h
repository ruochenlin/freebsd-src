//===-- flags.h -------------------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef SCUDO_FLAGS_H_
#define SCUDO_FLAGS_H_

#include "internal_defs.h"

namespace scudo {

struct Flags {
#define SCUDO_FLAG(Type, Name, DefaultValue, Description) Type Name;
#include "flags.inc"
#undef SCUDO_FLAG
  void setDefaults();
};

Flags *getFlags();
void initFlags();
class FlagParser;
void registerFlags(FlagParser *Parser, Flags *F);

} // namespace scudo

#endif // SCUDO_FLAGS_H_
