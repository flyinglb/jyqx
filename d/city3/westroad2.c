// Room: westroad2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
һ����ʯ�̳ɵĴ��ͨ���ϱ���·���������ﲻ����ֻ�����治
Զ���Ĺ�������һ����ª��̯�ӣ�̯��һ�ǵ������ڷ���ҡ���ţ���
��д�š��������������ȻҲΧ��һ���ˡ��������������ˣ�������
�񶼴����
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "south" : __DIR__"westroad1",
	    "east"  : __DIR__"shuduroad2",
	    "west"  : __DIR__"westgate",
	    "north" : __DIR__"westroad3",
	]));
	set("objects", ([
	    "/d/taishan/npc/tangzi": 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
