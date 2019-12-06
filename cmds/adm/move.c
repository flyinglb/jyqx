// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) 
                return notify_fail("ָ���ʽ: mv <ԭ����> <Ŀ�굵��> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
        
        if(file_size(src)<0)
                return notify_fail("������Ч�ļ�����\n");
        
        if( !rename(src, dst) ) {
                log_file("edit/"+geteuid(me), sprintf("mv %s %s %s\n", src, dst, ctime(time())) );
                write("Ok.\n");
        } else
                write("������Ч�ļ�����\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ : mv <ԭ����> <Ŀ�굵��>
 
��ָ�������(��)�޸�ĳ��������Ŀ¼���ơ�
HELP
    );
    return 1;
}
 
