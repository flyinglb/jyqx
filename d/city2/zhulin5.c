
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ܶ������ܵ����֣�һ̤�������������·�������˼�������
Ω����̤��ƺ֮����ż����΢�������Ҷ�������������������˳�
��Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG );
        set("item_desc",(["north" : (: look_door,"north" :),]));
	set("exits", ([
/* //by risc
		"northeast" : __FILE__,
		"southwest" : __FILE__,
*/
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"zhulin4",
                "north" : __DIR__"xiaoyuan",
	]));
	set("no_clean_up", 0);
create_door("north","����","south",DOOR_CLOSED);
	set("outdoors", "city2");
	setup();
}

