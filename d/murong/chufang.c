// /u/beyond/mr/chufang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"����"NOR);
         set("long",@long
����һ��С����, ��Ȼ����, ���ǹ���ư��, ���ν���, ������ȫ����̨
�϶��������ʹϹ��߲�, �����Ϻ, �������಻��, ��ʮ�ָɾ����롣
long);
         set("objects", ([
             __DIR__"obj/lingbai-xiaren" : 1,
             __DIR__"obj/dongsun-tang" : 1,
             __DIR__"obj/yingtao-huotui" : 1,
]));
         set("valid_startroom", 1);
         set("exits",([
             "south" : __DIR__"xiaoting",
]));
         setup();
	 
}

