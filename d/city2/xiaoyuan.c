// xiaoyuan.c 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
�������������һ��СԺ������ʮ�����š���Ȼ��Х�������л��죬
ֱ����ľ����������ԺƵ������ء����ɰ��յ���Ȼ��������ؿ�������
�����С�������ޱߵ��������֮�У�һ���˵������Ƕ�ô�Ķ��ݺ���Ʈ��
���Ƕ�ô���������غ�΢��������㾲����վ�����Ʒζ����ݾ�Υ��
�¶��ľ��ף����þò�Ըת����ȥ�����߾��ǡ�����������
LONG );
	set("exits", ([
		"north" : "/d/city2/tingyu",
		"south" : __DIR__"zhulin5",
	]));
	create_door("south", "����", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
	setup();
}

