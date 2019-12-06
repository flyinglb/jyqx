//cave1.c
inherit ROOM;

int do_say(string arg);
void create()
{
	set("short","岩洞内");
	set("long",@LONG
这里是岩洞内部，洞顶上悬挂着洁白的钟乳石，你仿佛进了威虎山
的岩洞里。
LONG );
	set("exits",([
		"south" : __DIR__"cave",
	]));
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_say", "say");
}
int do_say(string arg)
{
	if( arg=="天王盖地虎" ||  arg=="宝塔镇河妖") 
	{
		write("只听有人说道：是老九么？。\n");
		message("vision", "洞里一堵墙缓缓移了开来，原来是道暗门。\n", this_player());
		set("exits/north", __DIR__"cave2");
		remove_call_out("close");
		call_out("close", 3, this_object());
		return 1;
	}
}
void close(object room)
{
	message("vision","只见暗门乒地关上了。\n", room);
	room->delete("exits/north");
}	




