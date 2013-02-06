#############################################################################
# Makefile for building: main
# Generated by qmake (2.01a) (Qt 4.8.4) on: so �no 2 18:17:34 2013
# Project:  NeuralNetCreator.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt/mkspecs/linux-g++-64 CONFIG+=debug CONFIG+=declarative_debug -o Makefile NeuralNetCreator.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt/mkspecs/linux-g++-64 -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include/QtWebKit -I/usr/include -I/usr/include/QtTest -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1,--sort-common,--as-needed,-z,relro
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtTest -lQtWebKit -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		Application/MainWindow.cpp \
		NeuralNetwork/Neuron.cpp \
		Test/NeuronTest.cpp \
		Util/function.cpp \
		Project/Project.cpp \
		Dialog/AboutDialog.cpp \
		Project/Workspace.cpp \
		Dialog/NewProjectDialog.cpp \
		Project/LearningConfigModel.cpp \
		Application/WelcomeWidget.cpp \
		Application/TopologyWidget.cpp \
		Application/LearningWidget.cpp \
		Application/HelpWidget.cpp \
		Application/LayerEditWidget.cpp \
		Application/NoModelWidget.cpp \
		Dialog/TextViewBoxDialog.cpp \
		Dialog/NewTestScnDialog.cpp \
		Application/OutputGraphWidget.cpp \
		Application/DatasetTestWidget.cpp \
		Project/BaseModel.cpp \
		Project/DatasetEditModel.cpp \
		Project/TopologyEditModel.cpp \
		Project/DatasetTestModel.cpp \
		Project/GraphTestModel.cpp \
		Application/DatasetEditWidget.cpp \
		NeuralNetwork/Dataset.cpp \
		Test/DatasetTest.cpp \
		NeuralNetwork/BpNetSt.cpp \
		Test/BpNetStTest.cpp \
		NeuralNetwork/BpAlgSt.cpp \
		Test/BpAlgStTest.cpp moc_MainWindow.cpp \
		moc_NeuronTest.cpp \
		moc_AboutDialog.cpp \
		moc_Workspace.cpp \
		moc_NewProjectDialog.cpp \
		moc_WelcomeWidget.cpp \
		moc_TopologyWidget.cpp \
		moc_LearningWidget.cpp \
		moc_HelpWidget.cpp \
		moc_LayerEditWidget.cpp \
		moc_NoModelWidget.cpp \
		moc_TextViewBoxDialog.cpp \
		moc_NewTestScnDialog.cpp \
		moc_OutputGraphWidget.cpp \
		moc_DatasetTestWidget.cpp \
		moc_DatasetEditModel.cpp \
		moc_DatasetEditWidget.cpp \
		moc_DatasetTest.cpp \
		moc_BpNetStTest.cpp \
		moc_BpAlgSt.cpp \
		moc_BpAlgStTest.cpp \
		qrc_styles.cpp
OBJECTS       = main.o \
		MainWindow.o \
		Neuron.o \
		NeuronTest.o \
		function.o \
		Project.o \
		AboutDialog.o \
		Workspace.o \
		NewProjectDialog.o \
		LearningConfigModel.o \
		WelcomeWidget.o \
		TopologyWidget.o \
		LearningWidget.o \
		HelpWidget.o \
		LayerEditWidget.o \
		NoModelWidget.o \
		TextViewBoxDialog.o \
		NewTestScnDialog.o \
		OutputGraphWidget.o \
		DatasetTestWidget.o \
		BaseModel.o \
		DatasetEditModel.o \
		TopologyEditModel.o \
		DatasetTestModel.o \
		GraphTestModel.o \
		DatasetEditWidget.o \
		Dataset.o \
		DatasetTest.o \
		BpNetSt.o \
		BpNetStTest.o \
		BpAlgSt.o \
		BpAlgStTest.o \
		moc_MainWindow.o \
		moc_NeuronTest.o \
		moc_AboutDialog.o \
		moc_Workspace.o \
		moc_NewProjectDialog.o \
		moc_WelcomeWidget.o \
		moc_TopologyWidget.o \
		moc_LearningWidget.o \
		moc_HelpWidget.o \
		moc_LayerEditWidget.o \
		moc_NoModelWidget.o \
		moc_TextViewBoxDialog.o \
		moc_NewTestScnDialog.o \
		moc_OutputGraphWidget.o \
		moc_DatasetTestWidget.o \
		moc_DatasetEditModel.o \
		moc_DatasetEditWidget.o \
		moc_DatasetTest.o \
		moc_BpNetStTest.o \
		moc_BpAlgSt.o \
		moc_BpAlgStTest.o \
		qrc_styles.o
