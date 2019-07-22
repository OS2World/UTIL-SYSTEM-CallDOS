#define INCL_DOSSESMGR      /* Session Manager values */
#include <os2.h>
#include <stdio.h>
#include <string.h>

STARTDATA   StartData;    /* Start session data structure */
ULONG       SessID;       /* Session ID (returned) */
PID         pid;          /* Process ID (returned) */
UCHAR       PgmTitle[40]; /* Program title string */
UCHAR       PgmName[80];  /* Program pathname string */
UCHAR       ObjBuf[100];  /* Object buffer */
PSZ         Environ = "DOS_HIGH=1\0DPMI_DOS_API=ENABLED\0DPMI_MEMORY_LIMIT=512\0\
KBD_ALTHOME_BYPASS=1\0MOUSE_EXCLUSIVE_ACCESS=1\0";
APIRET      rc;           /* Return code */

void main(void)                         
{

/*  Specify the various session start parameters  */

StartData.Length = sizeof(STARTDATA);
                       /* Length of STARTDATA structure */

StartData.Related = SSF_RELATED_INDEPENDENT;
                       /* Independent session */

StartData.FgBg = SSF_FGBG_FORE;
                       /* Start child session in foreground */

StartData.TraceOpt = SSF_TRACEOPT_NONE;
                       /* Don't trace session */

strcpy(PgmTitle,"DOS Command Prompt");
StartData.PgmTitle = PgmTitle;
                       /* Session Title string */

strcpy(PgmName,"COMMAND.COM");
StartData.PgmName = PgmName;
                       /* Program path-name string */

StartData.PgmInputs = 0;
                       /* Assume no input arguments need */
                       /*   be passed to the program     */

StartData.TermQ = 0;   /* Assume no termination queue */

StartData.Environment = Environ;
                       /* Address of environment string */

StartData.InheritOpt = SSF_INHERTOPT_SHELL;
                       /* Inherit the Shell's environment */

StartData.SessionType = SSF_TYPE_WINDOWEDVDM;
                       /* Start the program in a Windowed DOS session */

StartData.IconFile = 0;
                       /* Assume no specific icon file */
                       /*   is provided                */

StartData.PgmHandle = 0;
                       /* Do not use the installation file */

StartData.PgmControl = SSF_CONTROL_VISIBLE
                         | SSF_CONTROL_MAXIMIZE;
                       /* Start the program as visible */
                       /*   and maximized              */

StartData.InitXPos = 30;
StartData.InitYPos = 40;
StartData.InitXSize = 200;    /* Initial window coordinates */
StartData.InitYSize = 140;    /*   and size                 */

StartData.Reserved = 0;
                       /* Reserved, must be zero */

StartData.ObjectBuffer = ObjBuf;
                       /* Object buffer to hold DosExecPgm */
                       /*   failure causes                 */

StartData.ObjectBuffLen = 100;
                       /* Size of object buffer */

rc = DosStartSession(&StartData, &SessID, &pid);
                      /* On successful return, the variable  */
                      /*   SessID contains the session ID    */
                      /*   of the new session, and the       */
                      /*   variable PID contains the process */
                      /*   ID of the new process             */

if (rc != 0)
  printf("DosStartSession error: return code = %ld", rc);

return;
}

