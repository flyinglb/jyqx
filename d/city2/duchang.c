// Room: /city2/duchang.c

inherit ROOM;
string* npcs = ({
        "/d/city2/npc/wuliuqi",
});

void create()
{
	int i = random(sizeof(npcs));
	set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ�����
�����Ƕġ���С���ķ��䣬ǽ�Ϲ���һ������(paizi)��¥�Ͽ���
����. һ���ţ�ֻ�������������ӣ�ʮ�ֻ��ҡ���һ��Χ��һȺ�ˣ�
����һ��һ������ͷ��ʮ�����ۡ�һ���Ͻл��������Ƕĵ��𾢡�
LONG );

	set("item_desc", ([
		"paizi" : "��¥�Ĺ�������ʹ�ã�Ϊʲôû������?\n",
	]));
	set("exits", ([
                "north" : "/d/city2/daxiao",
                "up" : __DIR__"duchang2",
		"west" : __DIR__"xidan1",
	]));
	set("no_clean_up", 0);
	set("objects", ([
        	CLASS_D("shenlong")+"/shou": 1,
		npcs[i] : 1,
 	]));
	setup();
}

int valid_leave(object me, string dir)
{
   if(dir=="north")
   if(this_player()->query("weiwang")<50) 
   if(objectp(present("wu", environment(me)))&&living(present("wu", environment(me))))
   return notify_fail("\n��������ס��˵�����Բ��𣬷Ǳ�����Ӳ������ɳ��롣\n");	
   return ::valid_leave(me, dir);
}        
