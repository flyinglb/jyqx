// Room: /d/henshan/shuzhuangtai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ױ̨");
        set("long", @LONG
�ؾ�����һ����Ȫ�羵���������Ȫ���ഫΪ�ϳº������ڴ˱���
ʱ���Ա�ˮ��������ױ���ĵط�����ǰʤ�������գ���ʱҹ�䳣����
�⣬���緱�ǵ�㣬������ө�ҷɣ�ɷ��׳�ۡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "north"   : __DIR__"cangjingdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

