// Room: /u/mei/room66.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "�ͱ�");
        set("long", @LONG
��ǰãã�ƺ�������ȥ·������������һ������Կյļ���ƽ̨��
��һ����һ��������ͱڡ�ƽ̨����ʮ���ɷ�Բ�����ǰ����ٿգ���
�Ȳ��ã����ֲ��ܣ���������·һ�������ƽ̨�ϰװ����Ķ��Ǳ�ѩ��
�������֣�����Ұ�ޡ�
LONG
        );

        set("outdoors", "city");
        set("item_desc", ([
        "�ͱ�" : "�ͱ�����һСɽ��(cave)���ƺ�������(zuan)��ȥ��\n", 
        "cave" : "�������ɽ����Ʈ��һ�����磬�ŵ���ֱ����¡�\n",
])); 
        set("outdoors", "room63");
    setup();
}

void init()
{
   add_action("do_jump","jump");
   add_action("do_zuan","zuan");
}
int do_jump(string arg)
    {
        object me,room;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");
          message_vision("$N��ԥ��һ�£�����������������ȥ��\n",me);
        if ((int)me->query_skill("dodge",1) < 300 ) {
          message("vision",me->name()+"��������׹ȥ���������׶༪����!\n",
            environment(me), ({me}) );
        if (!room=find_object(__DIR__"room63"))
                room=load_object(__DIR__"room63");
        me->move(room);
        message("vision","�飡��һ���˵���������\n",room,({me}));
        me->set_temp("die_for","׹��");
        me->die();
        return 1;
        }
        message("vision",
        me->name() + "��ԥ��һ�£�����������������ȥ��\n���ء���һ���죬�ƺ�����"+me->name()+"�Һ���һ��!\n",
        environment(me), ({me}) );
        if (!room=find_object(__DIR__"room63"))
                room=load_object(__DIR__"room63");
        me->move(room);
        message("vision","�飡��һ���˵���������\n",room,({me}));
        return 1;
     }
int do_zuan(string arg)
{

    object me = this_player();
    object room;

    if (arg != "cave" && arg != "out") return notify_fail("����ôû���ϰ��궴ѽ?\n");
    if (me->query("age")>16) return notify_fail("��ôС�Ķ�����ֻ��С��������ý�ȥ!\n");
    if (me->query("str")>18) return notify_fail("�������̫׳�ˣ��겻����ôС�Ķ���\n");
        message("vision", me->name() + "����һ�����˽�ȥ��\n",
                environment(me), ({me}) );
        if (!room=find_object(__DIR__"room67"))
                room=load_object(__DIR__"room67");
        me->move(room);
        message("vision", me->name() + "��ʯ�������˳�����\n",
                room, ({me}) );
    return 1;
}

