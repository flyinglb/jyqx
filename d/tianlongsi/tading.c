inherit ROOM;

string look();
void create()
{
        set("short", "����");
        set("long",@LONG
�������������������й�����ط���һ�Ź���(zhuozi)��
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
            "down" : __DIR__"ta1",
        ]));
        set("item_desc",([
            "zhuozi" : (:look():),
        ]));	
        set("no_clean_up", 0);
        setup();
}

string look()
{
	object me=this_player();
	me->set_temp("marks/ask_temp0",1);
	return "����ԭ�����������ӵĵط������տ���Ҳ�����������д��Բ��顣\n";
}
