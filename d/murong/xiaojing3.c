// /u/beyond/mr/xiaojing3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIG"С��"NOR);
         set ("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�Զ����һ��С����ӳ����������������̴�С�ݺ�����̴�
��ð����
long);
         set("outdoors","mr");
         set("exits",([
             "northeast" : __DIR__"xiaojing4",
             "west" : __DIR__"xiaoshe",
]));
         setup();
         replace_program(ROOM);
}

