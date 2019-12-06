// Room: /t/wanjiegu/right_room.c

inherit ROOM;

void create()
{
        set("short", "���᷿");
        set("long", @LONG
����һ����ͨ�ķ��䣬�������һЩ�ճ���Ʒ��ǽ���������
һ��ҩ�ݣ����ӹ����ɼ��������պ�Ҫ�����������ҩ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"hall",
            "north" : __DIR__"drug_room",
        ]));

        set("objects", ([
            __DIR__"npc/fuer" : 1,
            __DIR__"obj/cao" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
}

void reset()
{
        object          *inv;
        object          container, item;
        int             i;

        ::reset();
        container = present("cao", this_object());
        inv = all_inventory(container);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/flower");
                if(random(2)==1 )
                    item->move(container);
        }
}

