inherit ROOM;
 
void create()
{
        set("short", "������");
        set("long",@LONG
�����Ǻ�ľ�µĵ��Ĵ��á������á���һ���긾�˺�ü����
���ء�
LONG );
        set("exits", ([
            "northdown"   : __DIR__"dating4",
        ]));
        set("objects", ([
            __DIR__"npc/shang" : 1,
        ]));       
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
