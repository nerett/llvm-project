//===----------------------------------------------------------------------===//
// QField profiles and nodes
//===----------------------------------------------------------------------===//

def qfield_ret      : SDNode<"QFieldISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "QFieldInstrFormats.td"

//===----------------------------------------------------------------------===//
// QField Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class QFImmAsmOperand<int width> : AsmOperandClass {
  let Name = "QFImm" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def qfimm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = QFImmAsmOperand<16>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeQFImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_QFIELDM16";
  let OperandNamespace = "QFieldOp";
}

//===----------------------------------------------------------------------===//
// QField Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1 in
def BR : QFieldInst<0x0, (outs), (ins GPR:$rs1), "BR $rs1",
                  [(brind GPR:$rs1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : QFieldPseudoInst<(outs), (ins), "# PseudoRET",
                [(qfield_ret)]>,
                PseudoInstExpansion<(BR R0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1 in
def MOVLI : QFieldInst<0x0, (outs GPR:$rd), (ins qfimm16:$imm),
                     "MOVli $rd $imm",
                     [(set GPR:$rd, qfimm16:$imm)]>;
