//LUCAS 2000-6-18
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ����Ө��͸�ı��ݡ��˴��ش�����ѩɽ���壬����
�����ǵ����շ��߷����¡��������ֻ��������������и�
�壬��ຮ�����죬�����뵡��������غ��������չ�����˸��
�ԡ�ɽ��ˮ�䣬����ɾ���Ω�ж���ѩ������Ʈ�㡣��������
������ʧ���������Ծ���
LONG );
        set("exits", ([
                "up" : __DIR__"shanya",
                "down" : __DIR__"fentianya",
        ]));
        set("outdoors", "lingxiao");
        setup();
}

void init()
{
        add_action("do_jump","jump");
}
int do_jump(object me)
{
        me = this_player();
        message_vision("$N���˿��������ư��ƣ�һҧ������һ�գ���������������ȥ\n", me);
        if (me->query_dex()>25)
        {
                me->move(__DIR__"juegu");
        }
        else if (me->query_dex()>20)
        {
                me->move(__DIR__"boot");
                me->unconcious();
        }
        else
        {
                me->move(__DIR__"juegu");
                me->die();
        }
        return 1;
}

