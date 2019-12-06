// dating.c
// written by tree

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
你步入大厅，迎面的墙上挂着一块木匾，上面写着“浣花庄”，原来你已经到
了浣花内院，屋子中放着两排红木椅，旁边还站着几个小丫鬟。这里闻不到半点
江湖气息，有的只是安详，宁静。  
LONG);

       set("exits", ([
               "south" : __DIR__"xiaoyuan",
               "east" : __DIR__"huayuan1",
               "west" : __DIR__"huayuan2",
               "north" : __DIR__"shufang",
]));
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);	
}
