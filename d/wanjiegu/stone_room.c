// Room: /t/wanjiegu/stone_room.c

inherit ROOM;
int do_give(object me, object obj, object who);

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ���û��������ɵķ��ӣ�����ޱȡ�������һ��С�ף�����
��һ��С�������ڹ��ߺڰ�������Щ��ʪ��һ��Ů�������ڴ��ϲ�
ͣ�ش��������ϵ��·�������ˮʪ͸�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"backyard",
        ]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/mu" : 1,
        ]));
//        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
