inherit ROOM;
 
void create()
{
        set("short", "ʥ����");
        set("long",@LONG
�����Ǻ�ľ�µ�ʥ�����ڵء�ʥ���á�������������ޣ�ɷ
��Ư��������һλ����Ů�ӣ�����С�䣬���޲��ɷ��
LONG );
        set("exits", ([
            "east"   : __DIR__"chitang",
        ]));
        set("objects", ([
            __DIR__"npc/ren" : 1,
            __DIR__"npc/shinu":2,
        ]));       
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