DIST          = /usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/common/gcc-base.conf \
		/usr/share/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt/mkspecs/common/g++-base.conf \
		/usr/share/qt/mkspecs/common/g++-unix.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/debug.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/qtestlib.prf \
		/usr/share/qt/mkspecs/features/declarative_debug.prf \
		/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		NeuralNetCreator.pro
QMAKE_TARGET  = main
DESTDIR       = 
TARGET        = main

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_MainWindow.h ui_AboutDialog.h ui_NewProjectDialog.h ui_WelcomeWidget.h ui_TopologyWidget.h ui_LearningWidget.h ui_HelpWidget.h ui_LayerEditWidget.h ui_NoModelWidget.h ui_TextViewBoxDialog.h ui_NewTestScnDialog.h ui_OutputGraphWidget.h ui_DatasetTestWidget.h ui_DatasetEditWidget.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: NeuralNetCreator.pro  /usr/share/qt/mkspecs/linux-g++-64/qmake.conf /usr/share/qt/mkspecs/common/unix.conf \
		/usr/share/qt/mkspecs/common/linux.conf \
		/usr/share/qt/mkspecs/common/gcc-base.conf \
		/usr/share/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt/mkspecs/common/g++-base.conf \
		/usr/share/qt/mkspecs/common/g++-unix.conf \
		/usr/share/qt/mkspecs/qconfig.pri \
		/usr/share/qt/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt/mkspecs/features/qt_functions.prf \
		/usr/share/qt/mkspecs/features/qt_config.prf \
		/usr/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt/mkspecs/features/default_pre.prf \
		/usr/share/qt/mkspecs/features/debug.prf \
		/usr/share/qt/mkspecs/features/default_post.prf \
		/usr/share/qt/mkspecs/features/qtestlib.prf \
		/usr/share/qt/mkspecs/features/declarative_debug.prf \
		/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt/mkspecs/features/warn_on.prf \
		/usr/share/qt/mkspecs/features/qt.prf \
		/usr/share/qt/mkspecs/features/unix/thread.prf \
		/usr/share/qt/mkspecs/features/moc.prf \
		/usr/share/qt/mkspecs/features/resources.prf \
		/usr/share/qt/mkspecs/features/uic.prf \
		/usr/share/qt/mkspecs/features/yacc.prf \
		/usr/share/qt/mkspecs/features/lex.prf \
		/usr/share/qt/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtTest.prl \
		/usr/lib/libQtWebKit.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt/mkspecs/linux-g++-64 CONFIG+=debug CONFIG+=declarative_debug -o Makefile NeuralNetCreator.pro
