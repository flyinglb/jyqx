// query.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if(!arg)
                return notify_fail("����鿴ʲô���������\n");
        if( arg == "time()" || arg == "time" )
                write(time()+"\n");
        if( arg == "uptime()" || arg == "uptime" )
                write(uptime()+"\n");
        
        return 1;
}

int help(object me)
{
write(@HELP
���� time() uptime()
 
HELP
    );
    return 1;
}