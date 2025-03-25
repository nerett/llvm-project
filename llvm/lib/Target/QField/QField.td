include "llvm/Target/Target.td"
include "QFieldRegisterInfo.td"
include "QFieldInstrInfo.td"
include "QFieldCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def QFieldInstrInfo : InstrInfo;
def QField : Target {
  let InstructionSet = QFieldInstrInfo;
}
