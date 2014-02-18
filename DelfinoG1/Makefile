CLIBS= 		-lm -lglut -lGL -lGLU -lX11 # 2014
#CPATHS=	-L/usr/X11R6/lib -I/usr/X11R6/include # 2011
CPATHS=		-I/usr/include -L/usr/lib # 2014
CFLAGS=		$(CPATHS)$(CLIBS)

OBJECTS = locations.o locationsMain.o

#targets-----------------------------
DelfinoG1:	$(OBJECTS)
		g++ $(OBJECTS) -o DelfinoG1 $(CFLAGS)

clean:
	rm *.o

#dependencies
locations.o:	locations.h tkmap.c
locationsMain.o:	locations.h vertices.h 

