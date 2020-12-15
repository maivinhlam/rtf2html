#include "Un_RTF.h"
#include <stdio.h>

extern "C" char* runmain(char* linkInput);
Un_RTF::Un_RTF(char* linkInput) {

	snprintf(m_FolderOutput, 255, "%s", runmain(linkInput));
	
}

Un_RTF::~Un_RTF() {
}
