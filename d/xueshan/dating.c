//      dating.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
���������ڵĴ�������λ�е��ĸ�ɮ�ڸ������ۡ���
�����������ݵ䣬�������档
LONG );
        set("exits",([
                "east" : __DIR__"zoulang1",
                "west" : __DIR__"zoulang2",
                "northeast" : __DIR__"chanshi",
                "southeast" : __DIR__"cangjing",
                "northwest" : __DIR__"cangjingge",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/fawang" :1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

