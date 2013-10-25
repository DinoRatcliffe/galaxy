#### Make File ####
###################

CC = g++
CFLAGS = -g -I/usr/include/opencv2 -L/usr/lib/
SRCDIR = src
BINDIR = bin
PROGRAM = galaxy

$(PROGRAM): $(SRCDIR)/$(PROGRAM).cpp
	$(CC) $(CFLAGS) -o $(BINDIR)/$(PROGRAM) $(SRCDIR)/$(PROGRAM).cpp \
	-lopencv_highgui -lopencv_core -lopencv_imgproc -lm