/usr/share/qt/mkspecs/common/unix.conf:
/usr/share/qt/mkspecs/common/linux.conf:
/usr/share/qt/mkspecs/common/gcc-base.conf:
/usr/share/qt/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt/mkspecs/common/g++-base.conf:
/usr/share/qt/mkspecs/common/g++-unix.conf:
/usr/share/qt/mkspecs/qconfig.pri:
/usr/share/qt/mkspecs/modules/qt_phonon.pri:
/usr/share/qt/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt/mkspecs/features/qt_functions.prf:
/usr/share/qt/mkspecs/features/qt_config.prf:
/usr/share/qt/mkspecs/features/exclusive_builds.prf:
/usr/share/qt/mkspecs/features/default_pre.prf:
/usr/share/qt/mkspecs/features/debug.prf:
/usr/share/qt/mkspecs/features/default_post.prf:
/usr/share/qt/mkspecs/features/qtestlib.prf:
/usr/share/qt/mkspecs/features/declarative_debug.prf:
/usr/share/qt/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt/mkspecs/features/warn_on.prf:
/usr/share/qt/mkspecs/features/qt.prf:
/usr/share/qt/mkspecs/features/unix/thread.prf:
/usr/share/qt/mkspecs/features/moc.prf:
/usr/share/qt/mkspecs/features/resources.prf:
/usr/share/qt/mkspecs/features/uic.prf:
/usr/share/qt/mkspecs/features/yacc.prf:
/usr/share/qt/mkspecs/features/lex.prf:
/usr/share/qt/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtTest.prl:
/usr/lib/libQtWebKit.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt/mkspecs/linux-g++-64 CONFIG+=debug CONFIG+=declarative_debug -o Makefile NeuralNetCreator.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/main1.0.0 || $(MKDIR) .tmp/main1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/main1.0.0/ && $(COPY_FILE) --parents Util/Exception.h Application/MainWindow.h NeuralNetwork/Neuron.h Util/Array.h Test/NeuronTest.h Util/function.h Project/Project.h Dialog/AboutDialog.h Project/Workspace.h Dialog/NewProjectDialog.h Project/LearningConfigModel.h Application/WelcomeWidget.h Application/TopologyWidget.h Application/LearningWidget.h Application/HelpWidget.h Application/LayerEditWidget.h Application/NoModelWidget.h Dialog/TextViewBoxDialog.h Dialog/NewTestScnDialog.h Application/OutputGraphWidget.h Application/DatasetTestWidget.h Project/BaseModel.h Project/DatasetEditModel.h Project/TopologyEditModel.h Project/DatasetTestModel.h Project/GraphTestModel.h Application/DatasetEditWidget.h NeuralNetwork/Dataset.h NeuralNetwork/AbstractDataset.h Test/DatasetTest.h NeuralNetwork/AbstractBpNet.h NeuralNetwork/BpNetSt.h Test/BpNetStTest.h NeuralNetwork/BpAlgSt.h NeuralNetwork/AbstractLrnAlg.h Test/BpAlgStTest.h .tmp/main1.0.0/ && $(COPY_FILE) --parents styles.qrc .tmp/main1.0.0/ && $(COPY_FILE) --parents main.cpp Application/MainWindow.cpp NeuralNetwork/Neuron.cpp Test/NeuronTest.cpp Util/function.cpp Project/Project.cpp Dialog/AboutDialog.cpp Project/Workspace.cpp Dialog/NewProjectDialog.cpp Project/LearningConfigModel.cpp Application/WelcomeWidget.cpp Application/TopologyWidget.cpp Application/LearningWidget.cpp Application/HelpWidget.cpp Application/LayerEditWidget.cpp Application/NoModelWidget.cpp Dialog/TextViewBoxDialog.cpp Dialog/NewTestScnDialog.cpp Application/OutputGraphWidget.cpp Application/DatasetTestWidget.cpp Project/BaseModel.cpp Project/DatasetEditModel.cpp Project/TopologyEditModel.cpp Project/DatasetTestModel.cpp Project/GraphTestModel.cpp Application/DatasetEditWidget.cpp NeuralNetwork/Dataset.cpp Test/DatasetTest.cpp NeuralNetwork/BpNetSt.cpp Test/BpNetStTest.cpp NeuralNetwork/BpAlgSt.cpp Test/BpAlgStTest.cpp .tmp/main1.0.0/ && $(COPY_FILE) --parents ApplicationUi/MainWindow.ui DialogUi/AboutDialog.ui DialogUi/NewProjectDialog.ui ApplicationUi/WelcomeWidget.ui ApplicationUi/TopologyWidget.ui ApplicationUi/LearningWidget.ui ApplicationUi/HelpWidget.ui ApplicationUi/LayerEditWidget.ui ApplicationUi/NoModelWidget.ui DialogUi/TextViewBoxDialog.ui DialogUi/NewTestScnDialog.ui ApplicationUi/OutputGraphWidget.ui ApplicationUi/DatasetTestWidget.ui ApplicationUi/DatasetEditWidget.ui .tmp/main1.0.0/ && (cd `dirname .tmp/main1.0.0` && $(TAR) main1.0.0.tar main1.0.0 && $(COMPRESS) main1.0.0.tar) && $(MOVE) `dirname .tmp/main1.0.0`/main1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/main1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp moc_NeuronTest.cpp moc_AboutDialog.cpp moc_Workspace.cpp moc_NewProjectDialog.cpp moc_WelcomeWidget.cpp moc_TopologyWidget.cpp moc_LearningWidget.cpp moc_HelpWidget.cpp moc_LayerEditWidget.cpp moc_NoModelWidget.cpp moc_TextViewBoxDialog.cpp moc_NewTestScnDialog.cpp moc_OutputGraphWidget.cpp moc_DatasetTestWidget.cpp moc_DatasetEditModel.cpp moc_DatasetEditWidget.cpp moc_DatasetTest.cpp moc_BpNetStTest.cpp moc_BpAlgSt.cpp moc_BpAlgStTest.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp moc_NeuronTest.cpp moc_AboutDialog.cpp moc_Workspace.cpp moc_NewProjectDialog.cpp moc_WelcomeWidget.cpp moc_TopologyWidget.cpp moc_LearningWidget.cpp moc_HelpWidget.cpp moc_LayerEditWidget.cpp moc_NoModelWidget.cpp moc_TextViewBoxDialog.cpp moc_NewTestScnDialog.cpp moc_OutputGraphWidget.cpp moc_DatasetTestWidget.cpp moc_DatasetEditModel.cpp moc_DatasetEditWidget.cpp moc_DatasetTest.cpp moc_BpNetStTest.cpp moc_BpAlgSt.cpp moc_BpAlgStTest.cpp
moc_MainWindow.cpp: Application/WelcomeWidget.h \
		Application/DatasetEditWidget.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Application/TopologyWidget.h \
		Application/LayerEditWidget.h \
		Project/TopologyEditModel.h \
		Application/LearningWidget.h \
		Project/LearningConfigModel.h \
		Application/DatasetTestWidget.h \
		Project/DatasetTestModel.h \
		Project/Project.h \
		Project/GraphTestModel.h \
		Application/HelpWidget.h \
		Application/NoModelWidget.h \
		Application/OutputGraphWidget.h \
		Project/Workspace.h \
		Application/MainWindow.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/MainWindow.h -o moc_MainWindow.cpp

