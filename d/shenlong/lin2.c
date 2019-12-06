inherit ROOM;
string* npcs = ({
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/fushe",
});
 
void create()
{
        set("short", "��ľ��");
        set("long",@LONG
����һƬ��ľ�֡����˲�Զ,��Ϳ��Կ��ü�ǰ��Ŀյ��ˡ�
LONG);
	set("exits", ([
		"north" : __DIR__"kongdi",
		"south" : __DIR__"lin1",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 1+random(2),
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]) );
	set("outdoors", "shenlong");
	setup();
	replace_program(ROOM);
}

