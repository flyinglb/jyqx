// houting.c ����
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_tang(string arg);
int do_niu(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�ĺ������ܷ������ʵʵ��û��һ˿�ķ�϶���ڻ谵
�ĵƹ��£��㷢��ǽ��������һ���� (picture)���ƺ���һ�������
Ф�����������룬�ڷ��ż��߹ײ�(coffin)������ֻ��һ�߹ײĵ�
�װ�û�к��ϣ��ײ��к���տ���Ҳ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"zhengting",
        ]));

        set("item_desc", ([
        "picture": "������һ�������ʿ�ı�Ӱ��������ʲô��ò��������һ��ָ�죬��
�����š�"+MAG"��������"NOR+"���������֡�\n",
        "coffin": "�ú���ʯ�����ɵĹײģ��װ���Ϻ󣬾�û��һ˿�ķ�϶�ˡ�\n"
        ]) );

        set("getbook",1);

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_tang", "tang");
        add_action("do_niu", "niu");
}

int do_tang(string arg)
{
        object me=this_player();
        object ob;

        if( !arg || arg != "coffin" ) {
                return notify_fail("��Ҫ�����Ķ���\n");
        }

        if (query("getbook")>0) {
        message_vision("$N�ɽ��ײ��У��ѹװ���ϣ���ʱһƬ�ڰ����ƺ���쳾�����ˣ�\n",this_player());
        message_vision("������$N�ƺ������װ��ڱ��������֣�ϸϸ����������һͷд��\n", this_player());
        message_vision("��"+HIW"��Ů�ľ�����ѹȫ�棻����һ������������"NOR+"������ʮ�������֣�\n", this_player());
        message_vision("��һͷ������һЩͼ��֮��ķ��š�$N��֪���ԣ������������\n", this_player());
        message_vision("��������˵�������������ϲ�����ϸϸ�ؽ���������ȫ��������\n", this_player());
        message_vision("������������֮�䣬�ƺ������׽�����һ��͹��Ļ���(lock)��\n", this_player());

        if (random(21)>10)
                ob=new("/clone/book/jiuyin2");
        else
                ob=new("/clone/book/jiuyin1");
        ob->move(me);
        add("getbook",-1);
        }
        else {
        message_vision("$N�ɽ��ײ��У��ѹװ���ϣ���ʱһƬ�ڰ����ƺ���쳾������\n",this_player());
        message_vision("������$N�ƺ������װ��ڱ���ǰ�������֣��������ּ��Ѿ�����\n", this_player());
        message_vision("����ε��ˡ�ͻȻ�䣬�ƺ������׽�����һ��͹��Ļ���(lock)��\n", this_player());
        }

        me->set_temp("tmarks/��",1);
        return 1;
}

int do_niu(string arg)
{
        object me=this_player();

        if( !arg || arg != "lock" || me->query_temp("tmarks/��",1)<1) {
                return notify_fail("��ҪŤ��ʲô��\n");
        }

        message_vision("$N���ջ��أ���������Ť������Ȼ��׵�֨֨���죬�ѿ���һ��
\n",this_player());
        message_vision("�󶴣�$N����������ȥ��\n", this_player());
        me->move(__DIR__"mishi2");

        me->set_temp("tmarks/��",0);
        return 1;

}

