//      mishi.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
����һ��С���䡣ʲô������û�С�
LONG );
        set("exits",([
                "south" : __DIR__"midao",
                "down" : "/d/city/guangchang" ,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