moc_NeuronTest.cpp: NeuralNetwork/Neuron.h \
		Test/NeuronTest.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Test/NeuronTest.h -o moc_NeuronTest.cpp

moc_AboutDialog.cpp: Dialog/AboutDialog.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Dialog/AboutDialog.h -o moc_AboutDialog.cpp

moc_Workspace.cpp: Project/Project.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Project/TopologyEditModel.h \
		Project/LearningConfigModel.h \
		Project/DatasetTestModel.h \
		Project/GraphTestModel.h \
		Project/Workspace.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Project/Workspace.h -o moc_Workspace.cpp

moc_NewProjectDialog.cpp: Dialog/NewProjectDialog.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Dialog/NewProjectDialog.h -o moc_NewProjectDialog.cpp

moc_WelcomeWidget.cpp: Application/WelcomeWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/WelcomeWidget.h -o moc_WelcomeWidget.cpp

moc_TopologyWidget.cpp: Application/LayerEditWidget.h \
		Project/TopologyEditModel.h \
		Project/BaseModel.h \
		Application/TopologyWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/TopologyWidget.h -o moc_TopologyWidget.cpp

moc_LearningWidget.cpp: Project/LearningConfigModel.h \
		Project/BaseModel.h \
		Application/LearningWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/LearningWidget.h -o moc_LearningWidget.cpp

moc_HelpWidget.cpp: Application/HelpWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/HelpWidget.h -o moc_HelpWidget.cpp

moc_LayerEditWidget.cpp: Project/TopologyEditModel.h \
		Project/BaseModel.h \
		Application/LayerEditWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/LayerEditWidget.h -o moc_LayerEditWidget.cpp

moc_NoModelWidget.cpp: Application/NoModelWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/NoModelWidget.h -o moc_NoModelWidget.cpp

moc_TextViewBoxDialog.cpp: Dialog/TextViewBoxDialog.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Dialog/TextViewBoxDialog.h -o moc_TextViewBoxDialog.cpp

moc_NewTestScnDialog.cpp: Project/Project.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Project/TopologyEditModel.h \
		Project/LearningConfigModel.h \
		Project/DatasetTestModel.h \
		Project/GraphTestModel.h \
		Dialog/NewTestScnDialog.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Dialog/NewTestScnDialog.h -o moc_NewTestScnDialog.cpp

moc_OutputGraphWidget.cpp: Project/GraphTestModel.h \
		Project/BaseModel.h \
		Application/OutputGraphWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/OutputGraphWidget.h -o moc_OutputGraphWidget.cpp

moc_DatasetTestWidget.cpp: Project/DatasetTestModel.h \
		Project/BaseModel.h \
		Project/Project.h \
		Project/DatasetEditModel.h \
		Project/TopologyEditModel.h \
		Project/LearningConfigModel.h \
		Project/GraphTestModel.h \
		Application/DatasetTestWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/DatasetTestWidget.h -o moc_DatasetTestWidget.cpp

moc_DatasetEditModel.cpp: Project/BaseModel.h \
		Project/DatasetEditModel.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Project/DatasetEditModel.h -o moc_DatasetEditModel.cpp

moc_DatasetEditWidget.cpp: Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Application/DatasetEditWidget.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Application/DatasetEditWidget.h -o moc_DatasetEditWidget.cpp

