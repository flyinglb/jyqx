// /u/beyond/mr/liulin2.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"������"NOR);
         set("long",@long
����һƬ���̵������֣�һƬ���̵���ɫ����������ȥ֦Ҷïʢ�����ϼ�
ֻС�����������Ľи���ͣ����������΢������ڶ���
long);
         set("exits",([
             "west" : __DIR__"liulin1",
             "south" : __DIR__"xiaojing7",
]));
         setup();
         replace_program(ROOM);
}
