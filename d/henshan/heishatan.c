// Room: /d/henshan/heishatan.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ɳ̶");
        set("long", @LONG
��ɳ̶�ֳƺ���̶������ף�ˮɫ�Ժڣ��ٲ�������ˮ�к��ݹ�
��ĭ���࣬���Ŀɲ���ʯ���� "��������" ���־���Ϊ���λ�����٥��
�����ݽ����壬һ��������
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "up"  : __DIR__"shanjian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
    if ((random((int)me->query_skill("dodge")) <= 20) && dir=="up")    
    {
        return notify_fail("��ʹ����һ�ģ����ٲ�����������Զ�͵���������ˤ�ı������ס�\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 35) && dir=="up")    
    {
        return notify_fail("�����һԾ��ȴ���ٲ�������һ�ɶ�Զ�������ǰ׷�������\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 60) && dir=="up")    
    {
        return notify_fail("������������ٲ���ֻ��һ����ˣ��ټӰѾ���\n");
    }

    return ::valid_leave(me, dir);
}

