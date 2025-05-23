# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f VCombinational_top.mk

default: /home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/build/Combinational_top

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = VCombinational_top
# Module prefix (from --prefix)
VM_MODPREFIX = VCombinational_top
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-MMD \
	-O3 \
	-I/usr/include/SDL2 \
	-D_REENTRANT \
	-I/home/yjx/ysyx-workbench/nvboard/usr/include \
	-DTOP_NAME="VCombinational_top" \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
	/home/yjx/ysyx-workbench/nvboard/build/nvboard.a \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	auto_bind \
	Combinational_top \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	/home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/build \
	/home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/csrc \


### Default rules...
# Include list of all generated classes
include VCombinational_top_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

auto_bind.o: /home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/build/auto_bind.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
Combinational_top.o: /home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/csrc/Combinational_top.cpp
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<

### Link rules... (from --exe)
/home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/build/Combinational_top: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-
