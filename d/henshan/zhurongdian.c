// Room: /d/henshan/zhurongdian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ף�ڵ�");
        set("long", @LONG
ף�ڵ������ʥ�������ף�ڡ�����ʯ��ǽ�����߸���������
��հ�ѩ��ΡȻ�����ں�ɽ����������ʯ��Ͽ���:  "�����ճ�������
����" ��������"ʥ���ػ�"��鹶���������Ǻ�ɽ���������ڡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"wangritai",
           "northdown"  : __DIR__"wangyuetai",
           "westup"     : __DIR__"zhurongfeng",
        ]));
	set("objects", ([
		__DIR__"npc/moda" : 1,
	]));
//        set("no_clean_up", 0);
        setup();
        "/clone/board/henshan_b"->foo();
        replace_program(ROOM);
}

