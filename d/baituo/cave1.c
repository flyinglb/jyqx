//cave1.c
inherit ROOM;

int do_say(string arg);
void create()
{
	set("short","�Ҷ���");
	set("long",@LONG
�������Ҷ��ڲ��������������Ž�׵�����ʯ����·��������ɽ
���Ҷ��
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
	if( arg=="�����ǵػ�" ||  arg=="���������") 
	{
		write("ֻ������˵�������Ͼ�ô����\n");
		message("vision", "����һ��ǽ�������˿�����ԭ���ǵ����š�\n", this_player());
		set("exits/north", __DIR__"cave2");
		remove_call_out("close");
		call_out("close", 3, this_object());
		return 1;
	}
}
void close(object room)
{
	message("vision","ֻ������ƹ�ع����ˡ�\n", room);
	room->delete("exits/north");
}	




