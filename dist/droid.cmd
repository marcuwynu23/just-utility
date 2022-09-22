 @echo off
 set REMOTE_PATH=/storage/emulated/0/
 set LOCAL_PATH=C:\Users\admin\Desktop\Dev
 set WORK_DIR=JavaNIDE
 set CMD_TERM=cmd
 set EDITOR=code
 set ANDROID_IDE=com.duy.compiler.javanide
 set COM_X=265
 set COM_Y=109
 set RUN_X=632
 set RUN_Y=1457

rem droiddroid %REMOTE_PATH% %LOCAL_PATH% %WORK_DIR% %CMD_TERM% %EDITOR% %ANDROID% %COM_X% %COM_Y% %RUN_Y%
droiddroid %REMOTE_PATH% %LOCAL_PATH% %WORK_DIR% %CMD_TERM% %EDITOR% %ANDROID_IDE% %COM_X% %COM_Y% %RUN_X% %RUN_Y%
