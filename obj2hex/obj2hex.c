/*
  Converts a Macro-11 object file to various output formats,
  including intel hex (.HEX), straight binary records,
  ASCII format for PDP-11-GUI console load commands (.DUMP),
  loadable absolute binary program images (.BIN) files and
  C header file for use in various MCU projects.

  Currently the program is limited to a single object input file that
  can be output in the selected format. Multiple .psect/.asect ops are
  supported, as well as all local (non-global) relocation directory
  entries. Multiple object files are (not yet) supported.

*/

/*
 Modified by VWarlock 2017

 Copyright (c) 2005-2016 Don North
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 
 o Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 
 o Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
 
 o Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "obj2hex.h"

#include <stdio.h>
#include <stdlib.h>
//#include <stddef.h>
//#include <string.h>
//#include <ctype.h>
//#include <assert.h>



static void print_version(
	FILE *strm)
{
	fprintf(strm, "obj2hex - Convert a Macro-11 object file to .bin/.hex/.h format\n");
	fprintf(strm, "  Version %s\n", VERSIONSTR);
	fprintf(strm, "  Copyright(c) 2005 - 2016 Don North, \n");
	fprintf(strm, "  modified 2017 by VWarlock\n");
}

static void print_help(
	void)
{
	printf("\n");
	print_version(stdout);
	printf("\n");
	printf("Usage:\n");
	printf("  obj2hex [-o <file>] [-l [<file>]] \n");
	printf("          [-h] [-v][-e <option>] [-d <option>]\n");
	printf("          [-ysl <num>] [-yus] \n");
	printf("\n");
	printf("Arguments:\n");
	printf("<inputfile>  MACRO11 source file(s) to assemble\n");
	printf("\n");
	printf("Options:\n");
	printf("\n");
}

/*
Usage print help
*/
void usage(
	char *message) {
	fputs(message, stderr);
	exit(EXIT_FAILURE);
}

/*
Main function
*/
int main(
	int argc,
	char *argv[]) {

	
	if (argc <= 1) {
		print_help();
		exit(EXIT_FAILURE);
	}

}