// more.c
// modified by wind

inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
        string file;
        object ob;
        seteuid(geteuid(me));
        if (!arg) return notify_fail("ָ���ʽ : more <����>|<�����> \n");
        file = resolve_path(me->query("cwd"), arg);
        if( file_size(file) < 0 ) {
                ob = present(arg, me);
                if( !ob ) ob = present(arg, environment(me));
                if (file=="here") ob=environment(me);
                if( !ob ) return notify_fail("û�����������\n");
                file = base_name(ob) + ".c";
        }
        if (! (int)SECURITY_D->valid_read(file,me) ) return notify_fail("û�����������\n");
        me->start_more( read_file(file));
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : more <����>|<�����>|<here>
 
��ҳ��ʾ�������ݡ�
 
more ģʽ�µ�ָ��:
q      : �뿪 more.
b      : ��ʾǰһҳ������.
[ENTER]: ��ʾ��һҳ������.
HELP
    );
    return 1;
}
