/* Log define struct, macro. */
#ifndef _LOG_DEF_H_
#define _LOG_DEF_H_

#ifdef T_DEBUG_MODE
#define TERRY3_DEBUG
#endif 

/* log level*/
enum T_LOG_LEVEL
{
    INFORMATION = 0,
    WARNING,
    ERR,
    EMERGENCY,
    DEBUG, // DEBUG is the Highest level
};

#endif /* _LOG_DEF_H_ */



