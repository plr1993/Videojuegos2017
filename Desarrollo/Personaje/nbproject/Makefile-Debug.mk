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
	${OBJECTDIR}/Companyero.o \
	${OBJECTDIR}/Enemigo.o \
	${OBJECTDIR}/Estado.o \
	${OBJECTDIR}/Juego.o \
	${OBJECTDIR}/Mapa.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/Motor/Armas.o \
	${OBJECTDIR}/Motor/Bala.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personaje

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personaje: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/personaje ${OBJECTFILES} ${LDLIBSOPTIONS} -framework sfml-window -framework sfml-graphics -framework sfml-system

${OBJECTDIR}/Companyero.o: Companyero.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Companyero.o Companyero.cpp

${OBJECTDIR}/Enemigo.o: Enemigo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Enemigo.o Enemigo.cpp

${OBJECTDIR}/Estado.o: Estado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Estado.o Estado.cpp

${OBJECTDIR}/Juego.o: Juego.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Juego.o Juego.cpp

${OBJECTDIR}/Mapa.o: Mapa.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mapa.o Mapa.cpp

${OBJECTDIR}/Menu.o: Menu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/Motor/Armas.o: Motor/Armas.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Armas.o Motor/Armas.cpp

${OBJECTDIR}/Motor/Bala.o: Motor/Bala.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Bala.o Motor/Bala.cpp

${OBJECTDIR}/Motor/Camera.o: Motor/Camera.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Camera.o Motor/Camera.cpp

${OBJECTDIR}/Motor/Render.o: Motor/Render.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Render.o Motor/Render.cpp

${OBJECTDIR}/Motor/Sprite.o: Motor/Sprite.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Sprite.o Motor/Sprite.cpp

${OBJECTDIR}/Motor/Text.o: Motor/Text.cpp
	${MKDIR} -p ${OBJECTDIR}/Motor
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Motor/Text.o Motor/Text.cpp

${OBJECTDIR}/Personaje.o: Personaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Personaje.o Personaje.cpp

${OBJECTDIR}/Update.o: Update.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Update.o Update.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
