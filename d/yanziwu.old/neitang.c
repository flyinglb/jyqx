//room: neitang.c
inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
����һ�����µ����ã����ü򵥶����š�����վ�Ÿ�һ���̵�Ů
�ɣ���������Ц��Ц���ƺ��ǽ���������������һ��С���ˡ�
LONG );
        set("exits",([
            "north" : __DIR__"qinyun",
        ]));
        set("objects",([
             __DIR__"npc/abi" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

