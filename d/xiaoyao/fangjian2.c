// fangjian2.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�䲼�ó�����ģ����С���䣬����ʯ�������ϰ��Ÿ�СС��ľͷ
�Ƴɵ�ҡ����ǽ��������һ�������٣����߶��Ѿ����ˡ�
LONG );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));
       set("no_clean_up", 0);
       setup();
}

void init()
{
        add_action("do_shout", "shout");
}

int do_shout(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="֥�鿪��") 
	{
		tell_object(me,"�����˵������ǽ�ڴ��һ������֥�鿪�ţ���\n");
		if (random(100) >50 || ((me->query("family")) && me->query("family")["master_name"]=="��ң��"))
		{
		message("vision", "����һ�������ֻ����һ���¡¡��������������һ�����š�\n", me);
		set("exits/down", __DIR__"shishi4");
		remove_call_out("close");
		call_out("close", 5, this_object());
		}
	else
		{
		message("vision", "�����ﵽ���ص�����������������Ķ����������졣\n", me);
		me->receive_wound("qi",20);
		me->unconcious();
		}
		return 1;
	}
}

void close(object room)
{
	message("vision","һ���¡¡����������ʯ���ֻ����ع����ˡ�\n", room);
	room->delete("exits/down");
}
