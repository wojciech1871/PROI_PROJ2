#
# TODO:
#

CC = g++
SRCDIR = src
BUILDDIR = build
TARGET = bin/main

SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS = -g -Wall -std=c++11
# LIB =
INC = -I include
BOOST = -lboost_unit_test_framework

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@echo "$(CC) $^ -o $(TARGET) $(LIB)"
	$(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..."
	@echo "$(RM) -r $(BUILDDIR) $(TARGET)"
	$(RM) -r $(BUILDDIR) $(TARGET);

#Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(BOOST) $(BUILDDIR)/ -o bin/

#Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

	.PHONY all clean
