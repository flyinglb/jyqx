// /u/beyond/mr/fanting.c
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
             __DIR__"obj/longjing-caiyeji" : 1,
             __DIR__"obj/feicui-yuyuan" : 1,
             __DIR__"obj/meihua-zaoya" : 1,
]));
         set("exits",([
             "west" : __DIR__"cl4-3",
]));
         setup();
	 
}

