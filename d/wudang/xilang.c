// xilang.c ��������
// by Xiang

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ�������ϣ������Ǵ�������һ��¥������¥�ϴ���
���������
LONG );
        set("exits", ([
                "northup" : __DIR__"cangjingge",
                "east"    : __DIR__"sanqingdian",
                "westup"  : __DIR__"caolianfang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