moc_DatasetTest.cpp: NeuralNetwork/Dataset.h \
		NeuralNetwork/AbstractDataset.h \
		Test/DatasetTest.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Test/DatasetTest.h -o moc_DatasetTest.cpp

moc_BpNetStTest.cpp: NeuralNetwork/BpNetSt.h \
		NeuralNetwork/AbstractBpNet.h \
		NeuralNetwork/Neuron.h \
		Test/BpNetStTest.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Test/BpNetStTest.h -o moc_BpNetStTest.cpp

moc_BpAlgSt.cpp: NeuralNetwork/AbstractLrnAlg.h \
		NeuralNetwork/AbstractBpNet.h \
		NeuralNetwork/Neuron.h \
		NeuralNetwork/AbstractDataset.h \
		NeuralNetwork/BpAlgSt.h
	/usr/bin/moc $(DEFINES) $(INCPATH) NeuralNetwork/BpAlgSt.h -o moc_BpAlgSt.cpp

moc_BpAlgStTest.cpp: NeuralNetwork/BpAlgSt.h \
		NeuralNetwork/AbstractLrnAlg.h \
		NeuralNetwork/AbstractBpNet.h \
		NeuralNetwork/Neuron.h \
		NeuralNetwork/AbstractDataset.h \
		Test/BpAlgStTest.h
	/usr/bin/moc $(DEFINES) $(INCPATH) Test/BpAlgStTest.h -o moc_BpAlgStTest.cpp

compiler_rcc_make_all: qrc_styles.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_styles.cpp
qrc_styles.cpp: styles.qrc \
		Resources/appIcon16.png \
		Resources/datasetIcon32.png \
		Resources/up22.png \
		Resources/toolbarMidLight.png \
		Resources/start22.png \
		Resources/copy22.png \
		Resources/neuron3w.png \
		Resources/toolbar.png \
		Resources/helpIcon32.png \
		Resources/toolbarLight.png \
		Resources/newDoc22.png \
		Resources/neuron1w.png \
		Resources/clear22.png \
		Resources/neuralNetwork128.png \
		Resources/spinBoxUp.png \
		Resources/topologyIcon32.png \
		Resources/neuralNetwork32.png \
		Resources/close22.png \
		Resources/datasetTestIcon32.png \
		Resources/openDoc22.png \
		Resources/testingIcon32.png \
		Resources/toolmenu.png \
		Resources/stop22.png \
		Resources/spinBoxDown.png \
		Resources/add22.png \
		Resources/learningIcon32.png \
		Resources/down22.png \
		Resources/comboBoxArrow.png
	/usr/bin/rcc -name styles styles.qrc -o qrc_styles.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_MainWindow.h ui_AboutDialog.h ui_NewProjectDialog.h ui_WelcomeWidget.h ui_TopologyWidget.h ui_LearningWidget.h ui_HelpWidget.h ui_LayerEditWidget.h ui_NoModelWidget.h ui_TextViewBoxDialog.h ui_NewTestScnDialog.h ui_OutputGraphWidget.h ui_DatasetTestWidget.h ui_DatasetEditWidget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_MainWindow.h ui_AboutDialog.h ui_NewProjectDialog.h ui_WelcomeWidget.h ui_TopologyWidget.h ui_LearningWidget.h ui_HelpWidget.h ui_LayerEditWidget.h ui_NoModelWidget.h ui_TextViewBoxDialog.h ui_NewTestScnDialog.h ui_OutputGraphWidget.h ui_DatasetTestWidget.h ui_DatasetEditWidget.h
ui_MainWindow.h: ApplicationUi/MainWindow.ui
	/usr/bin/uic ApplicationUi/MainWindow.ui -o ui_MainWindow.h

ui_AboutDialog.h: DialogUi/AboutDialog.ui
	/usr/bin/uic DialogUi/AboutDialog.ui -o ui_AboutDialog.h

ui_NewProjectDialog.h: DialogUi/NewProjectDialog.ui
	/usr/bin/uic DialogUi/NewProjectDialog.ui -o ui_NewProjectDialog.h

ui_WelcomeWidget.h: ApplicationUi/WelcomeWidget.ui
	/usr/bin/uic ApplicationUi/WelcomeWidget.ui -o ui_WelcomeWidget.h

ui_TopologyWidget.h: ApplicationUi/TopologyWidget.ui
	/usr/bin/uic ApplicationUi/TopologyWidget.ui -o ui_TopologyWidget.h

ui_LearningWidget.h: ApplicationUi/LearningWidget.ui
	/usr/bin/uic ApplicationUi/LearningWidget.ui -o ui_LearningWidget.h

