// dating1

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǡ�������̡��µ�һ���ã������õĴ�������Ŀ��ȥ��
�����صģ���������һ������(vote)��\n"
LONG    );
	
        set("exits", ([
            "south" : __DIR__"grass2",
            "northdown" : __DIR__"linjxd5",
        ]));
 
        set("objects",([
            __DIR__"npc/jiaotu" : 2,
        ]));
        set("item_desc", ([
            "vote": "������̣��ĳ���£��󱻲�����\n"
        ]) );
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
