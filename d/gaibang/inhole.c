// Room: /d/gaibang/inhole.c
// Date: Haa 96/03/22

inherit ROOM;
int do_say(string arg);
void create()
{
	set("short", "�����ڲ�");
	set("long", @LONG
�������ݳ�����㳡���ϻ����ڲ���Ҳ��ؤ�����ܵĵ���ͨ�����ܽ�
�㴦�������ﶪ���˸���������������һ�ɳ�����ζ�����������϶���
һ��ǳ���Ŀ��ľ�ƣ�board����
LONG );
	set("exits", ([
		"out" : "d/city/guangchang"
	]));
	set("item_desc",([
		"board"	: "���˵������������á�\n"
	]));
	set("objects",([
		CLASS_D("gaibang") + "/zuo-qu" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_say", "say");
}
int do_say(string arg)
{
//      if( !arg || arg=="" ) return 0;
        if( arg=="������·�㲻��ѽ" ||  arg=="���������������") 
        {
		write("ֻ����������˵�������Ǳ����ֵܰɣ�������ɡ�\n");
		message("vision", "��������һ��ǽ�������˿�����ԭ���ǵ�Сľ�š�\n", this_player());
		set("exits/down", __DIR__"undertre");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}
void close(object room)
{
	message("vision","ֻ��Сľ��ƹ�ع����ˡ�\n", room);
	room->delete("exits/down");
}	