ui_HelpWidget.h: ApplicationUi/HelpWidget.ui
	/usr/bin/uic ApplicationUi/HelpWidget.ui -o ui_HelpWidget.h

ui_LayerEditWidget.h: ApplicationUi/LayerEditWidget.ui
	/usr/bin/uic ApplicationUi/LayerEditWidget.ui -o ui_LayerEditWidget.h

ui_NoModelWidget.h: ApplicationUi/NoModelWidget.ui
	/usr/bin/uic ApplicationUi/NoModelWidget.ui -o ui_NoModelWidget.h

ui_TextViewBoxDialog.h: DialogUi/TextViewBoxDialog.ui
	/usr/bin/uic DialogUi/TextViewBoxDialog.ui -o ui_TextViewBoxDialog.h

ui_NewTestScnDialog.h: DialogUi/NewTestScnDialog.ui
	/usr/bin/uic DialogUi/NewTestScnDialog.ui -o ui_NewTestScnDialog.h

ui_OutputGraphWidget.h: ApplicationUi/OutputGraphWidget.ui
	/usr/bin/uic ApplicationUi/OutputGraphWidget.ui -o ui_OutputGraphWidget.h

ui_DatasetTestWidget.h: ApplicationUi/DatasetTestWidget.ui
	/usr/bin/uic ApplicationUi/DatasetTestWidget.ui -o ui_DatasetTestWidget.h

ui_DatasetEditWidget.h: ApplicationUi/DatasetEditWidget.ui
	/usr/bin/uic ApplicationUi/DatasetEditWidget.ui -o ui_DatasetEditWidget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp Application/MainWindow.h \
		Application/WelcomeWidget.h \
		Application/DatasetEditWidget.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Application/TopologyWidget.h \
		Application/LayerEditWidget.h \
		Project/TopologyEditModel.h \
		Application/LearningWidget.h \
		Project/LearningConfigModel.h \
		Application/DatasetTestWidget.h \
		Project/DatasetTestModel.h \
		Project/Project.h \
		Project/GraphTestModel.h \
		Application/HelpWidget.h \
		Application/NoModelWidget.h \
		Application/OutputGraphWidget.h \
		Project/Workspace.h \
		Test/NeuronTest.h \
		NeuralNetwork/Neuron.h \
		Test/BpNetStTest.h \
		NeuralNetwork/BpNetSt.h \
		NeuralNetwork/AbstractBpNet.h \
		Test/BpAlgStTest.h \
		NeuralNetwork/BpAlgSt.h \
		NeuralNetwork/AbstractLrnAlg.h \
		NeuralNetwork/AbstractDataset.h \
		Test/DatasetTest.h \
		NeuralNetwork/Dataset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

MainWindow.o: Application/MainWindow.cpp Application/MainWindow.h \
		Application/WelcomeWidget.h \
		Application/DatasetEditWidget.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Application/TopologyWidget.h \
		Application/LayerEditWidget.h \
		Project/TopologyEditModel.h \
		Application/LearningWidget.h \
		Project/LearningConfigModel.h \
		Application/DatasetTestWidget.h \
		Project/DatasetTestModel.h \
		Project/Project.h \
		Project/GraphTestModel.h \
		Application/HelpWidget.h \
		Application/NoModelWidget.h \
		Application/OutputGraphWidget.h \
		Project/Workspace.h \
		ui_MainWindow.h \
		Dialog/AboutDialog.h \
		Dialog/NewProjectDialog.h \
		Dialog/NewTestScnDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o Application/MainWindow.cpp

Neuron.o: NeuralNetwork/Neuron.cpp NeuralNetwork/Neuron.h \
		Util/function.h \
		Util/Exception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Neuron.o NeuralNetwork/Neuron.cpp

NeuronTest.o: Test/NeuronTest.cpp Test/NeuronTest.h \
		NeuralNetwork/Neuron.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NeuronTest.o Test/NeuronTest.cpp

function.o: Util/function.cpp Util/function.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o function.o Util/function.cpp

Project.o: Project/Project.cpp Project/Project.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Project/TopologyEditModel.h \
		Project/LearningConfigModel.h \
		Project/DatasetTestModel.h \
		Project/GraphTestModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Project.o Project/Project.cpp

AboutDialog.o: Dialog/AboutDialog.cpp Dialog/AboutDialog.h \
		ui_AboutDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AboutDialog.o Dialog/AboutDialog.cpp

