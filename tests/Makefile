SIM = verilator
TOPLEVEL_LANG = verilog

# Use CPU as the toplevel for the sw integration test
TOPLEVEL = cpu
MODULE = sw

# All RTL sources needed by the toplevel
VERILOG_SOURCES = \
  $(PWD)/../cpu/cpu.sv \
  $(PWD)/../cpu/alu.sv \
  $(PWD)/../cpu/control.sv \
  $(PWD)/../cpu/dataMemory.sv \
  $(PWD)/../cpu/decoder.sv \
  $(PWD)/../cpu/registerFile.sv \
  $(PWD)/../cpu/signExtender.sv

include $(shell cocotb-config --makefiles)/Makefile.sim

VERILATOR_FLAGS += -sv

#		works
#registerFile
#decoder
#alu (passes for add, other operations relativly simple to add)
#Sign Extender
#Data Memory
#Control
