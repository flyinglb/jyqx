//ROOM neishi.c
inherit ROOM;
void create()
{
        set("short", "С������");
        set("long", @LONG
������С�����ҡ���ʰ�þ�ϸ�쳣����һ��ȥ���ͷ��ִ���
����һ��������޵��ˡ�����Ҳ�����̧ͷ���㷢������Ȼ�Ǹ�
���ˣ�����ִ��һö�廨�룡
LONG    );
        set("exits", ([
             "west" : __DIR__"xiaoshe",
        ]));
        set("objects", ([
             __DIR__"npc/dongfang": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