Workspace.o: Project/Workspace.cpp Project/Workspace.h \
		Project/Project.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Project/TopologyEditModel.h \
		Project/LearningConfigModel.h \
		Project/DatasetTestModel.h \
		Project/GraphTestModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Workspace.o Project/Workspace.cpp

NewProjectDialog.o: Dialog/NewProjectDialog.cpp Dialog/NewProjectDialog.h \
		ui_NewProjectDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NewProjectDialog.o Dialog/NewProjectDialog.cpp

LearningConfigModel.o: Project/LearningConfigModel.cpp Project/LearningConfigModel.h \
		Project/BaseModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LearningConfigModel.o Project/LearningConfigModel.cpp

WelcomeWidget.o: Application/WelcomeWidget.cpp Application/WelcomeWidget.h \
		ui_WelcomeWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o WelcomeWidget.o Application/WelcomeWidget.cpp

TopologyWidget.o: Application/TopologyWidget.cpp Application/TopologyWidget.h \
		Application/LayerEditWidget.h \
		Project/TopologyEditModel.h \
		Project/BaseModel.h \
		ui_TopologyWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TopologyWidget.o Application/TopologyWidget.cpp

LearningWidget.o: Application/LearningWidget.cpp Application/LearningWidget.h \
		Project/LearningConfigModel.h \
		Project/BaseModel.h \
		ui_LearningWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LearningWidget.o Application/LearningWidget.cpp

HelpWidget.o: Application/HelpWidget.cpp Application/HelpWidget.h \
		ui_HelpWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o HelpWidget.o Application/HelpWidget.cpp

LayerEditWidget.o: Application/LayerEditWidget.cpp Application/LayerEditWidget.h \
		Project/TopologyEditModel.h \
		Project/BaseModel.h \
		ui_LayerEditWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LayerEditWidget.o Application/LayerEditWidget.cpp

NoModelWidget.o: Application/NoModelWidget.cpp Application/NoModelWidget.h \
		ui_NoModelWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NoModelWidget.o Application/NoModelWidget.cpp

TextViewBoxDialog.o: Dialog/TextViewBoxDialog.cpp Dialog/TextViewBoxDialog.h \
		ui_TextViewBoxDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TextViewBoxDialog.o Dialog/TextViewBoxDialog.cpp

NewTestScnDialog.o: Dialog/NewTestScnDialog.cpp Dialog/NewTestScnDialog.h \
		Project/Project.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		Project/TopologyEditModel.h \
		Project/LearningConfigModel.h \
		Project/DatasetTestModel.h \
		Project/GraphTestModel.h \
		ui_NewTestScnDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NewTestScnDialog.o Dialog/NewTestScnDialog.cpp

OutputGraphWidget.o: Application/OutputGraphWidget.cpp Application/OutputGraphWidget.h \
		Project/GraphTestModel.h \
		Project/BaseModel.h \
		ui_OutputGraphWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OutputGraphWidget.o Application/OutputGraphWidget.cpp

DatasetTestWidget.o: Application/DatasetTestWidget.cpp Application/DatasetTestWidget.h \
		Project/DatasetTestModel.h \
		Project/BaseModel.h \
		Project/Project.h \
		Project/DatasetEditModel.h \
		Project/TopologyEditModel.h \
		Project/LearningConfigModel.h \
		Project/GraphTestModel.h \
		ui_DatasetTestWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DatasetTestWidget.o Application/DatasetTestWidget.cpp

BaseModel.o: Project/BaseModel.cpp Project/BaseModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BaseModel.o Project/BaseModel.cpp

DatasetEditModel.o: Project/DatasetEditModel.cpp Project/DatasetEditModel.h \
		Project/BaseModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DatasetEditModel.o Project/DatasetEditModel.cpp

TopologyEditModel.o: Project/TopologyEditModel.cpp Project/TopologyEditModel.h \
		Project/BaseModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TopologyEditModel.o Project/TopologyEditModel.cpp

DatasetTestModel.o: Project/DatasetTestModel.cpp Project/DatasetTestModel.h \
		Project/BaseModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DatasetTestModel.o Project/DatasetTestModel.cpp

GraphTestModel.o: Project/GraphTestModel.cpp Project/GraphTestModel.h \
		Project/BaseModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GraphTestModel.o Project/GraphTestModel.cpp

DatasetEditWidget.o: Application/DatasetEditWidget.cpp Application/DatasetEditWidget.h \
		Project/DatasetEditModel.h \
		Project/BaseModel.h \
		ui_DatasetEditWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DatasetEditWidget.o Application/DatasetEditWidget.cpp

