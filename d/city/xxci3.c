#include <room.h>
//inherit ROOM;
inherit CHATTING_ROOM;

void create()
{
	set("short", "��������Ů��Ҳ�");
	set("long", @LONG
������һ��������С�ݣ�ʹ���������Ǹ���֪�ع����ٽ���Ů�ܵ��Ʋֿ⡣
̧ͷһ�ź���(bian)�������м����ں����Ĵ��֣�����������ü��
ע�����������Ⱥ󡣰���ĸ˳��
LONG );
	set("exits", ([ 
		"north" : __DIR__"xxci1",
	]));
	set("item_desc", ([ 
		"bian" : "�����м������֣���һ�����Ա���ע��һ��С�֣�\nŮ�˵����������ߡ�\n",
	]));
	set("no_fight",1);
	set("no_clean_up", 0);

      set("objects", ([ 
//		"/d/npc/wwl" : 1,
//              "/d/npc/roujing":1,
      ]));

	create_door("north","ľ��","south",DOOR_CLOSED); 	
	setup();
}
//
