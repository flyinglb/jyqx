//olist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i, i1;
        object *list;
        
        if( arg ) {
                arg = resolve_path(me->query("cwd"), arg);
                list = children(arg);
        } else  {
                arg = "objects()";
                list = objects();
        }
        i1 = sizeof(list);
        write("����"+arg+" һ�����֣�"+i1+"����\n");
        for(i=0; i<i1; i++) {
                write(sprintf("Object: %O\t",list[i]));
                if(!environment(list[i])) write("\n");
                else write(sprintf("Object: %O\n",environment(list[i])));
        }
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��olist
ָ���ʽ��olist <file>
ָ��˵�����г�ָ�������ж���
HELP
        );
        return 1;
}
