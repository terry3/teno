#ifndef _LOG_VAR_H_
#define _LOG_VAR_H_

/* set log level */
extern T_LOG_LEVEL gulLogLevel ;

/* log file path*/
extern T_CHAR * gpcLogFilePath ;

/* log file size */
extern T_UINT32  gulLogFileSize;

/* log compress toggle */
extern T_TOGGLE  gtLogToggle   ;

/* log compress program */
extern T_CHAR * gpcLogProgram  ;

/* log file name prefix */
extern T_CHAR * gpcLogFilePrefix;

/* log file name suffix */
extern T_CHAR * gpcLogFileSuffix;



#endif /* _LOG_VAR_H_ */
