inherit F_CLEAN_UP;
object find_env(object ob);
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8
int main(object me, string str)
{
        string output = "";
        if(!str) return notify_fail("ָ���ʽ: locate <��Ʒ>\n");
        me->add("sen",-5);
        output = TASK_D->locate_obj(me,str);
        if(output=="")
                return notify_fail("ȷ������"+str+"�Ĵ��λ�á�\n");
        write(output);
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ: locate <��Ʒ>
���ָ����������֪ʹ����Ʒ�Ĵ��λ�á�
HELP
        );
        return 1;
}
object find_env(object ob)
{
        while(ob)
        {
        if(ob->query("coor") ) return ob;
        else ob=environment(ob);        
        }
        return ob;
}
