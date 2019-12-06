// liangong4.c

inherit ROOM;

void create()
{
	set("short", "摘星亭");
	set("long", @LONG
这里是一间别致的亭子，身处此间，看着亭外的景致，闻着那醉人的花香,使
人感到心旷神怡。亭柱上还留有两行诗句“橙林碍日吟风叶，笼竹和烟滴露梢”。
这是当年大诗人杜甫，在安史之战役，一再被俘，九死一生，历尽艰险，终于入
蜀，越天险剑门，到了四川成都，浣花溪畔，得以舒散心怀之后漫呤的诗句。
LONG
	);
        set("exits", ([ 
		"north" : __DIR__"huayuan2",
		"south" : __DIR__"huajing", 
			
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",0);
	setup();
	replace_program(ROOM);
}
