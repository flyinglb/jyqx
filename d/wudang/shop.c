//Room: /d/huashan/shop.c

inherit ROOM;

void create()
{
	set("short", "С�Ե�");
	set("long", @LONG
������ʯ���ߵ�һ��С�Ե꣬��Щ�򵥵���ʳ��ר��׬��Щ�ο�
��Ǯ��
LONG );
     	set("exits", ([
            "west" : __DIR__"shiliang",
       	]));

        set("objects", ([
            "/d/city/npc/xiaoer2" : 1,
       	]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

