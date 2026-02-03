SIM = verilator
TOPLEVEL_LANG = verilog

# CPU top-level and BEQ integration test
TOPLEVEL = cpu
MODULE = loops

# RTL sources required for CPU
VERILOG_SOURCES = \
	$(PWD)/../cpu/alu_adder.sv \
	$(PWD)/../cpu/alu_logic.sv \
	$(PWD)/../cpu/alu_shifter.sv \
	$(PWD)/../cpu/alu.sv \
	$(PWD)/../cpu/branch.sv \
	$(PWD)/../cpu/control.sv \
	$(PWD)/../cpu/dataMemory.sv \
	$(PWD)/../cpu/decoder.sv \
	$(PWD)/../cpu/pc.sv \
	$(PWD)/../cpu/registerFile.sv \
	$(PWD)/../cpu/signExtender.sv \
	$(PWD)/../cpu/cpu.sv

VERILATOR_FLAGS += -sv

include $(shell cocotb-config --makefiles)/Makefile.sim