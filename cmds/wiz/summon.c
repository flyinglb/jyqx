inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob;
        if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("��... ���������?\n");
/*
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail("���޷��ٻ�"+ob->query("name")+"��\n");
*/
        // moving
        tell_room(environment(ob),"��������һֻ���ְ�"+
                (string)ob->query("name")+"ץ������, Ȼ�᲻����.\n", ob);
        tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ���....\n");
        ob->move(environment(me));
        tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ.\n");
        tell_object(ob,".... ����ʱ������"+(string)me->query("name")+
                "����Ū������.\n");
        tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
                "������ǰ\n",({me,ob}));
        // ok ..
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : summon <ĳ��>

��ָ�������(��)��ĳ���ٻ�������ǰ��
HELP
    );
    return 1;
}

