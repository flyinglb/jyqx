 inherit ROOM;
void create()
{
        set("short", "�µ�");
        set("long", @LONG
�����������������±ڣ������ǹ�ʯ�Լ��ɶѵĺ��ǡ�Ҳ��֪������
�����޵ģ����˿��˾�ë���Ȼ�����ǿ���취�뿪�ĺ� ����
LONG
        );
        setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me = this_player();
        if( !arg || (arg!="cliff" && arg!="ya" && arg!="up") )
                return notify_fail("��Ҫ��������\n");
        if( me->query("jing") < 100 )
                return notify_fail("���۵��߶��߲����ˣ���ô����\n");
        //if( me->query("jingli") < 100 )
        //        return notify_fail("���۵��߶��߲����ˣ���ô����\n");
        if( me->query("qi") < 100 )
                return notify_fail("����Ѫ�����޷�����ô�ߵ����¡�\n");
        if( me->query("neili") < 100 )
                return notify_fail("�����������޷�֧�������¶���\n");
        tell_object(me,"��î����һ���������±�һ��\nץס��һ��ͻ���ʯ�飬�Ѿ����������� ����\n\n");
        me->move("/d/gumu/zhufeng");
        tell_room(environment(me),me->name()+"���µ��������� ����\n",({me}));
        return 1;
}
