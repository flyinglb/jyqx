// /u/beyond/mr/houtang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set("long", @long
�������һ��С������ͷ��һ��Ů���õ���ױ̨��������������֬��
�С�������һ�ų����ĺ�ľ������ֻҪ̧����ȥ��̫��������̲���������
�ס�
long);
         set("exits",([
             "north" : __DIR__"xiaoting",
]));
	setup();
	replace_program(ROOM);
}

