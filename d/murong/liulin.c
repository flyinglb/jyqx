// /u/beyond/mr/liulin.c
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
             "south" : __DIR__"xiaojing5",
             "east" : __DIR__"liulin1",
]));     
         set("objects",([
             __DIR__"obj/liutiao" : 2,
]));
         setup();
         replace_program(ROOM);
}
