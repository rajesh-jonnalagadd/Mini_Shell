#include "Include/main.h"

//To findout the type command -> internal,external, no command
int check_command_type(char *command)
{
    if(strcmp(command,"\0") == 0)        
    {
        return NO_COMMAND;       
    }

    //list buildincommand
    char *builtins[] ={"exit","cd","pwd","clear","NULL"};
    
    for(int i = 0 ; builtins[i] != NULL ; i++)
    {
        if(strcmp(command,builtins[i]) == 0)
        {
            return BUILDIN;
        }
    } 
    
    //to extract the external commands
    char *external_commands[] = {"man","wc","bash","bunzip2","busybox","bzcat","bzcmp","bzdiff,bzegrep","bzexe,bzfgrep","bzgrep,bzip2","bzip2recover","bzless,bzmore","cat","chacl","chgrp,chmod","chown","chvt","cp","cpio","dash","date","dbus-cleanup-sockets","dbus-daemon","dbus-uuidgen","dd","df","dir","dmesg","dnsdomainname","domainname","dumpkeys","echo","ed","egrep","false","fgconsole","fgrep","findmnt","fuser","fusermount","getfacl","grep","gunzip","gzexe","gzip","hostname","ip","kbd_mode","kill","kmod","less","lessecho","lessfile","lesskey","lesspipe","ln","loadkeys","login","loginctl","lowntfs-3g","ls","lsblk","lsmod","mkdir","mknod","mktemp","more","mount","mountpoint","mt","mt-gnu","mv","nano","nc","nc.openbsd","netcat","netstat","nisdomainname","ntfs-3g","ntfs-3g.probe","ntfs-3g.secaudit","ntfs-3g.usermap","ntfscat","ntfsck","ntfscluster","ntfscmp","ntfsdump_logfile","ntfsfix","ntfsinfo","ntfsls","ntfsmftalloc","ntfsmove","ntfstruncate","ntfswipe","open","openvt","pidof","ping","ping6","plymouth","plymouth-upstart-bridge","ps","rbash","readlink","red","rm","rmdir","rnano","running-in-container","run-parts","sed","setfacl","setfont","setupcon","sh","sh.distrib","sleep","ss","static-sh","stty","su","sync","tailf","tar","tempfile","touch","true","udevadm","ulockmgr_server","umount","uname","uncompress,unicode_start","vdir,vmmouse_detect","which","whiptail","ypdomainname","zcat","zcmp","zdiff","zegrep","zfgrep","zforce","zgrep","zless","zmore","znew"};
    
    size_t external_commands_count = sizeof(external_commands) / sizeof(external_commands[0]);

    
    for(int j = 0 ; j < external_commands_count; j++)
    {
        if(strcmp(command,external_commands[j]) == 0)
        {
            return EXTERNAL;
        }
    }
    
    return NO_COMMAND;

}
