// query.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if(!arg)
                return notify_fail("你想查看什么函数结果？\n");
if (!ob=present(arg,environment(me)))
  return "错误\n";
q
                write(time()+"\n");
        if( arg == "uptime()" || arg == "uptime" )
                write(uptime()+"\n");
        
        return 1;
}

int help(object me)
{
write(@HELP
测试 time() uptime()
 
HELP
    );
    return 1;
}
