// /u/beyond/mr/huandong.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",MAG"������"NOR);
         set ("long",@long
������٢��ɽׯ����书�ؼ��ĵط���һ�������������İڷ��Ÿ����鼮��
һλ�����Ĺ����������ǰ�ж��伮��
long);
         set("exits",([
             "north" : __DIR__"ytyuan",
]));
//set("objects",([
//__DIR__"npc/wyy" : 1,
//]));
//set("no_fight",1);
         setup();
         replace_program(ROOM);
}

