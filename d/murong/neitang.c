// /u/beyond/mr/neitang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"����"NOR);
         set("long",@long
����������������ã�������ƽʱĽ�ݼҾ���ĵط���Ѿ�ߺ��Ů����
�����ź���Ľ��һ�ҡ�ǽ���Ϲ���һ������ͼ�����������Ϻõ��ľ���ġ�
�����м����һ�Ű������������ϰ���ˮ���Һ���֦��
long);
         set("exits",([
             "north" : __DIR__"houting",
             "east" : __DIR__"shangyuezhai",
             "west" : __DIR__"jingyinge",
]));
         set("objects",([
             __DIR__"obj/mitao" : 2,
             __DIR__"obj/lizhi" : 2,
]));
         setup();
         replace_program(ROOM);
}
