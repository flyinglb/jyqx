inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
������������֮һ�������Ƴ��������Զ����˵��Բ֮ҹ���ڴ���֮
��Ĭ����Ը�����������ʥ��ָ���Խ���������Ը��
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "west" : __DIR__"talin",
        ]));
	set("objects",([
                "/d/wudang/npc/guest" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
