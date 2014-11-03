//
// rsp/vfunctions.c: RSP vector execution functions.
//
// CEN64: Cycle-Accurate Nintendo 64 Simulator.
// Copyright (C) 2014, Tyler J. Stachecki.
//
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//

#define RSP_BUILD_OP(op, func, flags) \
  (RSP_##func)

#include "common.h"
#include "rsp/cpu.h"
#include "rsp/opcodes.h"
#include "rsp/opcodes_priv.h"
#include "rsp/rsp.h"

//
// VAND
//
rsp_vect_t RSP_VAND(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t result = rsp_vand(vs, vt_shuffle);

  rsp_vect_write_operand(acc + RSP_ACC_LO, result);
  return result;
}

//
// VINV
//
rsp_vect_t RSP_VINV(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
#ifndef NDEBUG
  struct rsp_rdex_latch *rdex_latch = &rsp->pipeline.rdex_latch;

  debug("Unimplemented instruction: %s [0x%.8X] @ 0x%.8X\n",
    rsp_vector_opcode_mnemonics[rdex_latch->opcode.id],
    iw, rdex_latch->common.pc);
#endif

  return zero;
}

//
// VMADN
//
rsp_vect_t RSP_VMADN(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t acc_lo, acc_md, acc_hi, result;

  acc_lo = rsp_vect_load_unshuffled_operand(acc + RSP_ACC_LO);
  acc_md = rsp_vect_load_unshuffled_operand(acc + RSP_ACC_MD);
  acc_hi = rsp_vect_load_unshuffled_operand(acc + RSP_ACC_HI);

  result = rsp_vmadn(vs, vt_shuffle, zero, &acc_lo, &acc_md, &acc_hi);

  rsp_vect_write_operand(acc + RSP_ACC_LO, acc_lo);
  rsp_vect_write_operand(acc + RSP_ACC_MD, acc_md);
  rsp_vect_write_operand(acc + RSP_ACC_HI, acc_hi);
  return result;
}

//
// VMUDL
//
rsp_vect_t RSP_VMUDL(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t result = rsp_vmudl(vs, vt_shuffle);

  rsp_vect_write_operand(acc + RSP_ACC_LO, result);
  rsp_vect_write_operand(acc + RSP_ACC_MD, zero);
  rsp_vect_write_operand(acc + RSP_ACC_HI, zero);
  return result;
}

//
// VMUDM
//
rsp_vect_t RSP_VMUDM(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t acc_lo, acc_md, acc_hi, result;

  result = rsp_vmudm(vs, vt_shuffle, &acc_lo, &acc_md, &acc_hi);

  rsp_vect_write_operand(acc + RSP_ACC_LO, acc_lo);
  rsp_vect_write_operand(acc + RSP_ACC_MD, acc_md);
  rsp_vect_write_operand(acc + RSP_ACC_HI, acc_hi);
  return result;
}

//
// VMUDN
//
rsp_vect_t RSP_VMUDN(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t acc_lo, acc_md, acc_hi, result;

  result = rsp_vmudn(vs, vt_shuffle, &acc_lo, &acc_md, &acc_hi);

  rsp_vect_write_operand(acc + RSP_ACC_LO, acc_lo);
  rsp_vect_write_operand(acc + RSP_ACC_MD, acc_md);
  rsp_vect_write_operand(acc + RSP_ACC_HI, acc_hi);
  return result;
}

//
// VNAND
//
rsp_vect_t RSP_VNAND(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t result = rsp_vnand(vs, vt_shuffle, zero);

  rsp_vect_write_operand(acc + RSP_ACC_LO, result);
  return result;
}

//
// VNOR
//
rsp_vect_t RSP_VNOR(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t result = rsp_vnor(vs, vt_shuffle, zero);

  rsp_vect_write_operand(acc + RSP_ACC_LO, result);
  return result;
}

//
// VNXOR
//
rsp_vect_t RSP_VNXOR(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t result = rsp_vnxor(vs, vt_shuffle, zero);

  rsp_vect_write_operand(acc + RSP_ACC_LO, result);
  return result;
}

//
// VOR
//
rsp_vect_t RSP_VOR(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t result = rsp_vor(vs, vt_shuffle);

  rsp_vect_write_operand(acc + RSP_ACC_LO, result);
  return result;
}

//
// VSAR
//
rsp_vect_t RSP_VSAR(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  unsigned e = GET_E(iw) & 0x3;

  assert(e < 3 && "Invalid element! Needs reversing.");
  return rsp_vect_load_unshuffled_operand(acc + (e << 3));
}

//
// VXOR
//
rsp_vect_t RSP_VXOR(struct rsp *rsp, uint32_t iw, uint16_t *acc,
  rsp_vect_t vs, rsp_vect_t vt, rsp_vect_t vt_shuffle, rsp_vect_t zero) {
  rsp_vect_t result = rsp_vxor(vs, vt_shuffle);

  rsp_vect_write_operand(acc + RSP_ACC_LO, result);
  return result;
}

// Function lookup table.
cen64_align(const rsp_vector_function
  rsp_vector_function_table[NUM_RSP_VECTOR_OPCODES], CACHE_LINE_SIZE) = {
#define X(op) op,
#include "rsp/vector_opcodes.md"
#undef X
};