Dataset.o: NeuralNetwork/Dataset.cpp NeuralNetwork/Dataset.h \
		NeuralNetwork/AbstractDataset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Dataset.o NeuralNetwork/Dataset.cpp

DatasetTest.o: Test/DatasetTest.cpp Test/DatasetTest.h \
		NeuralNetwork/Dataset.h \
		NeuralNetwork/AbstractDataset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DatasetTest.o Test/DatasetTest.cpp

BpNetSt.o: NeuralNetwork/BpNetSt.cpp NeuralNetwork/BpNetSt.h \
		NeuralNetwork/AbstractBpNet.h \
		NeuralNetwork/Neuron.h \
		Util/function.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BpNetSt.o NeuralNetwork/BpNetSt.cpp

BpNetStTest.o: Test/BpNetStTest.cpp Test/BpNetStTest.h \
		NeuralNetwork/BpNetSt.h \
		NeuralNetwork/AbstractBpNet.h \
		NeuralNetwork/Neuron.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BpNetStTest.o Test/BpNetStTest.cpp

BpAlgSt.o: NeuralNetwork/BpAlgSt.cpp NeuralNetwork/BpAlgSt.h \
		NeuralNetwork/AbstractLrnAlg.h \
		NeuralNetwork/AbstractBpNet.h \
		NeuralNetwork/Neuron.h \
		NeuralNetwork/AbstractDataset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BpAlgSt.o NeuralNetwork/BpAlgSt.cpp

BpAlgStTest.o: Test/BpAlgStTest.cpp Test/BpAlgStTest.h \
		NeuralNetwork/BpAlgSt.h \
		NeuralNetwork/AbstractLrnAlg.h \
		NeuralNetwork/AbstractBpNet.h \
		NeuralNetwork/Neuron.h \
		NeuralNetwork/AbstractDataset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BpAlgStTest.o Test/BpAlgStTest.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

moc_NeuronTest.o: moc_NeuronTest.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_NeuronTest.o moc_NeuronTest.cpp

moc_AboutDialog.o: moc_AboutDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AboutDialog.o moc_AboutDialog.cpp

moc_Workspace.o: moc_Workspace.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Workspace.o moc_Workspace.cpp

moc_NewProjectDialog.o: moc_NewProjectDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_NewProjectDialog.o moc_NewProjectDialog.cpp

moc_WelcomeWidget.o: moc_WelcomeWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_WelcomeWidget.o moc_WelcomeWidget.cpp

moc_TopologyWidget.o: moc_TopologyWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_TopologyWidget.o moc_TopologyWidget.cpp

moc_LearningWidget.o: moc_LearningWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_LearningWidget.o moc_LearningWidget.cpp

moc_HelpWidget.o: moc_HelpWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_HelpWidget.o moc_HelpWidget.cpp

moc_LayerEditWidget.o: moc_LayerEditWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_LayerEditWidget.o moc_LayerEditWidget.cpp

moc_NoModelWidget.o: moc_NoModelWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_NoModelWidget.o moc_NoModelWidget.cpp

moc_TextViewBoxDialog.o: moc_TextViewBoxDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_TextViewBoxDialog.o moc_TextViewBoxDialog.cpp

moc_NewTestScnDialog.o: moc_NewTestScnDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_NewTestScnDialog.o moc_NewTestScnDialog.cpp

moc_OutputGraphWidget.o: moc_OutputGraphWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_OutputGraphWidget.o moc_OutputGraphWidget.cpp

moc_DatasetTestWidget.o: moc_DatasetTestWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_DatasetTestWidget.o moc_DatasetTestWidget.cpp

moc_DatasetEditModel.o: moc_DatasetEditModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_DatasetEditModel.o moc_DatasetEditModel.cpp

moc_DatasetEditWidget.o: moc_DatasetEditWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_DatasetEditWidget.o moc_DatasetEditWidget.cpp

moc_DatasetTest.o: moc_DatasetTest.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_DatasetTest.o moc_DatasetTest.cpp

moc_BpNetStTest.o: moc_BpNetStTest.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BpNetStTest.o moc_BpNetStTest.cpp

moc_BpAlgSt.o: moc_BpAlgSt.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BpAlgSt.o moc_BpAlgSt.cpp

moc_BpAlgStTest.o: moc_BpAlgStTest.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BpAlgStTest.o moc_BpAlgStTest.cpp

qrc_styles.o: qrc_styles.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_styles.o qrc_styles.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
