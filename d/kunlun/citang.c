//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
���õ��㰸�Ϲ�������ʮ����λ���谵�Ĺ�����Ҳ�����������ϵ��֡���
�е�������㰸�����š���¯�϶�����һ��ҳ��������ܾ�û��������ɨҲû
�����������ˡ�ֻ���㰸�µ�һ��ľ��(ban)�������ö࣬Ӧ�����������
�����ġ�
LONG );
	set("exits", ([
		"south" : __DIR__"mudi",
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{
	if(arg == "ban")
	{
		message_vision ("$N�ƿ������ϵ�ľ�壬�㰸�³���һ������\n", this_player());
		set("exits/down", __DIR__"dong1");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}
void close(object room)
{
	message("vision","ֻ����ž����һ��������һ�ߵ�ľ�����е������������ض������ˡ�\n", room);
	room->delete("exits/down");
}       
