// Room: /d/henshan/zhurongfeng.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ף�ڷ�");
        set("long", @LONG
 "ף�ڷ�֮��" Ϊ��ɽ���ľ�֮�ס��ڴ˸��Ⱥ�壬�����۵ס���
���潭���ϼ����룬���ͥ������ѩɽ���Ÿ�����ʫ���� "ף�����
�𣬷��εͰ���" �������� "ף�����ɰε�����������������" ��
����ߡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastdown"   : __DIR__"zhurongdian",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

