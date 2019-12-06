// Room: /t/wanjiegu/drug_room.c

inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
�ս�������ӣ�����һ��Ũ�ص�ҩζ��������������м���һ
����ҩ�õ�ʯ�ʣ����м�ֻҩ�׷���һ�ߡ���ǽһ�ż��ӣ�������
������ҩƿ�����ٸ�ƿ���϶�д��ҩ������֡�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"right_room",
        ]));
        set("item_desc", ([ /* sizeof() == 1 */
            "����" : "�����ϰ�����ҩƿ��\n",
        ]));
        set("objects", ([
            __DIR__"obj/mortar" : 1,
        ]));
//        set("no_clean_up", 0);

        setup();
}

void reset()
{
        object          *inv;
        object          container, item;
        int             i;

        ::reset();
        container = present("mortar", this_object());
        inv = all_inventory(container);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/x-drug");
                if(random(2)==1 )
                    item->move(container);
        }
}

