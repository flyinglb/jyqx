//westroad1.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ��ֱͨ������ɽ·������Զ����ȺɽΡ�룬����Ʈ�죬
����ǰ��Զ����Ҫ������ɽ֮���ˡ��������ȥ��ԭ��·��
LONG);
	set("exits",([
	      "west" : __DIR__"westroad2",
 	      "east" : "/d/xingxiu/silk2",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
        
