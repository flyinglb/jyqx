// /u/beyond/mr/tingzi.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"ͤ��"NOR);
         set ("long",@long
���Ǹ���С��ͤ�ӣ������ܹ���������ȫ���ľ�ɫ��Զ����һƬӣ��԰��
���м���С���ڱ��̵ĺ������������󣬺�����һ��ľ��ͨ����е�ͤ�ӡ�
��ˮ�صļ�ɽ����һ���ں����Ķ�Ѩ�� 
long);
         set("exits",([
             "westdown" : __DIR__"cl4-1",
]));
         setup();
         replace_program(ROOM);
}



