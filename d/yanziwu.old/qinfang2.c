//ROOM: /d/yanziwu/qinfang2.c

inherit ROOM;
void create()
{
        set("short", "�߷������");
        set("long",@LONG
���������գ�����͸�������������㣬�������Щ���롣һ�Ŵ�
���ϵ���ɫ�ı��췢��������������˯�˰ɣ��㲻�ɵ��뵽��
LONG );
        set("exits", ([
            "down"    : __DIR__"qinfang1",
        ]));
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
