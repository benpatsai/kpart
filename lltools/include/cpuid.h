#pragma once

#include <stdint.h>

class CPUID {
  uint32_t regs[4];

public:
  explicit CPUID(uint32_t eax, uint32_t ecx) {
    asm volatile("cpuid"
                 : "=a"(regs[0]), "=b"(regs[1]), "=c"(regs[2]), "=d"(regs[3])
                 : "a"(eax), "c"(ecx));
  }

  const uint32_t &EAX() const { return regs[0]; }
  const uint32_t &EBX() const { return regs[1]; }
  const uint32_t &ECX() const { return regs[2]; }
  const uint32_t &EDX() const { return regs[3]; }
};
