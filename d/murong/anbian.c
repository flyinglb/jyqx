// /u/beyond/mr/anbian.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"����"NOR);
         set("long",@long
��С����������̤����С���İ��ߣ�ֻ������ȫ�ǻ������硣�����ţ�
ʮ��ѧʿ��ʮ��̫�������ɹ������糾��������������Ĳ軨�����������
Χ�����Ѿ����ݻ����У��������ϸ�ı���򣬺����ܹ��߳�ȥ��
long);
         set("outdoors","mr");
/*       set("objects",([
             __DIR__"npc/youcao" : 1,
]));
*/       set("exits",([
             "south" : __DIR__"hc",
             "east" : __DIR__"hc1",
             "west" : __DIR__"hc2",
]));
         setup();
         replace_program(ROOM);
}

