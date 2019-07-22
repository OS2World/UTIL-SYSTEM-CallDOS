# IBM Developer's Workframe/2 Make File Creation run at 12:44:24 on 12/16/92

# Make File Creation run in directory:
#   D:\DATA\C\CALLDOS;

.SUFFIXES:

.SUFFIXES: .c

CALLDOS.EXE:  \
  CALLDOS.OBJ \
  CALLDOS.MAK
   @REM @<<CALLDOS.@0
     /CO /NOI /PM:VIO +
     CALLDOS.OBJ
     CALLDOS.EXE
     
     
     ;
<<
   LINK386.EXE @CALLDOS.@0

{.}.c.obj:
   ICC.EXE /Ss /Ti /C .\$*.c

!include CALLDOS.DEP
