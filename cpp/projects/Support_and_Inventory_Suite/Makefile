# ===== Makefile (put this next to your .cpp/.hpp files) =====

# Compiler & flags
CXX       := g++
CXXSTD    := c++17
WARN      := -Wall -Wextra -Wpedantic
OPT_REL   := -O2
OPT_DBG   := -g -O0 -D_GLIBCXX_ASSERTIONS -fsanitize=address,undefined

# Optional: add include dirs like: INCLUDES := -Iinclude
INCLUDES  :=
DEFINES   :=
CXXFLAGS  := -std=$(CXXSTD) $(WARN) $(INCLUDES) $(DEFINES)
LDFLAGS   :=

# Build type (release by default). Use: make debug  or  make BUILD=debug
BUILD ?= release
ifeq ($(BUILD),debug)
  CXXFLAGS += $(OPT_DBG)
else
  CXXFLAGS += $(OPT_REL)
endif

# Auto-discover sources in the current directory
SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp,build/%.o,$(SOURCES))
DEPS    := $(OBJECTS:.o=.d)

# Output binary name (change if you want)
TARGET  := app

.PHONY: all debug release clean run rebuild

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile rule with automatic header dependency generation
build/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include generated .d files so changes in headers trigger rebuilds
-include $(DEPS)

debug:
	$(MAKE) BUILD=debug

release:
	$(MAKE) BUILD=release

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build $(TARGET)

rebuild: clean all
# ===== end Makefile =====
