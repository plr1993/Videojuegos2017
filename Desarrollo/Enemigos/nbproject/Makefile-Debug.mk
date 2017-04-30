#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Enemigo.o \
	${OBJECTDIR}/Juego.o \
	${OBJECTDIR}/Motor/Camera.o \
	${OBJECTDIR}/Motor/Render.o \
	${OBJECTDIR}/Motor/Sprite.o \
	${OBJECTDIR}/Motor/Text.o \
	${OBJECTDIR}/Personaje.o \
	${OBJECTDIR}/Update.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libsfml-graphics.so /usr/lib/x86_64-linux-gnu/libsfml-system.so /usr/lib/x86_64-linux-gnu/libsfml-window.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos
	${CP} /usr/lib/x86_64-linux-gnu/libsfml-window.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	-install_name_tool -change libsfml-window.so @rpath/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-window.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos
	${CP} /usr/lib/x86_64-linux-gnu/libsfml-graphics.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	-install_name_tool -change libsfml-graphics.so @rpath/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-graphics.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos
	${CP} /usr/lib/x86_64-linux-gnu/libsfml-system.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	-install_name_tool -change libsfml-system.so @rpath/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-system.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos: /usr/lib/x86_64-linux-gnu/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos: /usr/lib/x86_64-linux-gnu/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Enemigo.o: Enemigo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Enemigo.o Enemigo.cpp

${OBJECTDIR}/Juego.o: Juego.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Juego.o Juego.cpp

${OBJECTDIR}/Motor/Camera.o: Motor/Camera.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Camera.o Motor/Camera.cpp

${OBJECTDIR}/Motor/Render.o: Motor/Render.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Render.o Motor/Render.cpp

${OBJECTDIR}/Motor/Sprite.o: Motor/Sprite.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Sprite.o Motor/Sprite.cpp

${OBJECTDIR}/Motor/Text.o: Motor/Text.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Text.o Motor/Text.cpp

${OBJECTDIR}/Personaje.o: Personaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Personaje.o Personaje.cpp

${OBJECTDIR}/Update.o: Update.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Update.o Update.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-window.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-graphics.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-system.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/enemigos

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
