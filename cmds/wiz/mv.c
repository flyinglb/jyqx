// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) 
                return notify_fail("指令格式: mv <原档名> <目标档名> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
        
        if(file_size(src)<0)
                return notify_fail("错误：无效文件名。\n");
        
        if( !rename(src, dst) ) {
                log_file("edit/"+geteuid(me), sprintf("mv %s %s %s\n", src, dst, ctime(time())) );
                write("Ok.\n");
        } else
                write("错误：无效文件名。\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : mv <原档名> <目标档名>
 
此指令可让你(你)修改某个档案或目录名称。
HELP
    );
    return 1;
}
 
