// /u/beyond/mr/shiqiao.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"Сʯ��"NOR);
         set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����Զ���ĺ�����
���������������Զ����ֻԧ����һ��Ϸˮ�����ߵ��������ź����ϴ�����
΢��ʱ��ʱ��ҡ���š�
long);
// will add a npc to ask chuan
          set("outdoors","mr");
          set("exits", ([
           "south" : __DIR__"matou",
             "northwest" : __DIR__"hubian2",
]));
          replace_program(ROOM);
          setup();
}

